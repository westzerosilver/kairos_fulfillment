import rclpy
from rclpy.node import Node
from pc_ctrl_interfaces.srv import CobotStateSrv
import socket
import threading

clients = []

class ChatServer(Node):

    def __init__(self):
        super().__init__('chat_server')
        self.srv = self.create_service(CobotStateSrv, 'broadcast_message', self.broadcast_message_callback)
        self.server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.server_socket.bind(('', 8098))
        self.server_socket.listen(5)
        self.get_logger().info('Server listening on port 8098')
        threading.Thread(target=self.accept_clients).start()
        self.services_call=["out0,0","out0,1","out0,2","out1,0","out1,1","out1,2"]

    def accept_clients(self):
        while True:
            client_socket, client_address = self.server_socket.accept()
            self.get_logger().info(f'Connection from {client_address}')
            clients.append(client_socket)
            client_handler = threading.Thread(target=self.handle_client, args=(client_socket, client_address))
            client_handler.start()

    def handle_client(self, client_socket, client_address):
        while True:
            try:
                message = client_socket.recv(1024).strip()
                if not message:
                    break
                self.get_logger().info(f'Client {client_address}: {message.decode()}')
                self.broadcast(f"Client {client_address}: {message.decode()}", client_socket)
            except ConnectionResetError:
                break

        client_socket.close()
        self.get_logger().info(f'Connection with {client_address} closed')
        clients.remove(client_socket)

    def broadcast(self, message, sender_socket):
        for client in clients:
            if client != sender_socket:
                try:
                    client.send(message.encode())
                except:
                    client.close()
                    clients.remove(client)

    def broadcast_message_callback(self, request:CobotStateSrv.Request, response:CobotStateSrv.Response):
        if request.trigger:
            try:
                message=self.services_call[request.target]
                self.get_logger().info(f'Received broadcast message: {message}')
                self.broadcast(message, None)
                response.endflag = True
                response.result =0
            except:
                self.get_logger().info(f'Run Task Fail')
                response.endflag = False
                response.result =-1
        else:
            self.get_logger().info(f'Request Fail')
            response = False
            response.result =-1

        return response

def main(args=None):
    rclpy.init(args=args)
    chat_server = ChatServer()
    rclpy.spin(chat_server)
    chat_server.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
    





