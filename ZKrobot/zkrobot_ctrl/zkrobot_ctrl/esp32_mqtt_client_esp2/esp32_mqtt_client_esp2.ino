#include <AccelStepper.h>
#include <ESP32Servo.h>

#include <WiFi.h>
#include <PubSubClient.h>

// WiFi Parameters
const char* WIFI_SSID = "Android";
const char* WIFI_PASSWORD = "12341234";

// MQTT Server Parameters
const char* MQTT_CLIENT_ID = "arduino-esp32-demo";
const char* MQTT_BROKER = "driver.cloudmqtt.com";
const char* MQTT_USER = "USER";
const char* MQTT_PASSWORD = "PASSWORD";
const char* MQTT_TOPIC_ESP = "ESP";
const char* MQTT_TOPIC_PC = "PC2";


WiFiClient espClient;
PubSubClient client(espClient);

// 첫 번째 스테핑 모터 핀 설정 (TB6600 사용)
const int stepPin1 = 22;
const int dirPin1 = 23;

// 두 번째 스테핑 모터 핀 설정 (TB6600 사용)
const int stepPin2 = 32;
const int dirPin2 = 33;

// 서보모터 핀 설정
const int servoPin1 = 12;
const int servoPin2 = 13;

// 리미트 스위치 핀 설정
const int limitSwitchPin1 = 26;  // 첫 번째 모터 전진 리미트 스위치
const int limitSwitchPin2 = 27;  // 첫 번째 모터 후진 리미트 스위치
const int limitSwitchPin3 = 4;   // 두 번째 모터 리미트 스위치
const int limitSwitchPin4 = 5;   // 두 번째 모터 리미트 스위치

Servo servo1;
Servo servo2;

// 스테퍼 모터 객체 생성
AccelStepper stepper1(AccelStepper::DRIVER, stepPin1, dirPin1);
AccelStepper stepper2(AccelStepper::DRIVER, stepPin2, dirPin2);

// method
void setup_wifi();
void reconnect();
void movetohome();
void publishMessage(String msg);

void setup() {
  // 시리얼 모니터 초기화
  Serial.begin(115200);
  pinMode(stepPin1,OUTPUT); 
  pinMode(dirPin1,OUTPUT); 
  pinMode(stepPin2,OUTPUT); 
  pinMode(dirPin2,OUTPUT);
  // 서보 모터 설정
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);

  // 서보 모터 초기화
  servo1.write(0);
  servo2.write(0);

  // 리미트 스위치 핀 초기화
  pinMode(limitSwitchPin1, INPUT_PULLUP);
  pinMode(limitSwitchPin2, INPUT_PULLUP);
  pinMode(limitSwitchPin3, INPUT_PULLUP);
  pinMode(limitSwitchPin4, INPUT_PULLUP);

  // 스테퍼 모터 최대 속도 및 가속도 설정
  stepper1.setMaxSpeed(10000);
  stepper1.setAcceleration(5000);
  stepper2.setMaxSpeed(10000);
  stepper2.setAcceleration(5000);

  // mqtt setting
  setup_wifi();
  client.setServer(MQTT_BROKER, 18945);
  client.setCallback(callback);

  Serial.println("Setup complete. Ready to run.");
  // stepper1.setCurrentPosition(0); // 현재 위치를 0으로 설정
}

void loop() {

  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  delay(1000);

}

void callback(char* topic, byte* message, unsigned int length) {
 // topic을 String으로 변환
  String topicStr = String(topic);

  if (topicStr.startsWith("PC2")) {
    // message를 String으로 변환
    char msg[length + 1]; // 널 종료 문자를 위한 공간 확보
    for (unsigned int i = 0; i < length; i++) {
      msg[i] = (char)message[i];
    }
    msg[length] = '\0'; // 널 종료 문자 추가

    String messageStr = String(msg); // String 객체로 변환

     // 결과 출력
    Serial.print("Message arrived [");
    Serial.print(topicStr);
    Serial.print("] ");
    Serial.println(messageStr);

    int barIndex = messageStr.indexOf('_');
    String commendMsg = messageStr.substring(barIndex + 1);
    Serial.println(commendMsg);
    
    if (commendMsg.startsWith("get")) {
      handleGetCommand();
    } 
    else if (commendMsg.startsWith("give")) {
      handleGiveCommand();
    }
    publishMessage(messageStr);

  }
}

