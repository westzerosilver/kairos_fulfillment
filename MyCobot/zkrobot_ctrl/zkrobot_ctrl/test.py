
import paho.mqtt.client as mqtt

# ------------------- mqtt 메소드 -------------------

# mqtt 접속
def on_connect(client, userdata, flags, rc):
    print("rc: " + str(rc))
 
# 브로커에게 메시지 도착시 실행 
def on_message(client, obj, msg):
    print("msg")
    print(msg.topic + " " + str(msg.qos) + " " + str(msg.payload.decode("utf-8")))

# publish 성공시 실행: publish를 보내고 난 후 처리를 하고 싶을 때 사용
def on_publish(client, obj, mid):
    print("mid: " + str(mid))
 
# subscribe 성공시 호출
def on_subscribe(client, obj, mid, granted_qos):
    print("Subscribe complete : " + str(mid) + " " + str(granted_qos))

def on_log(client, obj, level, string):
    print(string)

# 객체 할당
mqttc = mqtt.Client()

# 콜백 함수 할당하기
mqttc.on_message = on_message
mqttc.on_connect = on_connect
# mqttc.on_publish = on_publish
mqttc.on_subscribe = on_subscribe
mqttc.on_log = on_log 

# mqtt 접속시 필요한 정보
url = "driver.cloudmqtt.com"
port = 18945
username = "obbzescv"
password = "BV6O_y05366U"

mqttc.username_pw_set(username, password)
mqttc.connect(url ,port)

# 사용 토픽 구독
mqttc.subscribe('temp',0)
mqttc.subscribe('humi',0)

mqttc.loop_forever()

	
while True:
	
	pass
	# ------------ mqtt publish ------------
	# mqttc.publish("temp", 3)
	# mqttc.publish("humi",3)
