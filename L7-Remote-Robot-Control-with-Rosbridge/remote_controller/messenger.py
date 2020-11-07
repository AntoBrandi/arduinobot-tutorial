import roslibpy

MESSENGER_TOPIC = "jarvis_messenger"
MESSENGER_TYPE = "sd_msgs/String"


class Messenger:

    def __init__(self, ros):
        print("Insert a message for the robot")
        message = input()
        ros.publish(MESSENGER_TOPIC, MESSENGER_TYPE, roslibpy.Message({'data': message}))
