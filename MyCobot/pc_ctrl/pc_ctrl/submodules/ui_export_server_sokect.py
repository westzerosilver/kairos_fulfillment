import socket
import json
import threading

class DictionaryServer:
    def __init__(self, host='', port=40022):
        self.host = host
        self.port = port
        self.order = []
        self.server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.server_thread=threading.Thread(target=self.start_server,daemon=True)
        
        
    def start_server(self):
        self.server_socket.bind((self.host, self.port))
        self.server_socket.listen()
        print(f"Server listening on {self.host}:{self.port}")
        
        while True:
            conn, addr = self.server_socket.accept()
            with conn:
                print(f"Connected by {addr}")
                self.handle_client(conn)
                
    def handle_client(self, conn):
        while True:
            data = conn.recv(1024)
            if not data:
                break
            # Decode and deserialize the data
            self.received_dict = json.loads(data.decode('utf-8'))
            self.order.append(self.received_dict)
            print(f"Received dictionary: {self.received_dict}")
            
            
            # Process the received data and prepare a response
            # response_dict = {"status": "success", "received": self.received_dict}
            
            # # Serialize and send the response
            # response_data = json.dumps(response_dict).encode('utf-8')
            # conn.sendall(response_data)

    def close(self):
        self.server_socket.close()
    
    def strat_thread(self):
        self.server_thread.start()

if __name__ == "__main__":
    server = DictionaryServer()
    server.strat_thread()
    # try:
    #     server.start_server()
    # finally:
    #     server.close()
