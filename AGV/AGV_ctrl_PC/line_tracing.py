import threading
from functools import partial
import cv2
import socket
import struct
import numpy as np
import time
import logging
from socket_video_server import VideoStreamServer
import aruco_marker_detect
from line_detect import LineDetect
import rclpy.node
import rclpy.subscription 
from mycobot_interfaces.srv import StateRQ
import rclpy
from rclpy.qos import QoSProfile

# Global variable for measurements
measurements = []


def aruco_detect(video_server: VideoStreamServer):
    global measurements
    video_server.accept_connection()
    video_server.cam_ui = True
    camera_matrix, dist_coeffs = aruco_marker_detect.load_camera_parameters('/home/park/Downloads/AGVP3/calibration_params.yaml')
    
    while True:
        video_server.getframe()
        frame, detectdata = aruco_marker_detect.detect_markers(video_server.frame, camera_matrix, dist_coeffs, 0.053)
        
        measurements = [(id[0], distance * 100, rot, marker_pos,frame_data) for id, marker_pos, rot, distance,frame_data in detectdata]
        # print (measurements)
def img_show(frame):
    try:
        cv2.imshow("img", frame)
        # print(measurements)
        cv2.waitKey(1) & 0xFF == ord('q')
    except Exception as e:
        print(f"Exception in img_show: {e}")



client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect(('172.30.1.33', 8047))
print("Connected to server")

video_server = VideoStreamServer(host='', port=8064)

# Wait for the video server to accept a connection


print("Video server connected")

aruco_detector = partial(aruco_detect, video_server)
aruco_detect_thread = threading.Thread(target=aruco_detector, daemon=True)
aruco_detect_thread.start()

while not video_server.is_connected():
    print("Waiting for video server connection...")
    time.sleep(1)

line_detector = LineDetect()
line_detector.cam_ui_open=True


def optimized_line_following(target_marker,target_distance,client_socket:socket.socket, video_server:VideoStreamServer, line_detector:LineDetect):
    global measurements
    running = True
    timeout_frame=50
    while running:
        try:
            frame = video_server.frame
            line_detect_flag, linear_x,linear_y, angular_z = line_detector.follow_forward_line(frame)
            # print(line_detect_flag)
            if linear_y>0.04:
                linear_y=0.04
                linear_x=0.03
                angular_z=0.01
            elif linear_y<-0.04:
                linear_y=-0.04
                linear_x=0.03
                angular_z=0.01
            
            if angular_z>0.1:
                angular_z=0.1
            elif angular_z<-0.1:
                angular_z=-0.1

            if measurements:
                for marker_id, distance, rpy, marker_pos,frame_data in measurements:
                    print(frame_data)
                    print("target_distance = ",distance)
                    if marker_id == target_marker and distance < target_distance:
                        running = False
                        send_control_command(client_socket,0.0,0.0,0.0)
                        send_control_command(client_socket,0.0,0.0,0.0)
                        print("point ",target_marker," arrive")
                        time.sleep(1)
                        break
                if not running:
                    continue

            if line_detect_flag:
                # 선을 성공적으로 감지한 경우
                print(linear_x,linear_y,angular_z)
                
                send_control_command(client_socket, linear_x,linear_y,angular_z)
                timeout_frame=50

            elif measurements:
                # 선 감지 실패, 마커를 확인하여 조정
                for marker_id, distance, rpy, marker_pos,frame_data in measurements:
                    if marker_id == target_marker:
                        print ("d= ",distance,"  p= ",rpy[1],"  x= ",marker_pos[0])
                        if distance > target_distance:
                            linear_x = 0.02
                            angular_z = 0.1 * rpy[1]*0.01
                            linear_y = 0.2*marker_pos[0]
                            send_control_command(client_socket, linear_x, 0.0,angular_z)
                            timeout_frame=50
                            break
                        elif distance < target_distance:
                            running = False
                            send_control_command(client_socket,0.0,0.0,0.0)
                            print("point ",target_marker," arrive")
                            time.sleep(1)
                            break


            else:
                # 선 감지도 실패하고 측정 데이터도 없는 경우
                logging.error("Line detection and measurement error.")
                send_control_command(client_socket,0.01,0.0,0.0)
                timeout_frame-=1
                if timeout_frame==0:
                    running = False

            img_show(frame)
        except Exception as e:
            # 예외 발생 시 로깅
            logging.exception("An error occurred in the line following loop.")
            send_control_command(client_socket,0.0 ,0.0 ,0.0)

    send_control_command(client_socket,0.0,0.0,0.0)
    logging.info("Line following task completed.")
    time.sleep(3)  # sleep duration should be specified if needed

