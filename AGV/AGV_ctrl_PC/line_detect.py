import cv2
import numpy as np
import threading
from socket_video_server import VideoStreamServer
import matplotlib.pyplot as plt
import socket
import struct

class LineDetect:
    def __init__(self):
        self.cam_ui_open=False
        self.cam_thread=threading.Thread(target=self.run,daemon=True)
        self.lower_green = (0, 0, 0)
        self.upper_green = (97, 255, 255)
        self.line_data=[]

    def display_frame(self, frame):
        cv2.imshow('ImageWindow', frame)
        cv2.waitKey(1)

    def conv_hsv_detect(self,frame):
        frame=self.transform_img(frame)
        hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
        mask = cv2.inRange(hsv, self.lower_green, self.upper_green)
        # mask = cv2.cvtColor(mask,cv2.COLOR_HSV2BGR)
        frame = self.detect(frame, mask)
        return frame
    
    def transform_img(self,frame):
        dx=30
        dy=200
        height=240
        width=320
        hrx=width-dx
        hry=dy
        hlx=dx
        hly=dy
        lrx=width-1
        lry=height-1
        llx=0
        lly=height-1
        pts1=np.float32([[hlx,hly],[hrx,hry],[lrx,lry],[llx,lly]])
        width, height = 600, 250
        pts2 = np.float32([[0, 0],[width - 1, 0],[width - 1, height - 1],[0, height - 1]])
        matrix = cv2.getPerspectiveTransform(pts1,pts2)
        imgOutput = cv2.warpPerspective(frame,matrix,(width,height))
        return imgOutput

    def detect(self, frame):
        
        frame=self.transform_img(frame)
        cv2.imshow("host",frame)
        hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
        mask = cv2.inRange(hsv, self.lower_green, self.upper_green)
        mask = cv2.GaussianBlur(mask,(5,5),0)
        mask = cv2.adaptiveThreshold(mask, 255, cv2.ADAPTIVE_THRESH_MEAN_C, cv2.THRESH_BINARY, 301, 0)
        histogram= np.sum(mask[mask.shape[0]//3: , :], axis=0)
        line_base= np.argmax(histogram[:])
        # print("line_base: ",line_base)
        # plt.plot(histogram)
        # plt.show()

        y=250
        box_y=50
        lx=[]
        data=[]
        msk= mask.copy()
        cv2.imshow('mask img', msk)
        cv2.waitKey(1)
        flag=True
        min_contour_area = 2500

        while y>0:
            img = mask[y-box_y:y,max(0,line_base-150):min(line_base+150,600)]
            # cv2.imshow("cut",img)
            contours, hierarchy = cv2.findContours(img, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
            contours=sorted(contours,key=cv2.contourArea,reverse=True)
            cv2.rectangle(frame,(line_base-150,y),(line_base+150,y-box_y),[255,0,255],2)
            try:
                # 컨투어 중 너무 작은 컨투어를 제거
                contour = next(cnt for cnt in contours if cv2.contourArea(cnt) >= min_contour_area)
            except StopIteration:
                flag = False
                break

            M=cv2.moments(contour)
            if M["m00"] != 0:
                cx=int(M["m10"]/M["m00"])
                cy=int(M["m01"]/M["m00"])
                lx.append(max(line_base-150,0)+cx)
                line_base=max(line_base-150,0)+cx
            cv2.rectangle(frame,(line_base-75,y),(line_base+75,y-box_y),[255,255,255],2)
            cv2.circle(frame,(int(line_base),int(y-box_y/2)),3,(0,0,255),-1)
            data.append([(line_base-300),(250-y+box_y/2),line_base])
            y-=box_y

        return flag ,frame , data

    def run(self,img):
        flag , detected_frame, data=self.detect(img)
        # print(data)
        # frame = self.conv_hsv_detect(frame)
        if img is None:
            print("No frame received, ending connection")
        if self.cam_ui_open:
            self.display_frame(detected_frame)
        return flag, data
    
    def follow_forward_line(self,frame):
        self.line_data=[]

        flag,self.line_data = self.run(frame)
        linedetect_flag=False
        linear_x=0.0
        linear_y=0.0
        angular_z=0.0
        
        if self.line_data:
            x = [point[0] for point in self.line_data]
            y = [point[1] for point in self.line_data]
            line_base=[point[2] for point in self.line_data]
            
            theta=[]
            for i in range(1,len(x)):
                theta.append((line_base[i]-line_base[i-1])/50)
            theta.sort()
            
            if(len(theta)>3):
                linedetect_flag=True
                degree=round((theta[1]+theta[2]+theta[3])/3,2)
                # print(degree)
                
                # print(line_base)
                
                #linear_x = 0.03
                
                linear_y=-round(0.01* (line_base[0]-300)/40,2)
                angular_z = round(-degree/3,2)
                if -0.05 <= linear_y <= 0.05:
                    linear_x = 0.03               
                else:
                    linear_x = 0.0
                    angular_z=0.0
                    
            
                
                
                

                # print(linear_x,linear_y,angular_z)

                # send_control_command(client_socket,0.0,0.0,linear_y)
        else:
            linedetect_flag=False
            linear_y=0.0
            linear_x=0.0
            angular_z=0.0
            # send_control_command(client_socket,0.0,0.0,0.0)
        return linedetect_flag, linear_x,linear_y,angular_z
    
    def follow_backward_line(self,frame):
        self.line_data=[]

        flag,self.line_data = self.run(frame)
        linedetect_flag=False
        linear_x=0.0
        linear_y=0.0
        angular_z=0.0
        
        if self.line_data:
            x = [point[0] for point in self.line_data]
            y = [point[1] for point in self.line_data]
            line_base=[point[2] for point in self.line_data]
            
            theta=[]
            for i in range(1,len(x)):
                theta.append((line_base[i]-line_base[i-1])/50)
            theta.sort()
            
            if(len(theta)>3):
                linedetect_flag=True
                degree=round((theta[1]+theta[2]+theta[3])/3,2)
                print(degree)
                
                # print(line_base)
                
                #linear_x = 0.03
                
                linear_y=-round(0.01* (line_base[0]-300)/40,2)
                
                if -0.03 <= linear_y <= 0.03:
                    linear_x = -0.03               
                else:
                    linear_x = 0.0
                    
            
                
                angular_z = round(-degree/3,2)
                

                # print(linear_x,linear_y,angular_z)

                # send_control_command(client_socket,0.0,0.0,linear_y)
        else:
            linedetect_flag=False
            linear_y=0.0
            linear_x=0.0
            angular_z=0.0
            # send_control_command(client_socket,0.0,0.0,0.0)
        return linedetect_flag, linear_x,linear_y,angular_z    


def send_control_command(socket:socket.socket, linear_x, linear_y, angular_z):
    packed_data = struct.pack('fff', linear_x, linear_y, angular_z)
    socket.sendall(packed_data)

if __name__ == "__main__":
    VS=VideoStreamServer(port=8888)
    server = LineDetect()
    server.cam_ui_open=True
    VS.cam_ui=True
    VS.accept_connection()
    # client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    # client_socket.connect(('172.30.1.32', 8999))
    # print("Connected to server")
    while True:
        VS.getframe()
        # flag,data=server.run(VS.frame)
        linedetect_flag, linear_x,linear_y,angular_z = server.follow_forward_line(VS.frame)
        # print(linear_x," ",linear_y," ",angular_z)
        # print(data)
        cv2.imshow("img",VS.frame)
    try:
        server.run()
    except KeyboardInterrupt:
        print("Interrupted by user")

