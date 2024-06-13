import rclpy
from rclpy.node import Node
from pc_ctrl_interfaces.srv import CobotStateSrv

class ZkrobotClient(Node) :
    
    def __init__(self):
        super().__init__('zkrobot_client')
        self.srv_pc = self.create_client(CobotStateSrv, 'broadcast_message')
        self.request = CobotStateSrv.Request()

    def send_request(self):
        self.request.trigger = True
        self.request.cnt = 1
        self.future = self.cli.call_async(self.request)
        rclpy.spin_until_future_complete(self, self.future)
        print(self.future.result())
        return self.future.result()

def main():
    rclpy.init()
    client = ZkrobotClient()
    rclpy.spin(client)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
