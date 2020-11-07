#!/usr/bin/env python
import rospy
from sensor_msgs.msg import JointState

# function that gets called every time a new message is published on the topic /jarvis_controller
def jarvis_controller_callback(data):
    pub.publish(data)   

if __name__ == '__main__':
    pub = rospy.Publisher('joint_states', JointState, queue_size=10)
    rospy.init_node('remote_controller', anonymous=True)

    # Subscribe to the topic in which the voice assistant is writing
    rospy.Subscriber("jarvis_controller", JointState, jarvis_controller_callback)

    # Keep the subscriber running
    rospy.spin()