import socket
import json
import threading
import time

class ExportServerThread(threading.Thread):
    def __init__(self, host='172.30.1.5', port=40023):
        threading.Thread.__init__(self,daemon=True)
        self.host = host
        self.port = port
        self.server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.received_bool = False
    
    def run(self):
        self.server_socket.bind((self.host, self.port))
        self.server_socket.listen()
        print(f"Server listening on {self.host}:{self.port}")
        
        while True:
            self.conn, addr = self.server_socket.accept()
            with self.conn:
                print(f"self.connected by {addr}")
                self.handle_client()
    
    def handle_client(self):
        while True:
            data = self.conn.recv(1024)
            if not data:
                break
            # Decode and deserialize the data
            received_data = data.decode('utf-8')
            self.received_bool = bool(int(received_data))
            print(f"Received boolean: {self.received_bool}")
            

    def send_data_to_client(self, data):
        # Serialize and send the response
        response_data = json.dumps(data).encode('utf-8')
        self.conn.sendall(response_data)

    def close(self):
        self.server_socket.close()

if __name__ == "__main__":
    server_thread = ExportServerThread()
    server_thread.start()
    try:
        while True:
            if not server_thread.received_bool:
                print("waiting for receive...")
                time.sleep(2)
            else:
                for i in range(0,5):
                    print("prosses", i ,"working")
                    time.sleep(1)
                server_thread.send_data_to_client(True)
                server_thread.received_bool=False
    finally:
        server_thread.close()
