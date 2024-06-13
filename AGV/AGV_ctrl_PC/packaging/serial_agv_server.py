import threading  # 스레드를 사용하기 위한 모듈을 임포트합니다.
from functools import partial  # 함수의 부분적인 적용을 위한 모듈을 임포트합니다.
import cv2  # OpenCV 라이브러리를 임포트합니다.
import socket  # 소켓 통신을 위한 모듈을 임포트합니다.
import struct  # 데이터를 패킹하고 언패킹하기 위한 모듈을 임포트합니다.
import numpy as np  # 배열 연산을 위한 NumPy 라이브러리를 임포트합니다.
import time  # 시간 관련 기능을 제공하는 모듈을 임포트합니다.
import logging  # 로그 기능을 제공하는 모듈을 임포트합니다.
import rclpy.node  # ROS 2의 노드 관련 기능을 제공하는 모듈을 임포트합니다.
import rclpy.subscription  # ROS 2의 구독 관련 기능을 제공하는 모듈을 임포트합니다.
from socket_video_server import VideoStreamServer  # 사용자 정의 비디오 스트리밍 서버 모듈을 임포트합니다.
import aruco_marker_detect  # AR 마커 감지 관련 모듈을 임포트합니다.
from line_detect import LineDetect  # 선 감지 관련 모듈을 임포트합니다.
from pymodbus.client import ModbusSerialClient  # Modbus 통신 클라이언트 모듈을 임포트합니다.
from mycobot_interfaces.srv import StateRQ  # ROS 2의 서비스 메시지를 임포트합니다.
import serial  # 시리얼 통신을 위한 모듈을 임포트합니다.
import rclpy  # ROS 2 Python 클라이언트 라이브러리를 임포트합니다.
from rclpy.qos import QoSProfile
# socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# client = ModbusSerialClient(port='/dev/ttyUSB0', baudrate=9600)  # Modbus 시리얼 클라이언트를 초기화합니다.

measurements = []  # 측정값을 저장할 리스트를 초기화합니다.
# ESP32_RPI = '172.30.1.73'  # ESP32 또는 Raspberry Pi의 IP 주소를 설정합니다.
# PORT = 8090  # 포트 번호를 설정합니다.
# eport_lock = threading.Lock()

SERIAL_PORT = '/dev/ttyUSB1'
BAUD_RATE = 9600

def aruco_detect(video_server: VideoStreamServer):
    global measurements  # 전역 변수 measurements를 함수 내에서 사용할 수 있도록 설정합니다.
    video_server.accept_connection()  # 비디오 스트림 서버에서 연결을 수락합니다.
    video_server.cam_ui = True  # 카메라 사용자 인터페이스를 활성화합니다.
    camera_matrix, dist_coeffs = aruco_marker_detect.load_camera_parameters('/home/sanggyu/ros2_ws/src/control_interfaces/src/calibration_params.yaml')  # 카메라 파라미터를 로드합니다.

    while True:
        video_server.getframe()  # 비디오 프레임을 가져옵니다.
        frame, detectdata = aruco_marker_detect.detect_markers(video_server.frame, camera_matrix, dist_coeffs, 0.049)  # AR 마커를 감지합니다.
        measurements = [(id[0], distance * 100, rot, marker_pos) for id, marker_pos, rot, distance in detectdata]  # 측정값을 업데이트합니다.


def img_show(frame):
    try:
        cv2.imshow("img", frame)  # 이미지를 화면에 출력합니다.
        cv2.waitKey(1) & 0xFF == ord('q')  # 'q' 키가 눌리면 창을 닫습니다.
    except Exception as e:
        print(f"Exception in img_show: {e}")  # 예외가 발생할 경우 메시지를 출력합니다.


