import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
import socket
import threading
import pickle

class JointStateReceiver(Node):
    def __init__(self):
        super().__init__('joint_state_receiver')
        self.publisher = self.create_publisher(JointState, 'import_joint_states', 10)

        # Socket setup
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.sock.bind(('', 40201))
        self.sock.listen(1)
        self.connection, self.address = self.sock.accept()
        print("client connect   address: ",self.address)

    def receive_data(self):
        while True:
            try:
                # Receive the data from the socket
                data = self.connection.recv(4096)
                
                if not data:
                    pass
                # Deserialize the data using pickle
                msg = pickle.loads(data)
                # print(msg)
                # Publish the message to ROS2 topic
                self.publisher.publish(msg)
            except:
                # print("receive fail")
                pass

def main(args=None):
    rclpy.init(args=args)
    joint_state_receiver = JointStateReceiver()

    # Run the receive_data method in a separate thread
    
    receive_thread = threading.Thread(target=joint_state_receiver.receive_data)
    receive_thread.start()

    rclpy.spin(joint_state_receiver)

    joint_state_receiver.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
