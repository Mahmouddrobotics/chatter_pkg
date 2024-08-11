#include "ros/ros.h"
#include "custom_msg_pkg/Age.h"

void ageCallback(const custom_msg_pkg::Age::ConstPtr& msg)
{
  int current_year = 2024;  // Set the current year
  int age_years = current_year - msg->years;
  
  // Output the age in years, months, and days
  ROS_INFO("Calculated Age: %d years, %d months, %d days", age_years, msg->months, msg->days);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "age_calculator");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("age", 1000, ageCallback);

  ros::spin();

  return 0;
}