def optimized_line_following(target_marker, target_distance, client_socket: socket.socket, video_server: VideoStreamServer, line_detector: LineDetect):
    running = True  # 작업 실행 여부를 나타내는 변수를 초기화합니다.
    timeout_frame = 50  # 타임아웃 프레임을 설정합니다.
    while running:
        try:
            frame = video_server.frame  # 현재 비디오 프레임을 가져옵니다.
            line_detect_flag, linear_x, linear_y, angular_z = line_detector.follow_forward_line(frame)  # 전방 선을 따라가는 함수를 호출합니다.

            if linear_y > 0.08:
                linear_y = 0.08
            elif linear_y < -0.08:
                linear_y = -0.08

            if angular_z > 0.05:
                angular_z = 0.05
            elif angular_z < -0.05:
                angular_z = -0.05

            if measurements:  # 측정값이 존재하는 경우
                for marker_id, distance, rpy, marker_pos in measurements:
                    print("target_distance = ", distance)  # 목표 거리를 출력합니다.
                    if marker_id == target_marker and distance < target_distance:
                        running = False  # 실행을 멈춥니다.
                        send_control_command(client_socket, 0.0, 0.0, 0.0)  # 제어 명령을 보냅니다.
                        print("point ", target_marker, " arrive")  # 목표 지점 도착을 출력합니다.
                        time.sleep(1)  # 1초 대기합니다.
                        break
                if not running:
                    continue

            if line_detect_flag:  # 선을 감지한 경우
                print(linear_x, linear_y, angular_z)  # 제어 값들을 출력합니다.
                send_control_command(client_socket, linear_x, linear_y, angular_z)  # 제어 명령을 보냅니다.
                timeout_frame = 50  # 타임아웃 프레임을 초기화합니다.

            elif measurements:  # 측정값이 존재하는 경우
                for marker_id, distance, rpy, marker_pos in measurements:
                    if marker_id == target_marker:
                        print("d= ", distance, "  p= ", rpy[1], "  x= ", marker_pos[0])  # 거리, 자세, 위치 정보를 출력합니다.
                        if distance > target_distance:
                            linear_x = 0.02
                            angular_z = 0.1 * rpy[1] * 0.01
                            linear_y = 0.2 * marker_pos[0]
                            send_control_command(client_socket, linear_x, 0.0, angular_z)  # 제어 명령을 보냅니다.
                            timeout_frame = 50  # 타임아웃 프레임을 초기화합니다.
                            break
                        elif distance < target_distance:
                            running = False  # 실행을 멈춥니다.
                            send_control_command(client_socket, 0.0, 0.0, 0.0)  # 제어 명령을 보냅니다.
                            print("point ", target_marker, " arrive")  # 목표 지점 도착을 출력합니다.
                            time.sleep(1)  # 1초 대기합니다.
                            break

            else:
                logging.error("Line detection and measurement error.")  # 선 감지 및 측정 오류 로그를 출력합니다.
                timeout_frame -= 1  # 타임아웃 프레임을 감소시킵니다.
                if timeout_frame == 0:
                    running = False  # 실행을 멈춥니다.

            img_show(frame)  # 이미지를 화면에 출력합니다.

        except Exception as e:
            logging.exception("An error occurred in the line following loop.")  # 예외 발생 시 로그를 출력합니다.
            send_control_command(client_socket, 0.0, 0.0, 0.0)  # 제어 명령을 보냅니다.

    send_control_command(client_socket, 0.0, 0.0, 0.0)  # 제어 명령을 보냅니다.
    logging.info("Line following task completed.")  # 로그를 출력합니다.
    time.sleep(3)  # 3초 대기합니다.


def send_control_command(socket: socket.socket, linear_x, linear_y, angular_z):
    packed_data = struct.pack('fff', linear_x, linear_y, angular_z)  # 제어 값을 패킹합니다.
    socket.sendall(packed_data)  # 소

def turn_until_line_detect(client_socket, video_server: VideoStreamServer, line_detector: LineDetect, turn_angle=0.3):
    send_control_command(client_socket, 0.0, 0.0, turn_angle)  # 회전 명령을 보냅니다.
    turn_flag = True  # 회전 상태를 나타내는 변수를 초기화합니다.
    while turn_flag:
        _, data = line_detector.run(video_server.frame)  # 선을 감지합니다.
        if len(data) > 4:
            turn_flag = False  # 회전을 멈춥니다.
    time.sleep(0.6)  # 0.6초 대기합니다.
    send_control_command(client_socket, 0.0, 0.0, 0.0)  # 제어 명령을 보냅니다.
    time.sleep(1)  # 1초 대기합니다.


def turn_left_90(client_socket):
    send_control_command(client_socket, 0.0, 0.0, 0.3)  # 좌회전 명령을 보냅니다.
    time.sleep(3.9)  # 3.9초 대기합니다.
    send_control_command(client_socket, 0.0, 0.0, 0.0)  # 제어 명령을 보냅니다.
    time.sleep(0.5)  # 0.5초 대기합니다.


