import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
import socket
import cv2
import numpy as np
from cv_bridge import CvBridge

class ImagePublisher(Node):
    def __init__(self):
        super().__init__('import_cobot_image_publisher')
        self.publisher_ = self.create_publisher(Image, 'import/cobot_cam/image', 10)
        self.bridge = CvBridge()
        self.server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.server_socket.bind(('172.30.1.5', 60202))  # 서버 주소와 포트 설정
        self.server_socket.listen(1)
        self.client_socket, add = self.server_socket.accept()
        print("client connect  :",add)
        self.publish_image()

    def publish_image(self):
        while rclpy.ok():
            data = self.client_socket.recv(640 * 480*3)  # 이미지 데이터를 수신
            if not data:
                print("data none")
                continue
            # 바이트 스트림을 numpy 배열로 변환
            nparr = np.frombuffer(data, np.uint8)
            # JPEG 포맷을 OpenCV 이미지로 디코딩
            cv_image = cv2.imdecode(nparr, cv2.IMREAD_COLOR)
            print(nparr)
            # cv2.imshow("img",cv_image)
            # cv2.waitKey(1)
            # OpenCV 이미지를 ROS2 메시지로 변환
            ros_image = self.bridge.cv2_to_imgmsg(cv_image, 'bgr8')
            # ROS2 메시지 게시
            self.publisher_.publish(ros_image)

def main(args=None):
    rclpy.init(args=args)
    image_publisher = ImagePublisher()
    rclpy.spin(image_publisher)
    image_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
