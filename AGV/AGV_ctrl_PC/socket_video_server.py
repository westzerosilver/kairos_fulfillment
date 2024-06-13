import socket
import cv2
import numpy as np

class VideoStreamServer:
    def __init__(self, host='', port=8080):
        self.host = host
        self.port = port
        self.socket = None
        self.conn = None
        self.addr = None
        self.frame = np.array([0]) 
        self.cam_ui =False
        self.connected = False

        self.setup_server()

    def is_connected(self):
        return self.connected

    def setup_server(self):
        self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.socket.bind((self.host, self.port))
        self.socket.listen(10)  # Listen for connections from up to 10 clients
        print("Socket created and now listening")

    def accept_connection(self):
        self.conn, self.addr = self.socket.accept()
        self.connected = True
        print(f"Connection established with {self.addr}")

    def recvall(self, count):
        buf = b''
        while count:
            newbuf = self.conn.recv(count)
            if not newbuf:
                return None
            buf += newbuf
            count -= len(newbuf)
        return buf

    def receive_frame(self):
        length = self.recvall(16)
        if length is None:
            return None
        length = int(length)
        stringData = self.recvall(length)
        data = np.frombuffer(stringData, dtype='uint8')
        frame = cv2.imdecode(data, cv2.IMREAD_COLOR)
        return frame

    def display_frame(self, frame):
        cv2.imshow('ImageWindow', frame)
        cv2.waitKey(1)

    def run(self):
        self.accept_connection()
        while True:
            frame = self.receive_frame()
            if frame is None:
                print("No frame received, ending connection")
                break
            self.frame=frame
            if self.cam_ui:
                self.display_frame(frame)

    def getframe(self):
        frame = self.receive_frame()
        if frame is None:
            print("No frame received, ending connection")

        self.frame=frame
        return frame


    def close(self):
        self.conn.close()
        self.socket.close()
        cv2.destroyAllWindows()
        print("Connections and window closed")

# Usage
if __name__ == "__main__":
    server = VideoStreamServer()
    try:
        server.run()
        server.display_frame()
    except KeyboardInterrupt:
        print("Interrupted by user")
    finally:
        server.close()
