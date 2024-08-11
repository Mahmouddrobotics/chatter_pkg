#include "ros/ros.h"
#include "std_msgs/Int32.h"

int main(int argc, char **argv)
{
  // Initialize the ROS system and the node.
  ros::init(argc, argv, "int32_pub_node");

  // Create a NodeHandle, which is the main access point to communications with the ROS system.
  ros::NodeHandle n;

  // Create a Publisher object. This publishes messages of type std_msgs::Int32
  // to the topic "chatter". The queue size is set to 50.
  ros::Publisher Int32_pub = n.advertise<std_msgs::Int32>("int_pub", 50);

  // Set a rate to publish messages. Here, it is set to 10 Hz.
  ros::Rate loop_rate(10);

  // Initialize the counter to 0.
  int count = 0;

  // Keep running the node until ROS is shut down.
  while (ros::ok())
  {
    // Create a new Int32 message object.
    std_msgs::Int32 msg;

    // Set the data field of the message to the current count value.
    msg.data = count;

    // Publish the message.
    Int32_pub.publish(msg);

    // Call spinOnce to allow ROS to process incoming messages.
    ros::spinOnce();

    // Sleep for the remainder of the loop rate time.
    loop_rate.sleep();

    // Increment the counter.
    ++count;
  }

  return 0;
}
