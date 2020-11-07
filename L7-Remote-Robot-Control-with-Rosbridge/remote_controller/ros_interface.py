import roslibpy

ROBOT_IP = "192.168.0.166"
ROBOT_PORT = 9090


class RosInterface:

    def __init__(self):
        self.client = roslibpy.Ros(host=ROBOT_IP, port=ROBOT_PORT)

    def connect(self):
        try:
            self.client.run()
            print('Connected')
        except Exception as e:
            print('WebSocket Error: ' + str(e))

    def publish(self, topic, msg_type, msg):
        if self.isConnected():
            talker = roslibpy.Topic(self.client, topic, msg_type)
            talker.publish(msg)
            print('Sending message...')
        else:
            print('The client is not connected to the server')

    def isConnected(self):
        return self.client.is_connected

    def closeConnection(self):
        if self.isConnected():
            self.client.terminate()
        else:
            print('Connection was already closed')