def turn_right_90(client_socket):
    send_control_command(client_socket, 0.0, 0.0, -0.3)  # 우회전 명령을 보냅니다.
    time.sleep(3.9)  # 3.9초 대기합니다.
    send_control_command(client_socket, 0.0, 0.0, 0.0)  # 제어 명령을 보냅니다.
    time.sleep(0.5)  # 0.5초 대기합니다.


def turn_right_180(client_socket):
    send_control_command(client_socket, 0.0, 0.0, -0.3)  # 180도 우회전 명령을 보냅니다.
    time.sleep(7.5)  # 7.5초 대기합니다.
    send_control_command(client_socket, 0.0, 0.0, 0.0)  # 제어 명령을 보냅니다.
    time.sleep(3)  # 3초 대기합니다.

def turn_back(client_socket):
    send_control_command(client_socket, -0.06, 0.0, 0.0)
    time.sleep(8)
    send_control_command(client_socket, 0.0, 0.0, 0.0)
    time.sleep(0)

def matching_line(client_socket, video_server: VideoStreamServer, line_detector: LineDetect):
    while True:
        frame = video_server.frame  # 현재 비디오 프레임을 가져옵니다.
        line_detect_flag, linear_x, linear_y, angular_z = line_detector.follow_forward_line(frame)  # 전방 선을 따라갑니다.
        if abs(linear_y) < 0.15:
            send_control_command(client_socket, 0.0, 0.0, 0.0)  # 제어 명령을 보냅니다.
            break
        send_control_command(client_socket, 0.0, linear_y, 0.0)  # 제어 명령을 보냅니다.
    print("matching finish")  # 매칭 완료 메시지를 출력합니다.
    time.sleep(1)  # 1초 대기합니다.

def run_seoul(seoul, client_socket, video_server, line_detector):
    if seoul == 'start1':
        optimized_line_following(0, 55, client_socket, video_server, line_detector)
        turn_right_90(client_socket)

        optimized_line_following(1, 70, client_socket, video_server, line_detector)
        turn_left_90(client_socket)

        optimized_line_following(2, 35, client_socket, video_server, line_detector)
        turn_right_90(client_socket)

        optimized_line_following(3, 35, client_socket, video_server, line_detector)
        turn_right_180(client_socket)

        time.sleep(1)

def run_seoul_back(seoul_back, client_socket, video_server, line_detector):
    if seoul_back == 'start2':
        optimized_line_following(11, 172, client_socket, video_server, line_detector)
        turn_left_90(client_socket)

        optimized_line_following(12, 55, client_socket, video_server, line_detector)
        turn_right_90(client_socket)
    
        optimized_line_following(13, 116, client_socket, video_server, line_detector)
        turn_right_90(client_socket)

        turn_back(client_socket)
        
def run_seoul_busan(seoul_busan, client_socket, video_server, line_detector):
    if seoul_busan == 'start3':
        optimized_line_following(4, 147, client_socket, video_server, line_detector)
        turn_right_90(client_socket)

        optimized_line_following(5, 25, client_socket, video_server, line_detector)
        turn_right_180(client_socket)

        time.sleep(1)

def run_busan(busan, client_socket, video_server, line_detector):
    if busan == 'start4':
        optimized_line_following(0, 55, client_socket, video_server, line_detector)
        turn_right_90(client_socket)

        optimized_line_following(1, 70, client_socket, video_server, line_detector)
        turn_left_90(client_socket)

        optimized_line_following(2, 35, client_socket, video_server, line_detector)
        turn_left_90(client_socket)

        optimized_line_following(4, 147, client_socket, video_server, line_detector)
        turn_right_90(client_socket)

        time.sleep(1)

def run_busan_back(busan_back, client_socket, video_server, line_detector):
    if busan_back == 'start5':
        optimized_line_following(6, 50, client_socket, video_server, line_detector)
        turn_right_90(client_socket)

        optimized_line_following(7, 40, client_socket, video_server, line_detector)
        turn_left_90(client_socket)

        optimized_line_following(8, 55, client_socket, video_server, line_detector)
        turn_left_90(client_socket)

        optimized_line_following(9, 115, client_socket, video_server, line_detector)
        turn_left_90(client_socket)
        
        turn_back(client_socket)      

