import rclpy
from rclpy.node import Node
from pc_ctrl_interfaces.srv import CobotStateSrv

class CobotServicesServer(Node):
    def __init__(self) :
        super().__init__('cobot_services_server')
        self.srv_pc = self.create_service(CobotStateSrv, 'start_detection', self.detection_srv_callback)

    def detection_srv_callback(self, request:CobotStateSrv.Request, response:CobotStateSrv.Response):

        response.trigger = True
        response.cnt = 0

        return response
    
    

def main():
    rclpy.init()
    service = CobotServicesServer()
    rclpy.spin(service)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
