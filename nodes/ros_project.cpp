/*#include "iostream"
#include "ros/ros.h"
#include "gazebo_msgs/ModelState"
int calback()
{
    std::cout << "yolo"<< std::endl;
}
int main(int argc, char **argv)
{
    ros::NodeHandle nh;

    ros::init(argc, argv, "listener");

    ros::Subscriber sub = n.subscribe("gazebo/model_states", 1000, callback);

    ros::spin();

    return 0;

}*/


#include <gazebo/transport/transport.hh>
#include <gazebo/msgs/msgs.hh>
#include <gazebo/gazebo_client.hh>

#include <iostream>

uint32_t counter =0;
/////////////////////////////////////////////////
// Function is called everytime a message is received.
void cb(ConstPosesStampedPtr &_msg)
{
  // Dump the message contents to stdout.
  //std::cout << _msg->DebugString();

  std::cout << counter << std::endl;
  counter ++;
}

/////////////////////////////////////////////////
int main(int _argc, char **_argv)
{
  // Load gazebo
  gazebo::client::setup(_argc, _argv);

  // Create our node for communication
  gazebo::transport::NodePtr node(new gazebo::transport::Node());
  node->Init();

  // Listen to Gazebo world_stats topic
  gazebo::transport::SubscriberPtr sub = node->Subscribe("~/pose/info", cb, true);

  // Busy wait loop...replace with your own code as needed.
  while (true)
    gazebo::common::Time::MSleep(10);

  // Make sure to shut everything down.
  gazebo::client::shutdown();
}
