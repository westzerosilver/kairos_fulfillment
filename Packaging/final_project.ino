#include <Arduino.h>
#include <WiFi.h>
#include <Wire.h>
#include <ezButton.h>
#include <ESP32Servo.h>
static const int servoPin1 = 25;
static const int servoPin2 = 19;
Servo servo1;
Servo servo2;
int A_IA = 17;
int A_IB = 18;
bool boxButton = false;
bool servoActive = false; // 서보 모터 활성화 상태 플래그
unsigned long servoStartTime = 0; // 서보 모터 시작 시간
ezButton limitSwitch(26);
void setup() {
  pinMode(2, OUTPUT);
  pinMode(A_IA, OUTPUT);
  pinMode(A_IB, OUTPUT);
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  Serial.begin(9600);
  delay(10);
  limitSwitch.setDebounceTime(50); // 스위치 디바운스 타임 설정
}
void loop() {
  limitSwitch.loop(); // 스위치 상태 업데이트
  // 시리얼 명령 처리
  if (Serial.available() > 0) {
    char command = Serial.read();
    if (command == '1') {
      // '1'을 받으면 모터를 계속 전진합니다.
      digitalWrite(A_IA, HIGH);
      digitalWrite(A_IB, LOW);
      servo1.write(0);
      servo2.write(0);
      boxButton = false; // 박스 버튼 상태 초기화
      servoActive = false; // 서보 모터 상태 초기화
    } else if (command == '0') {
      // '0'을 받으면 모터를 정지합니다.
      digitalWrite(A_IA, LOW);
      digitalWrite(A_IB, LOW);
      servo1.write(0);
      servo2.write(0);
      boxButton = false; // 박스 버튼 상태 초기화
      servoActive = false; // 서보 모터 상태 초기화
    }
  }
  // 박스 버튼 동작 처리
  if (boxButton && !servoActive) {
    // 박스 버튼이 눌렸고, 서보 모터가 활성화되지 않은 상태
    digitalWrite(A_IA, LOW);
    digitalWrite(A_IB, LOW);
    servo1.write(90);
    servo2.write(90);
    servoActive = true; // 서보 모터 활성화 상태 설정
    servoStartTime = millis(); // 시작 시간 기록
  }
  // 서보 모터 작동 후 3초 후 처리
  if (servoActive && (millis() - servoStartTime >= 4000)) {
    // 3초 후 다시 전진
    digitalWrite(A_IA, HIGH);
    digitalWrite(A_IB, LOW);
    servo1.write(0);
    servo2.write(0);
    servoActive = false; // 서보 모터 상태 리셋
    boxButton = false; // 박스 버튼 상태 리셋
  }
  // 스위치 동작
  if (limitSwitch.isPressed()) {
    boxButton = true;
    Serial.println("go");
  }
  if (limitSwitch.isReleased()) {
    boxButton = false;
  }
}