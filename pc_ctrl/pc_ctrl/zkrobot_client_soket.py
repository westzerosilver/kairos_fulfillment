import socket
import json

class ZkrobotClient:
    def __init__(self, host='172.30.1.5', port=30023):
        self.host = host
        self.port = port
        self.client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    def connect_to_server(self):
        self.client_socket.connect((self.host, self.port))

    def send_message(self, message):
        # self.client_socket.connect((self.host, self.port))
        self.client_socket.sendall(message.encode('utf-8'))
        
        # response = self.client_socket.recv(1024).decode('utf-8')
        # print(f"Received from server: {response}")

    def close(self):
        self.client_socket.close()

if __name__ == "__main__":
    client = ZkrobotClient()
    try:
        client.send_message("testMSG")
    finally:
        print("client_socket is close")
        client.close()