def run_busan_seoul(busan_seoul, client_socket, video_server, line_detector):
    if busan_seoul == 'start6':
        optimized_line_following(6, 50, client_socket, video_server, line_detector)
        turn_left_90(client_socket)

        optimized_line_following(3, 30, client_socket, video_server, line_detector)
        turn_right_180(client_socket)
        
        time.sleep(1)
# def run_comeback(comeback, client_socket, video_server, line_detector):
#     if comeback == 'start3':
#         optimized_line_following(6, 50, client_socket, video_server, line_detector)
#         turn_right_90(client_socket)

#         optimized_line_following(7, 60, client_socket, video_server, line_detector)
#         turn_left_90(client_socket)

#         optimized_line_following(8, 50, client_socket, video_server, line_detector)
#         turn_left_90(client_socket)

#         optimized_line_following(9, 120, client_socket, video_server, line_detector)
#         turn_left_90(client_socket)
        
#         optimized_line_following(0, 180, client_socket, video_server, line_detector)
#         turn_back(client_socket) 

def service_call_back(request:StateRQ.Request, response:StateRQ.Response):
    if request.target == 1: # esp, PLC 통신
        task(request.target)  # 요청에 따라 작업을 수행합니다.
        print("task End")  # 작업 완료 메시지를 출력합니다.

        response.endflag = True  # 서비스 요청 성공 여부를 설정합니다.
        response.result = 1  # 결과 값을 설정합니다.

    elif request.target == 2: # AGV 서울
        agv_seoul(request.target)

        response.endflag = True
        response.result == 2

    elif request.target == 3: # AGV 서울 갔다가 백
        seoul_back(request.target)

        response.endflag = True  # 서비스 요청 성공 여부를 설정합니다.
        response.result = 3    

    elif request.target == 4: # AGV 서울 갔다가 부산
        seoul_busan(request.target)

        response.endflag = True  # 서비스 요청 성공 여부를 설정합니다.
        response.result = 4

    elif request.target == 5: # AGV 부산
        agv_busan(request.target)

        response.endflag = True  # 서비스 요청 성공 여부를 설정합니다.
        response.result = 5 

    elif request.target == 6: # AGV 부산 갔다가 백
        busan_back(request.target)

        response.endflag = True  # 서비스 요청 성공 여부를 설정합니다.
        response.result = 6 

    elif request.target == 7: # AGV 부산 갔다가 서울
        busan_seoul(request.target)

        response.endflag = True  # 서비스 요청 성공 여부를 설정합니다.
        response.result = 7   

    else:
        print("request fail")  # 요청 실패 메시지를 출력합니다.
        response.endflag = False  # 서비스 요청 실패 여부를 설정합니다.
        response.result = -1  # 결과 값을 설정합니다.

    return response  # 응답을 반환합니다.


def task(target):
    print(target)  # 사용자 입력을 출력합니다.
    try:
        with serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1) as ser:
            print(f"Connected to {SERIAL_PORT} at {BAUD_RATE} baud")
            # s.connect((ESP32_RPI, PORT))  # ESP32 또는 Raspberry Pi에 연결합니다.
            # print(f"Connected to {ESP32_RPI}:{PORT}")  # 연결 메시지를 출력합니다.
            # client = ModbusSerialClient(port='/dev/ttyUSB0', baudrate=9600)        # 
            with ModbusSerialClient(port='/dev/ttyUSB0', baudrate=9600) as client:
                # s.connect((ESP32_RPI, PORT))  # ESP32 또는 Raspberry Pi에 연결합니다.
                # print(f"Connected to {ESP32_RPI}:{PORT}")  # 연결 메시지를 출력합니다.
                if target:
                    # s.sendall('1'.encode())  # 데이터 '1'을 전송합니다.
                    ser.write('1\n'.encode())
                    print("ESP32로 '1'을 보냈습니다.")
                # ESP32로 데이터 전송 메시지를 출력합니다.

                    result_word = client.write_register(0, 0x0001, 1)  # Modbus 클라이언트를 사용하여 레지스터에 데이터를 쓰고 결과를 받아옵니다.
                    print("PLC 작업 결과:", result_word)  # PLC 작업 결과를 출력합니다.

                while True:
                    result1 = client.read_coils(16,8,1)
                    print(result1.bits[0])

                    if result1.bits[0]:
                        # s.sendall('0'.encode())
                        ser.write('0\n'.encode())
                        print("ESP32로 '0'을 보냈습니다.")
                        client.close()
                        break

                    time.sleep(1) 
    except serial.SerialException as e:
        print(f"Error: {e}")

            # client.close()           

