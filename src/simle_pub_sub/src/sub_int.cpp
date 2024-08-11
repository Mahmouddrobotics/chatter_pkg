#include "ros/ros.h"
#include "std_msgs/Int32.h"  // Change the message type to Int32

void chatterCallback(const std_msgs::Int32::ConstPtr& msg) // Update the message type in the callback
{
  ROS_INFO("I heard: [%d]", msg->data);  // Use %d to print integer values
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "sub_int");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback); // Keep the same topic but the message type is now Int32

  ros::spin();

  return 0;
}
