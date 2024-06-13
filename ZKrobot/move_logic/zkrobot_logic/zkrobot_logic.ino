#include <AccelStepper.h>
#include <HardwareSerial.h>
#include <WiFiClient.h>
#include <WiFi.h>
// wifi && socket server setting
const char* ssid = "Android";
const char* password = "12341234";
const char* server_ip = "192.168.22.8"; // 서버 IP 주소
const uint16_t server_port = 8098; // 서버 포트
WiFiClient client;
// connect with ESP-32_2
HardwareSerial SerialOther(2); // use UART
// Define motor pins for ESP32
#define STEP_PIN_X 15
#define DIR_PIN_X 12
#define STEP_PIN_Y1 27
#define DIR_PIN_Y1 26
#define STEP_PIN_Y2 18
#define DIR_PIN_Y2 19
// Define limit switch pins
//#define LIMIT_SWITCH_PIN1   // Left limit switch
#define LIMIT_SWITCH_PIN2 13  // Right limit switch
#define LIMIT_SWITCH_PIN3 4  // Top limit switch
//#define LIMIT_SWITCH_PIN4 35  // Bottom limit switch
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
void homeMotors();
void moveToCoordinates(int x, int y);
void setup() {
  // Initialize Serial communication
  Serial.begin(115200);
  SerialOther.begin(115200, SERIAL_8N1, 16, 17);
  // pinMode(2, OUTPUT);
  // wifi connect
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // digitalWrite(2, HIGH);
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  // 서버에 연결
  if (client.connect(server_ip, server_port)) {
    Serial.println("Connected to server");
    // digitalWrite(2, HIGH);
  } else {
    Serial.println("Connection to server failed");
  }
  Serial.println("set speed n Accel");
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
  // Serial.println("sethome");
  homeMotors();
}
void loop() {
  if (client.connected()) {
    // 서버에 메시지 전송
    // 서버로부터 메시지 수신
    while (client.available()) {
      String msg = client.readStringUntil('\n');
      msg.trim();
      Serial.println("Received from server: " + msg);
      Serial.println("is connected");
      if (msg.startsWith("in")) {
        int commaIndex = msg.indexOf(',');
        int firstX = msg.substring(2, commaIndex).toInt();
        int firstY = msg.substring(commaIndex+1).toInt();
        client.print("in start");
        processInCommand(firstX, firstY);
      }
      else if (msg.startsWith("out")) {
        int commaIndex = msg.indexOf(',');
        // Serial.println(commaIndex);
        // Serial.println(msg);
        int x = msg.substring(3, commaIndex).toInt();
        int y = msg.substring(commaIndex+1).toInt();
        // Serial.print(x);
        // Serial.println(y);
        client.print("out start");
        processOutCommand(x, y);
      }
    }
  }
}
void homeMotors() {
  // Serial.println("goto home");
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
      }

      if(!yHomed){    
        motorY1.run();
        motorY2.run();
        if (digitalRead(LIMIT_SWITCH_PIN3) == LOW) {  // 위쪽 리미트 스위치
          motorY1.stop();
          motorY2.stop();
          motorY1.setCurrentPosition(0); // 초기 위치를 0으로 설정
          motorY2.setCurrentPosition(0);
        }
      }
    }
  }
  // while (!xHomed || !yHomed) {
  //   while (!xHomed) {
  //     motorX.run();
  //     if (digitalRead(LIMIT_SWITCH_PIN2) == LOW) {  // 오른쪽 리미트 스위치
  //       motorX.stop();
  //       motorX.setCurrentPosition(0); // 초기 위치를 0으로 설정
  //       xHomed = true;
  //     }
  //   }
  //   while (!yHomed) {
  //     motorY1.run();
  //     motorY2.run();
  //     if (digitalRead(LIMIT_SWITCH_PIN3) == LOW) {  // 위쪽 리미트 스위치
  //       motorY1.stop();
  //       motorY2.stop();
  //       motorY1.setCurrentPosition(0); // 초기 위치를 0으로 설정
  //       motorY2.setCurrentPosition(0);
  //       yHomed = true;
  //     }
  //   }
  // }
  Serial.println("Homing complete. Current position set to (0, 0).");
  client.print("ready");
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
void processInCommand(int firstX, int firstY) {
  // Step 1: Move to (2,0)
  moveToCoordinates(2, 2);
  // Step 2: Send "get" command to the other ESP32
  SerialOther.println("get");
  // Step 3: Wait for "finish" command from the other ESP32
  while (SerialOther.available() == 0) {}
  String response = SerialOther.readStringUntil('\n');
  response.trim();
  if (response == "get") {
    // Step 4: Move to the first coordinates
    moveToCoordinates(firstX, firstY);
    // Step 5: Send "give" command to the other ESP32
    SerialOther.println("give");
    // Step 6: Wait for "finish" command from the other ESP32
    while (SerialOther.available() == 0) {}
    response = SerialOther.readStringUntil('\n');
    response.trim();
    if (response == "give") {
      // Step 7: Move to initial position (0,2)
      moveToCoordinates(0, 0);
      // Step 8: Notify PC with "finish" command
      client.print("In");
    }
  }
}
void processOutCommand(int x, int y) {
  // Step 1: Move to the specified coordinates
  moveToCoordinates(x, y);
  // Step 2: Send "get" command to the other ESP32
  SerialOther.println("get");
  client.print("send get");
  // Step 3: Wait for "finish" command from the other ESP32
  while (SerialOther.available() == 0) {}
  String response = SerialOther.readStringUntil('\n');
  response.trim();
  Serial.println(response);
  client.print(response);
  // Serial.println(response);
  if (response == "get") {
    // Step 4: Move to (2,0)
    moveToCoordinates(2, 2);
    // Step 5: Send "give" command to the other ESP32
    SerialOther.println("give");
    // Step 6: Wait for "finish" command from the other ESP32
    while (SerialOther.available() == 0) {}
    response = SerialOther.readStringUntil('\n');
    response.trim();
    if (response == "give") {
      // Step 7: Move to initial position (0,2)
      moveToCoordinates(0, 0);
      // Step 8: Notify PC with "finish" command
      client.print("out");
    }
  }
}
