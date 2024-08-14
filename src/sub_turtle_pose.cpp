#include "ros/ros.h"
#include "turtlesim/Pose.h"

// Callback function to process the turtle's pose
void poseCallback(const turtlesim::Pose::ConstPtr& msg) {
    ROS_INFO("Turtle Position: [x: %f, y: %f, theta: %f]", msg->x, msg->y, msg->theta);
}

int main(int argc, char **argv) {
    // Initialize the ROS system
    ros::init(argc, argv, "pose_subscriber_node");

    // Establish this program as a ROS node
    ros::NodeHandle nh;

    // Create a subscriber object
    ros::Subscriber sub = nh.subscribe("/turtle1/pose", 10, poseCallback);

    // Enter a loop, pumping callbacks
    ros::spin();

    return 0;
}