def optimized_line_following_back(target_marker,target_distance,client_socket:socket.socket, video_server:VideoStreamServer, line_detector:LineDetect):
    global measurements
    running = True
    timeout_frame=50
    while running:
        try:
            frame = video_server.frame
            line_detect_flag, linear_x,linear_y, angular_z = line_detector.follow_backward_line(frame)
            # print(line_detect_flag)
            if linear_y>0.04:
                linear_y=0.04
                linear_x=0.03
                angular_z=0.01
            elif linear_y<-0.04:
                linear_y=-0.04
                linear_x=0.03
                angular_z=0.01
            
            
            if angular_z>0.1:
                angular_z=0.1
            elif angular_z<-0.1:
                angular_z=-0.1

            if measurements:
                for marker_id, distance, rpy, marker_pos,frame_data in measurements:
                    print("target_distance = ",distance)
                    if marker_id == target_marker and distance > target_distance:
                        running = False
                        send_control_command(client_socket,0.0,0.0,0.0)
                        send_control_command(client_socket,0.0,0.0,0.0)
                        print("point ",target_marker," arrive")
                        time.sleep(1)
                        break
                if not running:
                    continue

            if line_detect_flag:
                # 선을 성공적으로 감지한 경우
                print(linear_x,linear_y,angular_z)
                
                send_control_command(client_socket, linear_x,linear_y,angular_z)
                timeout_frame=50

            elif measurements:
                # 선 감지 실패, 마커를 확인하여 조정
                for marker_id, distance, rpy, marker_pos,frame_data in measurements:
                    if marker_id == target_marker:
                        print ("d= ",distance,"  p= ",rpy[1],"  x= ",marker_pos[0])
                        if distance < target_distance:
                            linear_x = -0.02
                            angular_z = 0.1 * rpy[1]*0.01
                            linear_y = 0.2*marker_pos[0]
                            send_control_command(client_socket, linear_x, 0.0,angular_z)
                            timeout_frame=50
                            break
                        elif distance > target_distance:
                            running = False
                            send_control_command(client_socket,0.0,0.0,0.0)
                            print("point ",target_marker," arrive")
                            time.sleep(1)
                            break


            else:
                # 선 감지도 실패하고 측정 데이터도 없는 경우
                logging.error("Line detection and measurement error.")
                send_control_command(client_socket,0.0,0.0,0.0)
                timeout_frame-=1
                if timeout_frame==0:
                    running = False

            img_show(frame)
        except Exception as e:
            # 예외 발생 시 로깅
            logging.exception("An error occurred in the line following loop.")
            send_control_command(client_socket,0.0 ,0.0 ,0.0)

    send_control_command(client_socket,0.0,0.0,0.0)
    logging.info("Line following task completed.")
    time.sleep(3)  # sleep duration should be specified if needed

