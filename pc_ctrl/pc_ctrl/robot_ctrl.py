import rclpy
from rclpy.node import Node
from mycobot_interfaces.srv import StateRQ
from .submodules.from_import_to_export_client import DictionaryClient
from .submodules.ui_export_server_sokect import DictionaryServer
# from zkrobot_client_soket import ZkrobotClient

import time

class RobotCtrl(Node) :

    def __init__(self,node_name:str):
        super().__init__(node_name+'_client')
        self.node_name=node_name
        self.client = self.create_client(StateRQ, node_name)
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Service not available, waiting again...')
        self.request = StateRQ.Request()

    

    def send_request(self, trigger, target):
        self.request.trigger = trigger
        self.request.target = target
        print('send request to ',self.node_name)
        self.future = self.client.call_async(self.request)
        rclpy.spin_until_future_complete(self, self.future)
        return self.future.result()

 

def main(args=None):
    item_dict = {"box":0, "clay" : 1, "cube" : 2, "eclipse" : 3, "profile" : 4, "soap" : 5}
    services_call_out=["out2,0", "out1,0", "out0,0", "out1,1","out0,1", "out2,1"]
    services_call_in=["in2,0", "in1,0", "in0,0", "in1,1","in0,1", "in2,1"]

    rclpy.init(args=args)
    yolo_client = RobotCtrl("start_detection")
    zkrobot_client = RobotCtrl("zkrobot")
    cobot_client = RobotCtrl("end_detection")

    agv_client = RobotCtrl("AGV_control_service")
    ui_server = DictionaryServer()
    export_client = DictionaryClient()
    export_client.connect_to_server()
    ui_server.strat_thread()

    # zkrobot_state_client = ZkrobotClient()
    # zkrobot_state_client.connect_to_server()
    passed_id=-1

    


    while True:
        print(ui_server.order)
        if len(ui_server.order) == 0:


            # yolo
            while True:
                response = yolo_client.send_request(bool(True),int(2))
                if response.endflag == True:
                    item_id = response.result
                    break
                time.sleep(5)

            
            # zkrobot_state_client.send_message(services_call_out[int(item_id)])
            # print(f'zkrobot_state_client.send_message({services_call_out[item_id]})')
            
            # zk
            response = zkrobot_client.send_request(bool(True), int(item_id))
            zkrobot_client.get_logger().info(f'Response: endflag={response.endflag}, result={response.result}')
            
            # agv send target->1 : 
            response = agv_client.send_request(bool(True), int(2))
            agv_client.get_logger().info(f'Response: endflag={response.endflag}, result={response.result}')
            

            response = cobot_client.send_request(bool(True),int(item_id))

            cobot_client.get_logger().info(f'Response: endflag={response.endflag}, result={response.result}')

            # agv send
            response = agv_client.send_request(bool(True), int(1))
            agv_client.get_logger().info(f'Response: endflag={response.endflag}, result={response.result}')


            # zkrobot_state_client.send_message(services_call_in[item_id])
            # print(f'zkrobot_state_client.send_message({services_call_in[item_id]})')


            response = zkrobot_client.send_request(bool(False), int(item_id))
            zkrobot_client.get_logger().info(f'Response: endflag={response.endflag}, result={response.result}')

            passed_id=item_id
            
        
        else:
            print("else")
            order = ui_server.order.pop(0)

            for key, value in order.items():
                if key == "address" :
                    continue
                if value == "0":
                    continue

                item_id = item_dict[key]

            # send zk state
            # zkrobot_state_client.send_message(services_call_out[item_id])
            # print(f'zkrobot_state_client.send_message({services_call_out[item_id]})')

            # zk
            response = zkrobot_client.send_request(bool(True), int(item_id))
            zkrobot_client.get_logger().info(f'Response: endflag={response.endflag}, result={response.result}')
            
            # agv send target->1 : 
            response = agv_client.send_request(bool(True), int(3))
            agv_client.get_logger().info(f'Response: endflag={response.endflag}, result={response.result}')
            
            # send
            export_client.send_bool_to_server(True)
            print(export_client.receive_response_from_server())


            # agv send
            response = agv_client.send_request(bool(True), int(4))
            agv_client.get_logger().info(f'Response: endflag={response.endflag}, result={response.result}')

            # zkrobot_state_client.send_message(services_call_in[item_id])
            # print(f'zkrobot_state_client.send_message({services_call_out[item_id]})')

            response = zkrobot_client.send_request(bool(False), int(item_id))
            zkrobot_client.get_logger().info(f'Response: endflag={response.endflag}, result={response.result}')


    
if __name__=="__main__":
    main()


