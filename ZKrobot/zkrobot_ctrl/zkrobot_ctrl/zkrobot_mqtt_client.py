import rclpy
from rclpy.node import Node
from mycobot_interfaces.srv import StateRQ
import paho.mqtt.client as mqtt


class ZkrobotMqttClient(Node) :
    def __init__(self):
        super().__init__("zkrobot_mqtt_client")
        self.srv = self.create_service(StateRQ, 'zkrobot', self.zkrobot_callback)
        
        item_dict = {"box":1, "clay" : 2, "cube" : 3, "eclipse" : 4, "profile" : 5, "soap" : 6}

        self.services_call_out=["out2,0", "out1,0", "out0,0", "out1,1","out0,1", "out2,1"]
        self.services_call_in=["in2,0", "in1,0", "in0,0", "in1,1","in0,1", "in2,1"]
        self.zkrobot_state = ""

        self.is_finigh = False
        
        # mqtt
        self.is_working = False
        self.mqttc = mqtt.Client()

        self.mqttc.on_message = self.on_message
        self.mqttc.on_connect = self.on_connect
        self.mqttc.on_publish = self.on_publish
        self.mqttc.on_subscribe = self.on_subscribe

        url = "driver.cloudmqtt.com"
        port = 18945
        username = "obbzescv"
        password = "BV6O_y05366U"

        self.mqttc.username_pw_set(username, password)
        self.mqttc.connect(url ,port)

        # subscribe
        self.mqttc.subscribe("ESP",0)
        self.mqttc.subscribe("PC",0)
        self.mqttc.subscribe("ESP2",0)
        self.mqttc.subscribe("PC2",0)

        self.mqttc.loop_start()

    def zkrobot_callback(self, request:StateRQ.Request, response:StateRQ.Response):
        id = request.target

        self.publish_command_message(id, request.trigger)
        while self.is_finigh == False:
            pass
        response.endflag = self.is_finigh
        response.result = id
        self.is_finigh = False
        
        # if request.trigger == True:
        #     self.publish_command_message(id)
        #     while self.is_finigh == False:
        #         pass
        #     response.endflag = self.is_finigh
        #     response.result = id
        #     self.is_finigh = False
        # elif request.trigger == False:
        #     self.publish_command_message(id)
        #     while self.is_finigh == False:
        #         pass
        #     response.endflag = self.is_finigh
        #     response.result = id
        #     self.is_finigh = False

            
        
        return response
    

 

    # mqtt 접속
    def on_connect(self, client, userdata, flags, rc):
        print("rc: " + str(rc))

    # 브로커에게 메시지 도착시 실행 
    def on_message(self, client, obj, msg):
        print(msg.topic + " " + str(msg.qos) + " " + str(msg.payload.decode("utf-8")))
        str_msg = str(msg.payload.decode("utf-8"))
        

        if msg.topic == 'ESP':
            # 
            if str_msg == "ready":
                print("ESP: ready")

            if str_msg == "out": 
                self.mqttc.publish("PC2", "out_get")
            elif str_msg == "out_get": 
                self.mqttc.publish("PC2", "out_give")
            if str_msg == "in": 
                self.mqttc.publish("PC2", "in_get")
            elif str_msg == "in_get":
                self.mqttc.publish("PC2", "in_give")

            # AGV 
            if str_msg == "out_give" or str_msg == "in_give":
                self.is_finigh = True


        elif msg.topic == 'ESP2':
            if str_msg == "out_get": 
                self.mqttc.publish("PC", "out_get")
            elif str_msg == "out_give": 
                self.mqttc.publish("PC", "out_give")
            if str_msg == "in_get": 
                self.mqttc.publish("PC", "in_get")
            elif str_msg == "in_give": 
                self.mqttc.publish("PC", "in_give")



    def publish_command_message(self, id, trigger):
        id = int(id)
        
        if id >= len(self.services_call_in) or id < 0:
            print("index error")
        else:
            if trigger == True :
                self.mqttc.publish("PC", self.services_call_out[id])
                print("PC message send ", self.services_call_out[id])
                self.is_working = True

            if trigger == False :
                self.mqttc.publish("PC", self.services_call_in[id])
                print("PC message send ", self.services_call_in[id])
                self.is_working = True


    
    # publish 성공시 실행: publish를 보내고 난 후 처리를 하고 싶을 때 사용
    def on_publish(self, client, obj, mid):
        print("mid: " + str(mid))

    
    # subscribe 성공시 호출
    def on_subscribe(self, client, obj, mid, granted_qos):
        print("Subscribe complete : " + str(mid) + " " + str(granted_qos))

def main(args=None):
    rclpy.init(args=args)

    zkrobot_mqtt_client = ZkrobotMqttClient()



    rclpy.spin(zkrobot_mqtt_client)
    zkrobot_mqtt_client.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()