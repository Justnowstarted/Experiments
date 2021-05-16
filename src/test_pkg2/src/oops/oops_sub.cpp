#include "ros/ros.h"
#include "std_msgs/String.h"


class Subscribe_
{
    private:
        /* data */
    public:
        Subscribe_(ros::NodeHandle* n)
        {
            ros::Subscriber sub = n->subscribe("/counter", 1000, &Subscribe_::chatterCallback, this);
            ros::spin();
        }
        
        void chatterCallback(const std_msgs::String::ConstPtr& msg){
            ROS_INFO("I heard: [%s]", msg->data.c_str());
        }
        ~Subscribe_();
};

Subscribe_::~Subscribe_()
{
}



int main(int argc, char** argv){
    ros::init(argc, argv, "oops_listener");
    ros::NodeHandle nh;
    Subscribe_ p = Subscribe_(&nh);
}