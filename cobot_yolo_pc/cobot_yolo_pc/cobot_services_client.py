import rclpy
from rclpy.node import Node
from pc_ctrl_interfaces.srv import CobotStateSrv
from rclpy.timer import Timer

class CobotServicesClient(Node):
    def __init__(self):
        super().__init__("cobot_services_client")
        self.srv_pc = self.create_client(CobotStateSrv, 'start_detection')

        self.srv_grip = self.create_client(CobotStateSrv, 'end_detection')
        self.request = CobotStateSrv.Request()
        self.timer = self.create_timer(3.0, self.send_request_yolo)



    def send_request_yolo(self):
        self.request.trigger = True
        self.request.cnt = 1
        self.future = self.srv_pc.call_async(self.request)
        rclpy.spin_until_future_complete(self, self.future)
    
        return self.future.result()
    
    def send_request_grip(self):
        self.request.trigger = True
        self.request.cnt = 1
        self.future = self.srv_grip.call_async(self.request)
        rclpy.spin_until_future_complete(self, self.future)

        return self.future.result()
    


def main():
    rclpy.init()
    client = CobotServicesClient()


    # response = client.send_request_yolo()

    

    # if response.trigger == True:
    #     client.send_request_grip()



        

    rclpy.spin(client)
    rclpy.shutdown()

if __name__ == '__main__':
    main()

