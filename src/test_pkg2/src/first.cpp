#include "ros/ros.h"

#include "test_pkg2/chararray.h"
#include "pkg3_msgs/floatarray.h"

int main(int argc, char** argv){
    ros::init(argc, argv, "node1");
    return 0;
}