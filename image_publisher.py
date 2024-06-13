# import rclpy
# from rclpy.node import Node
# from sensor_msgs.msg import Image
# import socket
# import pickle


# class ImagePublisher(Node):
#     def __init__(self):
#         super().__init__('import_cam_publisher')
#         self.subscription = self.create_subscription(
#             Image,
#             '/import/cobot_cam/image',
#             self.listener_callback,
#             10)
#         self.subscription  # prevent unused variable warning

#         # Socket setup
#         self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
#         self.sock.connect(('172.30.1.5', 60202))

#     def listener_callback(self, msg):
#         # Serialize the message using pickle
#         serialized_msg = pickle.dumps(msg)
#         # Send the serialized message through the socket
#         self.sock.sendall(serialized_msg)

# def main(args=None):
#     rclpy.init(args=args)
#     joint_state_publisher = ImagePublisher()
#     rclpy.spin(joint_state_publisher)
#     joint_state_publisher.destroy_node()
#     rclpy.shutdown()

# if __name__ == '__main__':
#     main()


import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
import socket
import cv2
import numpy as np
from cv_bridge import CvBridge

class ImageSubscriber(Node):
    def __init__(self):
        super().__init__('import_cobot_image_subscriber')
        self.subscription = self.create_subscription(
            Image,
            'import/cobot_cam/image',
            self.listener_callback,
            10)
        self.subscription  # prevent unused variable warning
        self.bridge = CvBridge()
        self.client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.client_socket.connect(('172.30.1.5', 40201))  # 서버 주소와 포트 설정

    def listener_callback(self, msg):
        # ROS2 Image 메시지를 OpenCV 이미지로 변환
        cv_image = self.bridge.imgmsg_to_cv2(msg, 'bgr8')
        # 이미지를 JPEG 포맷으로 인코딩
        _, buffer = cv2.imencode('.jpg', cv_image)
        # 바이트 스트림을 전송
        print(buffer)
        self.client_socket.sendall(buffer.tobytes())

def main(args=None):
    rclpy.init(args=args)
    image_subscriber = ImageSubscriber()
    rclpy.spin(image_subscriber)
    image_subscriber.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()