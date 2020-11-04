/*
  arduinobot
  Script that creates a ROS node on the Arduino that subscribes to topic
  for the joint contorl of the arm and the one of the gripper.
  When a new messages is published on a topic, th 
  Copyright (c) 2020 Antonio Brandi.  All right reserved.
*/

#include <Servo.h>
#include <ros.h>
#include <geometry_msgs/Vector3.h>
#include <std_msgs/Int16.h>

// Declare the Arduino pin where each servo is connected
#define SERVO_BASE_PIN 8
#define SERVO_SHOULDER_PIN 9
#define SERVO_ELBOW_PIN 10
#define SERVO_GRIPPER_PIN 11

// Register the servo motors of each joint
Servo base;  
Servo shoulder;  
Servo elbow;  
Servo gripper;  

ros::NodeHandle  nh;

// Variable that keeps track of the current position of each joint
int last_angle_base = 0;
int last_angle_shoulder = 0;
int last_angle_elbow = 0;
int last_angle_gripper = 0;

/*
 * This function moves a given servo smoothly from a given start position to a given end position.
 * The mouvement can be both clockwise or counterclockwise based on the values assigned to
 * the start position and end position
 */
void reach_goal(Servo servo, int start_point, int end_point){
  if(end_point>=start_point){
    for (int pos = start_point; pos <= end_point; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo.write(pos);     
    delay(15);                       
    }
  } else{
    for (int pos = start_point; pos >= end_point; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo.write(pos);     
    delay(15);                       
    }
  }
}


void jointCb( const geometry_msgs::Vector3& msg){
  // Move the base
  if(msg.x>0 && msg.x<181){
    int target = (int)msg.x;
    reach_goal(base, last_angle_base, target);
    last_angle_base = target;
  }
  
  // Move the shoulder
  if(msg.y>0 && msg.y<181){
    int target = (int)msg.y;
    reach_goal(shoulder, last_angle_shoulder, target);
    last_angle_shoulder = target;
  }

  // Move the elbow
  if(msg.x>0 && msg.x<181){
    int target = (int)msg.z;
    reach_goal(elbow, last_angle_elbow, target);
    last_angle_elbow = target;
  }
}

void gripperCb ( const std_msgs::Int16& msg){
  if (msg.data>0 && msg.data<181){
    int target = msg.data;
    reach_goal(gripper, last_angle_gripper, target);
    last_angle_gripper = target;
  }
}

ros::Subscriber<geometry_msgs::Vector3> sub_joint("servo_actuate", &jointCb );
ros::Subscriber<std_msgs::Int16> sub_gripper("gripper_actuate", &gripperCb );


void setup() {
  // Attach each Servo to the Arduino pin where it is connected
  base.attach(SERVO_BASE_PIN);
  shoulder.attach(SERVO_SHOULDER_PIN);
  elbow.attach(SERVO_ELBOW_PIN);
  gripper.attach(SERVO_GRIPPER_PIN); 

  // Set a common start point for each joint
  base.write(0);
  shoulder.write(0);
  elbow.write(0);
  gripper.write(0);

   // Inizialize the ROS node on the Arduino
  nh.initNode();
  // Inform ROS that this node will subscribe to messages on a given topic
  nh.subscribe(sub_joint);
  nh.subscribe(sub_gripper);
}

void loop() {
  // Keep the ROS node up and running
  nh.spinOnce();
  delay(1);
}
