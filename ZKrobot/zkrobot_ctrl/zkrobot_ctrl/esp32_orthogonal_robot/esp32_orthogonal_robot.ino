#include <WiFi.h>

// ESP32-1의 IP 주소 및 포트 번호
const char* remoteESP32IP = "172.30.1.26";
const int remotePort = 8090;

// Wi-Fi 네트워크 이름 및 비밀번호
const char* ssid = "ConnectValue_A602_2G";
const char* password = "PASSWORD";

WiFiClient client;
WiFiServer wifiServer(8090);
WiFiClient serverClient;

void setup() {
  Serial.begin(115200);
  delay(10);

  // Wi-Fi 연결
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  // 서버 시작
  wifiServer.begin();
  Serial.println("Server started.");

  // ESP32-1에 연결 시도
  if (client.connect(remoteESP32IP, remotePort)) {

    Serial.println("Connected to ESP32-1");
  } else {
    Serial.println("Connection to ESP32-1 failed");
  }
}

void loop() {
  // 클라이언트로서 ESP32-1에 연결된 상태 확인
  if (!client.connected()) {
    if (client.connect(remoteESP32IP, remotePort)) {
      Serial.println("Reconnected to ESP32-1");
    } else {
      Serial.println("Reconnection to ESP32-1 failed");
      delay(500);
      return;
    }
  }

  // 서버로서 PC로부터 명령을 수신
  serverClient = wifiServer.available();
  if (serverClient) {
    while (serverClient.connected()) {
      if (serverClient.available() > 0) {
        String pcMessage = serverClient.readStringUntil('\n');
        pcMessage.trim(); // 양쪽 끝 공백 제거

        if (pcMessage == "0") {
          // "0"을 받으면 "get" 명령 전송
          client.println("get");
          Serial.println("Sent to ESP32-1: get");
        } else if (pcMessage == "1") {
          // "1"을 받으면 "give" 명령 전송
          client.println("give");
          Serial.println("Sent to ESP32-1: give");
        } else if (pcMessage == "exit") {
          // "exit" 명령어 입력 시 루프 종료
          client.stop();
          while (true) {
            delay(100);
          }
        } else {
          Serial.println("Invalid command from PC");
        }
      }

      // ESP32-1로부터 finish 메시지를 수신할 때까지 대기
      if (client.available() > 0) {
        String response = client.readStringUntil('\n');
        response.trim(); // 양쪽 끝 공백 제거
        if (response == "finish") {
          Serial.println("Received from ESP32-1: finish");
          // PC에 finish 메시지 전송
          serverClient.println("finish");
          Serial.println("Sent to PC: finish");
        }
      }
    }
    serverClient.stop();  // 클라이언트 연결 종료
    Serial.println("Client disconnected.");
  }
}
