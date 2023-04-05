#include <ros/ros.h>
#include <sensor_msgs/Image.h>


int main(int argc, char **argv) {
    ros::init(argc, argv, "test_tracking");

    auto nh = std::make_shared<ros::NodeHandel>("~");
}