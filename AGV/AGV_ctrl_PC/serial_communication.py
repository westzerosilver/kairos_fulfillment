import serial
import time

def main():
    # 시리얼 포트 설정
    ser = serial.Serial('/dev/ttyS1', 115200)  # 포트 이름과 보드레이트 설정
    time.sleep(2)  # 시리얼 포트 초기화 시간 대기
    
    while True:
        message = "Hello from A"
        ser.write(message.encode('utf-8'))
        print(f"Sent: {message}")
        time.sleep(1)

if __name__ == "__main__":
    main()
