#include <AccelStepper.h>

#include <WiFi.h>
#include <PubSubClient.h>

// WiFi Parameters
const char* WIFI_SSID = "Android";
const char* WIFI_PASSWORD = "12341234";

// MQTT Server Parameters
const char* MQTT_CLIENT_ID = "arduino-esp32-demo2";
const char* MQTT_BROKER = "driver.cloudmqtt.com";
const char* MQTT_USER = "USER";
const char* MQTT_PASSWORD = "PASSWORD";
const char* MQTT_TOPIC_ESP = "ESP";
const char* MQTT_TOPIC_PC = "PC";


WiFiClient espClient;
PubSubClient client(espClient);

// moter ctrl Parameters


// Define motor pins for ESP32
#define STEP_PIN_X 15
#define DIR_PIN_X 12
#define STEP_PIN_Y1 27
#define DIR_PIN_Y1 26
#define STEP_PIN_Y2 18
#define DIR_PIN_Y2 19
// Define limit switch pins
#define LIMIT_SWITCH_PIN2 13  // Right limit switch
#define LIMIT_SWITCH_PIN3 4  // Top limit switch
// Define steps per unit distance
#define STEPS_PER_UNIT_X 100000  // NEMA 17: 100 pulses/mm => 100000 pulses/m
#define STEPS_PER_UNIT_Y 80000   // NEMA 23: 80 pulses/mm => 80000 pulses/m
// Define maximum travel distance (in units)
#define MAX_TRAVEL_X 1.1  // Maximum travel distance in X direction (meters)
#define MAX_TRAVEL_Y 1.2  // Maximum travel distance in Y direction (meters)
// Number of divisions
#define DIVISIONS_X 60
#define DIVISIONS_Y 120
// Calculate step positions for each division
const long stepPositionsX[DIVISIONS_X + 1] = {
  0,
  (20)*STEPS_PER_UNIT_X * MAX_TRAVEL_X / DIVISIONS_X,
  (40) * STEPS_PER_UNIT_X * MAX_TRAVEL_X / DIVISIONS_X,
  (60) * STEPS_PER_UNIT_X * MAX_TRAVEL_X / DIVISIONS_X
};
const long stepPositionsY[DIVISIONS_Y + 1] = {
  17*STEPS_PER_UNIT_Y * MAX_TRAVEL_Y / DIVISIONS_Y,
  (40+3)*STEPS_PER_UNIT_Y * MAX_TRAVEL_Y / DIVISIONS_Y,
  (80) * STEPS_PER_UNIT_Y * MAX_TRAVEL_Y / DIVISIONS_Y,
  (120) * STEPS_PER_UNIT_Y * MAX_TRAVEL_Y / DIVISIONS_Y
};

// Create instances of AccelStepper for each motor
AccelStepper motorX(AccelStepper::DRIVER, STEP_PIN_X, DIR_PIN_X);
AccelStepper motorY1(AccelStepper::DRIVER, STEP_PIN_Y1, DIR_PIN_Y1);
AccelStepper motorY2(AccelStepper::DRIVER, STEP_PIN_Y2, DIR_PIN_Y2);

// method
void setup_wifi();
void callback(char* topic, byte* message, unsigned int length);
void reconnect();
void publishMessage(String msg);

void homeMotors();
void moveToCoordinates(int x, int y);
// void processInCommand(int firstX, int firstY);
// void processOutCommand(int firstX, int firstY);
void movetohome();


int x=0, y=0;



void setup() {
  // Initialize Serial communication
  Serial.begin(115200);

  // Set max speed and acceleration for each motor
  motorX.setMaxSpeed(5000);
  motorX.setAcceleration(500);
  motorY1.setMaxSpeed(7000);
  motorY1.setAcceleration(2000);
  motorY2.setMaxSpeed(7000);
  motorY2.setAcceleration(2000);
  // Initialize limit switch pins
  pinMode(LIMIT_SWITCH_PIN2, INPUT_PULLUP);
  pinMode(LIMIT_SWITCH_PIN3, INPUT_PULLUP);
  // Move to initial position using limit switches
  Serial.println("sethome");
  homeMotors();


  // setup_wifi();
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
  
  client.setServer(MQTT_BROKER, 18945);
  client.setCallback(callback);

  delay(1000);
  publishMessage("ready");

}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  delay(1000);

  
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

