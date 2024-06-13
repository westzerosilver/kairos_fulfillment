
import rclpy
from rclpy.node import Node
from mycobot_interfaces.srv import DetectionRQ
from mycobot_interfaces.srv import StateRQ
from sensor_msgs.msg import Image

from vision_msgs.msg import Detection2DArray, Detection2D, BoundingBox2D
from cv_bridge import CvBridge
from ament_index_python.packages import get_package_share_directory
import socket
import struct
from ultralytics import YOLO
import cv2
import numpy as np
import threading
import sys

from pathlib import Path

class YoloDetectionService(Node):
    def __init__(self, yolo_path):
        super().__init__('yolo_detection_service')

        self.srv_yolo = self.create_service(DetectionRQ, 'yolo_detection', self.yolo_detect_callback)
        self.srv_pc = self.create_service(StateRQ, 'start_detection', self.yolo_start_callback)
        # self.publish=self.create_publisher(Image,'import/cobot_cam/image',10)
        # print("service create")


        self._package_path = Path(get_package_share_directory('cobot_yolo_pc'))
        self.bridge = CvBridge()

        # Camera set
        self.cap = cv2.VideoCapture(2)
        self.width =640
        self.height =480
        self.cap.set(cv2.CAP_PROP_FRAME_WIDTH, self.width)
        self.cap.set(cv2.CAP_PROP_FRAME_HEIGHT, self.height)

        self.armforcesX = 306
         
        self.armforcesY = 285
        self.detect_data=[] 
        self.send_data = []


        # YOLO
        self.model = YOLO(yolo_path, verbose=False)

        self.edge_width, self.edge_height = 100, 100
        self.contourarea_threshold=1000
        self.is_detected = False
        self.detected_id = 10


        _,self.frame=self.cap.read()
        imgshow_thread=threading.Thread(target=self.imgShow)
        imgshow_thread.start()

    def connect(self):
        try:
            self.socket.connect((self.server_ip, self.server_port))
            print(f"Connected to server {self.server_ip}:{self.server_port}")
        except Exception as e:
            print(f"Failed to connect to server: {e}")
            return False
        return True
    
    def send_image(self, image):
        try:
            encode_param = [int(cv2.IMWRITE_JPEG_QUALITY), 90]
            result, imgencode = cv2.imencode('.jpg', image, encode_param)
            data = np.array(imgencode)
            string_data = data.tostring()
            self.socket.sendall(struct.pack(">L", len(string_data)) + string_data)
            print("Image sent")
        except Exception as e:
            print(f"Failed to send image: {e}")

    def close(self):
        self.socket.close()
        print("Connection closed")

    def yolo_detect_callback(self, request:DetectionRQ.Request, response:DetectionRQ.Response):
        if request.trigger:
            response.result = self.detect()  # detect 메서드는 Detection2DArray 메시지를 반환하도록 작성되어야 합니다.

        print( "response: ", response)
        return response
    
    
    def yolo_start_callback(self, request:StateRQ.Request, response:StateRQ.Response):

        _ = self.detect()   
        response.endflag = self.is_detected
        response.result = self.detected_id
        
        print(response)
        return response       

        
            
    


    def detect(self):

        self.detect_data.clear()
        self.send_data.clear()
        
        # The detection logic here is simplified for brevity
        detected_id_list= ["box", "clay", "cube", "eclipse", "profile", "soap"]

        ret, frame = self.cap.read()
        if not ret:
            self.get_logger().error('Failed to read frame from camera')
            return

        # 마스크 생성
        mask = np.zeros(frame.shape, dtype=np.uint8)
        mask[120:460, 230:410] = 255
        
        # bitwise_and를 사용하여 마스크 적용
        frame = cv2.bitwise_and(frame, mask)
        frame = cv2.flip(frame,0)
        frame = cv2.flip(frame,1)  

        
        
              
        
        # Run YOLOv8 inference on the frame
        results = self.model(frame)

        
        for box in results[0].boxes:

            center_x, center_y, bb_width, bb_height = map(int,box.xywh[0,:4])
            idx = int(box.cls[0])
            self.detect_data.append([detected_id_list[idx],center_x, center_y, bb_width,bb_height])
            
            
            # 좌상단 좌표 계산
            x1 = max(0, int(center_x - (self.edge_width / 2) - 10))
            y1 = max(0, int(center_y- (self.edge_height / 2) - 10))

            # 우하단 좌표 계산
            x2 = int(min(self.width - 10, x1 + self.edge_width + 20) )
            y2 = int(min(self.height - 10, y1 + self.edge_height + 20) )


            cropped_image = frame[y1:y2, x1:x2]
            print(cropped_image.shape)


            cropped_image = cv2.cvtColor(cropped_image, cv2.COLOR_BGR2GRAY)
            # 가우시안 블러 필터 적용
            blurred = cv2.GaussianBlur(cropped_image, (3, 3), 0)

            # 케니 엣지 검출 적용
            edges = cv2.Canny(blurred, 30, 80)
            
            # Apply morphological operations to close gaps in the contours
            kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (5, 5))
            closed = cv2.morphologyEx(edges, cv2.MORPH_CLOSE, kernel)

            # 윤곽선 찾기
            contours, _ = cv2.findContours(closed, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)


            # 윤곽선 그리기
            for contour in contours:
                epsilon = 0.05 * cv2.arcLength(contour, True)
                approx = cv2.approxPolyDP(contour, epsilon, True)
                area = cv2.contourArea(approx)
                self.detected_id = idx
                if area > self.contourarea_threshold:  # 임계값을 조절하여 작은 노이즈를 제거
                    # 컨투어의 중심 찾기
                    rect = cv2.minAreaRect(contour)
                    box = cv2.boxPoints(rect)
                    box = np.int64(box)
                    # 중심점, 너비, 높이, 각도 추출
                    (_, _), (box_width, box_height), angle = rect
                    bb_width = int(box_width)
                    bb_height = int(box_height)
                    self.rec = results[0]
                    self.is_detected = True
                    
                    self.send_data.append([detected_id_list[idx],center_x, center_y, bb_width,bb_height,angle])
                    
            

         
           
        detections = Detection2DArray()
        detections.detections = [self.create_detection(color, centerx, centery, width, height, angle)
                                for color, centerx, centery, width, height, angle in self.send_data]

        print("detections: ", detections)
        
        return detections




    # detection 
    def create_detection(self, color, centerx, centery, width, height, angle):
        detection = Detection2D()
        detection.id=color
        detection.bbox.center.position.x = float(centerx)
        detection.bbox.center.position.y = float(centery)
        detection.bbox.center.theta = angle
        detection.bbox.size_x = float(width)
        detection.bbox.size_y = float(height)

        

        return detection
    

    def imgShow(self):
        while True:

            _,frame=self.cap.read()

            # 마스크 생성
            mask = np.zeros(frame.shape, dtype=np.uint8)
            mask[120:460, 230:410] = 255
            
            # bitwise_and를 사용하여 마스크 적용
            frame = cv2.bitwise_and(frame, mask)
            frame = cv2.flip(frame,0)
            frame = cv2.flip(frame,1)  

            
            for color,cX,cY,w,h,_ in self.send_data:
                # 중심점에 점 그리기
                cv2.circle(frame, (cX, cY), 5, (0, 0, 255), -1)
                # 중심점 좌표 출력
                transformX=cX-self.armforcesX
                transformY=self.armforcesY-cY
                cv2.putText(frame, f'{color} ({transformX}, {transformY})', (cX - 50, cY - 20), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 255, 255), 2)
                cx = cX - w // 2
                cy = cY - h // 2
                cv2.rectangle(frame, (cx, cy), (cx + w, cy + h), (255, 0, 0), 2)
            
                

            frame=cv2.line(frame,(self.armforcesX,0),(self.armforcesX,self.height),(0,255,0),1)
            frame=cv2.line(frame,(0,self.armforcesY),(self.width,self.armforcesY),(0,255,0),1)
            frame=cv2.circle(frame,(self.armforcesX,self.armforcesY),2,(0,0,255),-1)
            # 결과 출력
            msg=self.bridge.cv2_to_imgmsg(frame,encoding="bgr8")
            # self.publish.publish(msg)
            self.frame=frame
            cv2.imshow('Detection', frame )

            if cv2.waitKey(1) & 0xFF == ord('q'):
                break
             
def main(args=None):
    rclpy.init(args=args)

    yolo_detection_service = YoloDetectionService('/home/yeseo/ws_moveit2/src/cobot_yolo_pc/cobot_yolo_pc/best.pt')
    # yolo_detection_service.detect()
    rclpy.spin(yolo_detection_service)
    yolo_detection_service.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()

