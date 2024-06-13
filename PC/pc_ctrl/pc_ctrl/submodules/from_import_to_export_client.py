import socket
import json

class DictionaryClient:
    def __init__(self, host='172.30.1.5', port=40023):
        self.host = host
        self.port = port
        self.client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    
    def connect_to_server(self):
        self.client_socket.connect((self.host, self.port))
    
    def send_bool_to_server(self, bool_data):
        # Serialize the data
        bool_data_str = str(int(bool_data))
        # Send the data to the server
        self.client_socket.sendall(bool_data_str.encode('utf-8'))
    
    def receive_response_from_server(self):
        # Receive the response from the server
        response_data = self.client_socket.recv(1024)
        if response_data:
            # Decode and deserialize the response data
            response_dict = json.loads(response_data.decode('utf-8'))
            return response_dict
    
    def close_connection(self):
        self.client_socket.close()

if __name__ == "__main__":
    client = DictionaryClient()
    client.connect_to_server()
    
    while True:
        bool_input = input("보낼 bool 값을 입력하세요 (True 또는 False): ")
        if bool_input.lower() == 'true':
            bool_data = True
        elif bool_input.lower() == 'false':
            bool_data = False
        else:
            print("올바른 입력이 아닙니다. True 또는 False로 입력하세요.")
            continue
        
        # Send the bool data to the server
        client.send_bool_to_server(bool_data)
        
        # Receive and print the response from the server
        response = client.receive_response_from_server()
        print("서버로부터 받은 응답:", response)
        
        if bool_input.lower() == 'exit':
            break
    
    client.close_connection()