def agv_seoul(target):
    print(target)
    run_seoul('start1', client_socket, video_server, line_detector)

def seoul_back(target):
    print(target)
    run_seoul_back('start2', client_socket, video_server, line_detector)   

def seoul_busan(target):
    print(target)
    run_seoul_busan('start3', client_socket, video_server, line_detector)

def agv_busan(target):
    print(target)
    run_busan('start4', client_socket, video_server, line_detector)

def busan_back(target):
    print(target)
    run_busan_back('start5', client_socket, video_server, line_detector)

def busan_seoul(target):
    print(target)
    run_busan_seoul('start6', client_socket, video_server, line_detector)

client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)  # TCP 소켓을 생성합니다.
client_socket.connect(('172.30.1.1', 8999))  # 서버에 연결합니다.
print("Connected to server")  # 서버 연결 메시지를 출력합니다.

video_server = VideoStreamServer(host='', port=8485)  # 비디오 스트리밍 서버를 초기화합니다.
print("Video server connected")  # 비디오 서버 연결 메시지를 출력합니다.

# ArUco 마커 감지 스레드를 시작합니다.
aruco_detector = partial(aruco_detect, video_server)
aruco_detect_thread = threading.Thread(target=aruco_detector, daemon=True)
aruco_detect_thread.start()

while not video_server.is_connected():
    print("Waiting for video server connection...")  # 비디오 서버 연결 대기 메시지를 출력합니다.
    time.sleep(1)  # 1초 대기합니다.

line_detector = LineDetect()  # 선 감지 객체를 초기화합니다.
line_detector.cam_ui_open = True  # 카메라 사용자 인터페이스를 활성화합니다.


def main():
    rclpy.init()  # ROS 2 노드를 초기화합니다.
    service_node = rclpy.node.Node("AGV_control_service")  # ROS 2 노드를 생성합니다.
    qos_profile = QoSProfile(
        history=rclpy.qos.QoSHistoryPolicy.KEEP_LAST,
        depth=10  # 충분한 히스토리 깊이 설정
    )
    service_node.create_service(StateRQ, "AGV_control_service", service_call_back)  # 서비스를 생성합니다.
    rclpy.spin(service_node)  # ROS 2 노드를 실행합니다.

    rclpy.shutdown()  # ROS 2 노드를 종료합니다.

    # client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)  # TCP 소켓을 생성합니다.
    # client_socket.connect(('172.30.1.1', 8999))  # 서버에 연결합니다.
    # print("Connected to server")  # 서버 연결 메시지를 출력합니다.

    # video_server = VideoStreamServer(host='', port=8485)  # 비디오 스트리밍 서버를 초기화합니다.
    # print("Video server connected")  # 비디오 서버 연결 메시지를 출력합니다.

    # # ArUco 마커 감지 스레드를 시작합니다.
    # aruco_detector = partial(aruco_detect, video_server)
    # aruco_detect_thread = threading.Thread(target=aruco_detector, daemon=True)
    # aruco_detect_thread.start()

    # while not video_server.is_connected():
    #     print("Waiting for video server connection...")  # 비디오 서버 연결 대기 메시지를 출력합니다.
    #     time.sleep(1)  # 1초 대기합니다.

    # line_detector = LineDetect()  # 선 감지 객체를 초기화합니다.
    # line_detector.cam_ui_open = True  # 카메라 사용자 인터페이스를 활성화합니다.

    packed_data = struct.pack('fff', 0.0, 0.0, 0.0) # 초기 제어 데이터를 패킹합니다.
    client_socket.sendall(packed_data)  # 초기 제어 데이터를 서버로 전송합니다.
    client_socket.close()  # 클라이언트 소켓을 닫습니다.
    video_server.close()  # 비디오 서버를 닫습니다.
    aruco_detect_thread.join()  # ArUco 마커 감지 스레드가 종료될 때까지 기다립니다.
    cv2.destroyAllWindows()  # 모든 OpenCV 창을 닫습니다.


if __name__ == "__main__":
    main()  # 메인 함수를 실행합니다.
