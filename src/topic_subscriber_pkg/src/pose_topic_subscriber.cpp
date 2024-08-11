#include "ros/ros.h"
#include "turtlesim/Pose.h"

// Callback function to handle the incoming pose data
void poseCallback(const turtlesim::Pose::ConstPtr& msg)
{
    ROS_INFO("Turtle Pose - x: [%f], y: [%f], theta: [%f]", msg->x, msg->y, msg->theta);
}

int main(int argc, char **argv)
{
    // Initialize the ROS node
    ros::init(argc, argv, "pose_topic_subscriber");

    // Create a node handle
    ros::NodeHandle nh;

    // Subscribe to the /turtle1/pose topic
    ros::Subscriber pose_sub = nh.subscribe("/turtle1/pose", 1000, poseCallback);

    // Keep the node alive and listening for callbacks
    ros::spin();

    return 0;
}
