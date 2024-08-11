#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include "std_msgs/Float32.h"

// Define the constant for division
const float DIVISOR = 10.0;

// Declare the publisher globally
ros::Publisher float_pub;

// Callback function to process incoming Int32 messages and publish Float32 messages
void intCallback(const std_msgs::Int32::ConstPtr& msg)
{
  // Create a new Float32 message object
  std_msgs::Float32 float_msg;

  // Divide the incoming integer value by the divisor
  float_msg.data = static_cast<float>(msg->data) / DIVISOR;

  // Log the result
  ROS_INFO("Received Int32: %d, Divided value: %f", msg->data, float_msg.data);

  // Publish the Float32 message
  float_pub.publish(float_msg);
}

int main(int argc, char **argv)
{
  // Initialize the ROS system and the node
  ros::init(argc, argv, "divider_node");

  // Create a NodeHandle object
  ros::NodeHandle nh;

  // Initialize the publisher object for Float32 messages
  float_pub = nh.advertise<std_msgs::Float32>("divided_value", 50);

  // Create a Subscriber object to listen to Int32 messages on the "int_pub" topic
  ros::Subscriber int_sub = nh.subscribe("int_pub", 50, intCallback);

  // Keep the node running
  ros::spin();

  return 0;
}