def optimized_line_correct(client_socket:socket.socket, video_server:VideoStreamServer, line_detector:LineDetect):
    running = True
    timeout_frame=50
    while running:
        try:
            frame = video_server.frame
            line_detect_flag, linear_x,linear_y, angular_z = line_detector.follow_forward_line(frame)
            # print(line_detect_flag)
            if linear_y>0.04:
                linear_y=0.04
                linear_x=0.03
                angular_z=0.01
            elif linear_y<-0.04:
                linear_y=-0.04
                linear_x=0.03
                angular_z=0.01
            
            if angular_z>0.1:
                angular_z=0.1
            elif angular_z<-0.1:
                angular_z=-0.1

            if line_detect_flag:
                # 선을 성공적으로 감지한 경우
                print(linear_x,linear_y,angular_z)
                
                send_control_command(client_socket, 0.0,linear_y,angular_z)
                timeout_frame=50

                if linear_x == 0.0 and linear_y < 0.001 and angular_z < 0.01 and linear_y > -0.001 and angular_z > -0.001:
                    # 라인 완전 일치
                    send_control_command(client_socket,0.0,0.0,0.0)
                    timeout_frame-=1
                    if timeout_frame==0:
                        running = False

            img_show(frame)
        except Exception as e:
            # 예외 발생 시 로깅
            logging.exception("An error occurred in the line following loop.")
            send_control_command(client_socket,0.0 ,0.0 ,0.0)

    send_control_command(client_socket,0.0,0.0,0.0)
    logging.info("Line following task completed.")
    time.sleep(3)  # sleep duration should be specified if needed


def send_control_command(socket:socket.socket, linear_x, linear_y, angular_z):
    packed_data = struct.pack('fff', linear_x, linear_y, angular_z)
    socket.sendall(packed_data)

def turn_until_line_detect(client_socket,video_server:VideoStreamServer,line_detector:LineDetect,turn_angle=0.3):
    
    send_control_command(client_socket,0.0,0.0,turn_angle)
    turn_flag=True
    while turn_flag:
        _,data=line_detector.run(video_server.frame)
        if len(data)>4:
            turn_flag=False
    time.sleep(0.6)
    send_control_command(client_socket,0.0,0.0,0.0)
    time.sleep(2)


def turn_until_marker_detect(client_socket,turn_angle=0.3):
    global measurements
    send_control_command(client_socket,0.0,0.0,turn_angle)
    turn_flag=True
    while turn_flag:
        if measurements:
                for marker_id, distance, rpy, marker_pos,frame_data in measurements:
                    marker_x=frame_data[0]
                    if (160-10)<marker_x and (160+10)>marker_x:
                        send_control_command(client_socket,0.0,0.0,0.0)
                        turn_flag=False
    time.sleep(0.6)
    send_control_command(client_socket,0.0,0.0,0.0)
    time.sleep(2)
    

def turn_left_90(client_socket):
    send_control_command(client_socket,0.0,0.0,0.3)
    time.sleep(3.9)
    send_control_command(client_socket,0.0,0.0,0.0)
    time.sleep(1)

def turn_right_90(client_socket):
    send_control_command(client_socket,0.0,0.0,-0.3)
    time.sleep(3.9)
    send_control_command(client_socket,0.0,0.0,0.0)
    time.sleep(1)

def matching_line(client_socket, video_server:VideoStreamServer, line_detector:LineDetect):
    # running =True
    while True:
        frame = video_server.frame
        line_detect_flag, linear_x,linear_y, angular_z = line_detector.follow_forward_line(frame)
        if abs(linear_y)<0.2:
            send_control_command(client_socket,0.0,0.0,0.0)
            break
        send_control_command(client_socket,0.0,linear_y,0.0)
    print("matching finish")
    time.sleep(1)

def linear_to_import(client_socket, video_server, line_detector):
    
    send_control_command(client_socket,0.3,0.0,0.0)

    time.sleep(2)

    optimized_line_following(4,42,client_socket,video_server,line_detector)

    # turn_until_line_detect(client_socket,video_server,line_detector)
    turn_left_90(client_socket)

    optimized_line_following(10,80,client_socket,video_server,line_detector)

    turn_right_90(client_socket)

    optimized_line_following(1,50,client_socket,video_server,line_detector)

    turn_left_90(client_socket)

    optimized_line_following_back(6,80,client_socket,video_server,line_detector)

    #optimized_line_correct(client_socket,video_server,line_detector)

    send_control_command(client_socket,-0.03,0.0,0.0)

    time.sleep(10)


