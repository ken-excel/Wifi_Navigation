#include "ros/ros.h"
#include "ros_start/Service.h"
#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "move_pos");
  if (argc != 3)
  {
    ROS_INFO("usage: move_pos x y (distance in cm)");
    return 1;
  }

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<ros_start::Service>("move_pos");
  ros_start::Service srv;
  srv.request.goal_x = atoll(argv[1]);
  srv.request.goal_y = atoll(argv[2]);

  return 0;
}
