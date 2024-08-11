#include "ros/ros.h"
#include "custom_msg_pkg/Age.h"



int main(int argc, char **argv)
{
 
  ros::init(argc, argv, "Age_publisher");

  
  ros::NodeHandle n;

  
  ros::Publisher age_pub = n.advertise<custom_msg_pkg::Age>("age", 1000);

  ros::Rate loop_rate(10);

  
  int count = 0;
  while (ros::ok())
  {
    
    custom_msg_pkg::Age age_msg;

   
    age_msg.years = 1965;
    age_msg.months= 3;
    age_msg.days= 7;

   
    
    age_pub.publish(age_msg);

    ros::spinOnce();

    loop_rate.sleep();
   
  }


  return 0;
}