void callback(char* topic, byte* message, unsigned int length) {
 // topic을 String으로 변환
  String topicStr = String(topic);

  if (topicStr.startsWith("PC")) {
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
    
    if (messageStr.startsWith("in")) {
      int commaIndex = messageStr.indexOf(',');
      x = messageStr.substring(2, commaIndex).toInt();
      y = messageStr.substring(commaIndex+1).toInt();
      publishMessage("in start");
      moveToCoordinates(2, 2);
    } 
    else if (messageStr.startsWith("out")) {
      int commaIndex = messageStr.indexOf(',');
      Serial.println(commaIndex);
      Serial.println(msg);
      x = messageStr.substring(3, commaIndex).toInt();
      y = messageStr.substring(commaIndex+1).toInt();
      Serial.print(x);
      Serial.println(y);
      publishMessage("out start");
      moveToCoordinates(x, y);
      // Step 2: Send "get" command to the other ESP32
      publishMessage("out get");
    }
    else if (messageStr.startsWith("out_get")) {
      moveToCoordinates(2, 2);
    }
    else if (messageStr.startsWith("out_give")) {
      moveToCoordinates(0, 0);
    }
    else if (messageStr.startsWith("in_get")) {
      moveToCoordinates(x, y);
    }
    else if (messageStr.startsWith("in_give")) {
      moveToCoordinates(0, 0);
    }
    else if (messageStr.startsWith("home")) {
      movetohome();
    }

    publishMessage(messageStr);

  }
}

void movetohome(){
  publishMessage("move to home");
  motorX.moveTo(stepPositionsX[0]);
  motorY1.moveTo(stepPositionsY[0]);
  motorY2.moveTo(stepPositionsY[0]);
  // Move motors to the target positions
  while (motorX.distanceToGo() != 0 || motorY1.distanceToGo() != 0 || motorY2.distanceToGo() != 0) {
    motorX.run();
    motorY1.run();
    motorY2.run();
  }
  publishMessage("arrived");
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

void publishMessage(String msg) {
  const char* payload = msg.c_str();

  if (!client.publish(MQTT_TOPIC_ESP, payload)) {
    Serial.println("Failed to publish message to MQTT topic!");
  } else {
    Serial.println("Message published to MQTT topic!");
  }
}


void homeMotors() {
  // Move X motor to the right and Y motors upwards until limit switches are triggered
  motorX.moveTo(-100000); // Move right
  motorY1.moveTo(100000); // Move up
  motorY2.moveTo(100000); // Move up
  bool xHomed = false;
  bool yHomed = false;
  
  while (!xHomed || !yHomed) {
    if (!xHomed) {
      motorX.run();
      if (digitalRead(LIMIT_SWITCH_PIN2) == LOW) {  // 오른쪽 리미트 스위치
        motorX.stop();
        motorX.setCurrentPosition(0); // 초기 위치를 0으로 설정
        xHomed=true;
        Serial.println("digitalRead(LIMIT_SWITCH_PIN2) == LOW");
      }
    }
    if(!yHomed){    
      motorY1.run();
      motorY2.run();
      if (digitalRead(LIMIT_SWITCH_PIN3) == LOW) {  // 위쪽 리미트 스위치
        motorY1.stop();
        motorY2.stop();
        motorY1.setCurrentPosition(0); // 초기 위치를 0으로 설정
        motorY2.setCurrentPosition(0);
        yHomed=true;
        Serial.println("digitalRead(LIMIT_SWITCH_PIN3) == LOW");
      }
    }
  }
  Serial.println("Homing complete. Current position set to (0, 0).");
  publishMessage("ready");
}
void moveToCoordinates(int x, int y) {
  // Validate coordinates within the allowed range
  if (x < 0 || x > DIVISIONS_X || y < 0 || y > DIVISIONS_Y) {
    Serial.println("Error: Coordinates out of range.");
    return;
  }
  // Print the coordinates to the serial monitor
  Serial.print("Moving to coordinates: ");
  Serial.print("X = ");
  Serial.print(x);
  Serial.print(", Y = ");
  Serial.println(y);
  // Calculate target positions in steps
  long targetPositionX = stepPositionsX[x]; // X 좌표 설정
  long targetPositionY = -stepPositionsY[y]; // Y 좌표를 반대로 설정
  // Print the target positions to the serial monitor
  Serial.print("Target position (steps): ");
  Serial.print("X = ");
  Serial.print(targetPositionX);
  Serial.print(", Y = ");
  Serial.println(targetPositionY);
  // Set target positions for the motors
  motorX.moveTo(targetPositionX);
  motorY1.moveTo(targetPositionY);
  motorY2.moveTo(targetPositionY);
  // Move motors to the target positions
  while (motorX.distanceToGo() != 0 || motorY1.distanceToGo() != 0 || motorY2.distanceToGo() != 0) {
    motorX.run();
    motorY1.run();
    motorY2.run();
  }
  Serial.println("Reached target position.");
}

