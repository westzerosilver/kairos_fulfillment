import socket
import threading

class SocketServer:
    def __init__(self, host='localhost', port=40023):
        self.host = host
        self.port = port
        self.server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    def start_server(self):
        self.server_socket.bind((self.host, self.port))
        self.server_socket.listen(1)
        print(f"Server listening on {self.host}:{self.port}")

        client_socket, client_address = self.server_socket.accept()
        while True:
            print(f"Connection from {client_address}")
            
            data = client_socket.recv(1024).decode('utf-8')
            if data:
                print(f"Received from client: {data}")
                response = f"Server received: {data}"
                client_socket.sendall(response.encode('utf-8'))
            
            # client_socket.close()

    def close_server(self):
        self.server_socket.close()

if __name__ == "__main__":
    server = SocketServer()
    try:
        server.start_server()
    except KeyboardInterrupt:
        server.close_server()
        print("Server closed.")

