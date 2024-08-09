#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "turtle_velocity_publisher");
    ros::NodeHandle nh;

    ros::Publisher velocity_pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);

    ros::Rate loop_rate(10); // 10 Hz

    geometry_msgs::Twist vel_msg;
    vel_msg.linear.x = 0.5; // Linear speed in the x direction (m/s)
    vel_msg.angular.z = 0.0; // No rotation

    while (ros::ok())
    {
        velocity_pub.publish(vel_msg);
        ROS_INFO("Publishing linear velocity: %f", vel_msg.linear.x);

        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}
