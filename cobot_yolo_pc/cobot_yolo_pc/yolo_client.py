import rclpy
from rclpy.node import Node
from pc_ctrl_interfaces.srv import cobot_srv

class CobotClient(Node) :
    
    def __init__(self):
        super().__init__('cobot_client')
        self.srv_pc = self.create_client(cobot_srv, 'end_detection')

    def send_request(self):
        self.request.trigger = True
        self.request.cnt = 1
        self.future = self.cli.call_async(self.request)
        rclpy.spin_until_future_complete(self, self.future)
        return self.future.result()

    
           