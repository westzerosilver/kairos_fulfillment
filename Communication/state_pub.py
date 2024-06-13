import socket
import threading
import pickle
import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from sensor_msgs.msg import JointState

class MultiPurposeServer(Node):
    def __init__(self, host='172.30.1.5', port_string=30023, port_joint_state=40201):
        super().__init__('multi_purpose_server')

        # Publishers for both String and JointState messages
        self.string_publisher = self.create_publisher(String, 'liner_machine_state', 10)
        self.joint_state_publisher = self.create_publisher(JointState, 'import/joint_states', 10)

        # Socket setup for String messages
        self.host = host
        self.port_string = port_string
        self.server_socket_string = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

        # Socket setup for JointState messages
        self.port_joint_state = port_joint_state
        self.server_socket_joint_state = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    def start_string_server(self):
        self.server_socket_string.bind((self.host, self.port_string))
        self.server_socket_string.listen(1)
        print(f"String Server listening on {self.host}:{self.port_string}")

        client_socket, client_address = self.server_socket_string.accept()
        print(f"Connection from {client_address}")
        while True:
            data = client_socket.recv(1024).decode('utf-8')
            if data:
                msg = String()
                msg.data = data
                self.string_publisher.publish(msg)
                print(f"Received from client: {data}")
                response = f"Server received: {data}"
                client_socket.sendall(response.encode('utf-8'))

    def start_joint_state_server(self):
        self.server_socket_joint_state.bind((self.host, self.port_joint_state))
        self.server_socket_joint_state.listen(1)
        print(f"JointState Server listening on {self.host}:{self.port_joint_state}")

        connection, address = self.server_socket_joint_state.accept()
        print(f"Client connected: {address}")
        while True:
            try:
                data = connection.recv(4096)
                if data:
                    msg = pickle.loads(data)
                    self.joint_state_publisher.publish(msg)
                    print(f"Received JointState: {msg}")
            except Exception as e:
                print(f"Failed to receive data: {e}")
                break

    def start_servers(self):
        string_thread = threading.Thread(target=self.start_string_server)
        joint_state_thread = threading.Thread(target=self.start_joint_state_server)

        string_thread.start()
        joint_state_thread.start()

        string_thread.join()
        joint_state_thread.join()

    def close_servers(self):
        self.server_socket_string.close()
        self.server_socket_joint_state.close()

def main(args=None):
    rclpy.init(args=args)
    server = MultiPurposeServer()

    try:
        server.start_servers()
    except KeyboardInterrupt:
        server.close_servers()
        print("Servers closed.")
        rclpy.shutdown()

if __name__ == '__main__':
    main()
