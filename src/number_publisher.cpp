#include "ros/ros.h"
#include "std_msgs/Int32.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "number_publisher");
    ros::NodeHandle nh;

    ros::Publisher number_pub = nh.advertise<std_msgs::Int32>("number_topic", 1000);

    ros::Rate loop_rate(1); // 1 Hz

    for (int i = 20; i <= 100; ++i)
    {
        std_msgs::Int32 msg;
        msg.data = i;

        ROS_INFO("Publishing: %d", msg.data);

        number_pub.publish(msg);

        ros::spinOnce();
        loop_rate.sleep();
    }

    ROS_INFO("Finished publishing numbers from 20 to 100.");

    return 0;
}