void publishMessage(String msg) {
  const char* payload = msg.c_str();

  if (!client.publish(MQTT_TOPIC_ESP, payload)) {
    Serial.println("Failed to publish message to MQTT topic!");
  } else {
    Serial.println("Message published to MQTT topic!");
  }
}

void handleGetCommand() {
  // 1. 서보모터 90, 120으로 세팅
  servo1.write(90);
  servo2.write(110);
  delay(1000);

  // 2. 첫 번째 모터 첫 번째 리미트 스위치가 눌릴 때까지 전진
  stepper1.setSpeed(1000000);

  while (digitalRead(limitSwitchPin1) == HIGH) {
    stepper1.runSpeed();
    // stepper2.runSpeed(); // 두 번째 모터는 계속 회전
  }
  stepper1.stop(); // 첫 번째 모터 정지

  // 3. 첫 번째 모터 정지 후 1초 대기
  delay(1000);

  // 4. 서보모터 90, 90으로 세팅
  servo1.write(90);
  servo2.write(60);
  delay(1000);

  // 첫 번째 모터 후진 시작
  stepper1.setSpeed(-10000000);

  // 두 번째 모터 시계방향으로 계속 회전
  stepper2.setSpeed(5000); // 속도 설정

  // 첫 번째 모터 후진
  while (digitalRead(limitSwitchPin2) == HIGH) {
    stepper1.runSpeed();
    stepper2.runSpeed(); // 두 번째 모터는 계속 회전
  }
  stepper1.stop(); // 첫 번째 모터 정지
  servo1.write(0);
  servo2.write(0);

  // 두 번째 모터는 세 번째와 네 번째 리미트 스위치가 모두 눌릴 때까지 진행
  while (digitalRead(limitSwitchPin3) == HIGH || digitalRead(limitSwitchPin4) == HIGH) {
    stepper2.runSpeed();
  }
  stepper2.stop(); // 두 번째 모터 정지
}

void handleGiveCommand() {
  // 1. 두 번째 모터 반시계방향으로 진행
  stepper2.setSpeed(-5000);

  unsigned long startTime = millis();
  while (millis() - startTime < 5000) {
    stepper2.runSpeed(); // 두 번째 모터 계속 동작
  }

  // 2. 서보모터 90, 90으로 세팅
  servo1.write(110);
  servo2.write(110);
  delay(1000);

  // 3. 첫 번째 모터 전진
  stepper1.setSpeed(1000000);
  while (digitalRead(limitSwitchPin1) == HIGH) {
    stepper1.runSpeed();
    stepper2.runSpeed(); // 두 번째 모터 계속 동작
  }
  stepper1.stop();
  servo1.write(110);
  servo2.write(90);
  delay(1000);
  // 4. 첫 번째 모터 후진
  stepper1.setSpeed(-1000000);
  while (digitalRead(limitSwitchPin2) == HIGH) {
    stepper1.runSpeed();
    stepper2.runSpeed(); // 두 번째 모터 계속 동작
  }

  // 두 번째 리미트 스위치 상태 확인 후 두 번째 모터 정지
  stepper1.stop();
  stepper2.stop();

  servo1.write(0);
  servo2.write(0);

}



void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect(MQTT_CLIENT_ID, MQTT_USER, MQTT_PASSWORD)) {
      Serial.println("connected");
      client.subscribe(MQTT_TOPIC_ESP);
      client.subscribe(MQTT_TOPIC_PC);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WIFI_SSID);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}