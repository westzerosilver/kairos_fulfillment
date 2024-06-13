import socket
import json

class DictionaryClient:
    def __init__(self, host='localhost', port=60021):
        self.host = host
        self.port = port
        self.client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        
    def send_data_to_server(self, data):
        self.client_socket.connect((self.host, self.port))
        
        # Serialize and send the data
        serialized_data = json.dumps(data).encode('utf-8')
        self.client_socket.sendall(serialized_data)
        
        # Receive the response from the server
        response = self.client_socket.recv(1024)
        if response:
            self.handle_response(response)
            
    def handle_response(self, response):
        # Decode and deserialize the response
        response_dict = json.loads(response.decode('utf-8'))
        print(f"Received response: {response_dict}")

    def close(self):
        self.client_socket.close()

if __name__ == "__main__":
    client = DictionaryClient()
    sample_data = {"address": "value", "eclipse": 0, "box": 0, "cube": 0, "clay": 0, "sope": 0}
    try:
        client.send_data_to_server(sample_data)
    finally:
        client.close()