def import_to_linear(client_socket, video_server, line_detector):

    send_control_command(client_socket,0.03,0.0,0.0)

    time.sleep(4)

    optimized_line_following(6,47,client_socket,video_server,line_detector)

    # turn_until_line_detect(client_socket,video_server,line_detector)
    turn_left_90(client_socket)

    optimized_line_following(2,45,client_socket,video_server,line_detector)

    turn_left_90(client_socket)

    optimized_line_following(3,48,client_socket,video_server,line_detector)

    turn_left_90(client_socket)

    optimized_line_following_back(4,80,client_socket,video_server,line_detector)

    #optimized_line_correct(client_socket,video_server,line_detector)

    send_control_command(client_socket,-0.3,0.0,0.0)

    time.sleep(2.5)

def linear_to_export(client_socket, video_server, line_detector):
    send_control_command(client_socket,0.03,0.0,0.0)

    time.sleep(10)

    optimized_line_following(4,42,client_socket,video_server,line_detector)

    # turn_until_line_detect(client_socket,video_server,line_detector)
    turn_left_90(client_socket)

    optimized_line_following(10,115,client_socket,video_server,line_detector)

    turn_left_90(client_socket)

    turn_left_90(client_socket)
    
    #optimized_line_correct(client_socket,video_server,line_detector)

    send_control_command(client_socket,-0.03,0.0,0.0)

    time.sleep(14)

def export_to_linear(client_socket, video_server, line_detector):

    send_control_command(client_socket,0.03,0.0,0.0)

    time.sleep(10)

    optimized_line_following(3,49,client_socket,video_server,line_detector)

    # turn_until_line_detect(client_socket,video_server,line_detector)
    turn_left_90(client_socket)

    optimized_line_following_back(4,100,client_socket,video_server,line_detector)

    #optimized_line_correct(client_socket,video_server,line_detector)

    send_control_command(client_socket,-0.3,0.0,0.0)

    time.sleep(2)

def service_call_back(request:StateRQ.Request, response:StateRQ.Response):   #1:import_to_linear   2:linear_to_import   3:linear_to_export  4:export_to_linear
    print("service called")
    if request.target == 1:
        import_to_linear(client_socket,video_server,line_detector)
        print("import_to_linear End")

        response.endflag = True
        response.result = 1

    elif request.target == 2:
        linear_to_import(client_socket,video_server,line_detector)
        print("linear_to_import End")

        response.endflag = True
        response.result = 2

    elif request.target == 3:
        linear_to_export(client_socket,video_server,line_detector)
        print("linear_to_export End")

        response.endflag = True
        response.result = 3

    elif request.target == 4:
        export_to_linear(client_socket,video_server,line_detector)
        print("export_to_linear End")

        response.endflag = True
        response.result = 4     

    else:
        print("request fail")  # 요청 실패 메시지를 출력합니다.
        response.endflag = False  # 서비스 요청 실패 여부를 설정합니다.
        response.result = -1  # 결과 값을 설정합니다.
        
    packed_data = struct.pack('fff', 0.0, 0.0, 0.0)
    client_socket.sendall(packed_data)

    return response


def main():
    print("start main func")
    rclpy.init()  # ROS 2 노드를 초기화합니다.
    service_node = rclpy.node.Node("AGV_control_service_server")  # ROS 2 노드를 생성합니다.
    service_node.create_service(StateRQ, "AGV_control_service", service_call_back)  # 서비스를 생성합니다.
    rclpy.spin(service_node)  # ROS 2 노드를 실행합니다.

    rclpy.shutdown()  # ROS 2 노드를 종료합니다.

    packed_data = struct.pack('fff', 0.0, 0.0, 0.0)
    client_socket.sendall(packed_data)


    client_socket.close()
    video_server.close()
    aruco_detect_thread.join()
    cv2.destroyAllWindows()


if __name__ == "__main__":
    main()
