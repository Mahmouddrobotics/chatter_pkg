#include "ros/ros.h"
#include "custom_msg_pkg/Age.h"
#include <iostream>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "Age_publisher");
  ros::NodeHandle n;

  ros::Publisher age_pub = n.advertise<custom_msg_pkg::Age>("age", 1000);
  ros::Rate loop_rate(10);

  while (ros::ok())
  {
    custom_msg_pkg::Age age_msg;

    // Ask the user for the year, month, and day
    std::cout << "Enter the birth year: ";
    std::cin >> age_msg.years;

    std::cout << "Enter the birth month: ";
    std::cin >> age_msg.months;

    std::cout << "Enter the birth day: ";
    std::cin >> age_msg.days;

    // Publish the message
    age_pub.publish(age_msg);

    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}
