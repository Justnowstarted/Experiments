#include "ros/ros.h"
#include "std_msgs/String.h"

#include<sstream>

class Publish_{
    private:
        int counter{0};
    public:
        Publish_(ros::NodeHandle* nh)
        {
            ros::Publisher pub = nh->advertise<std_msgs::String>("/counter", 100);
            ros::Rate loop_rate(10);
            while (ros::ok())
            {
                std_msgs::String msg;
                msg.data = "Hey Pavan, I am publishing from here";
                pub.publish(msg);
                ros::spinOnce();

                loop_rate.sleep();
            }
            
        }
        ~Publish_();
};



Publish_::~Publish_()
{
}



int main(int argc, char** argv){
    ros::init(argc, argv, "oops_talker");
    ros::NodeHandle nh;
    Publish_ p = Publish_(&nh);
}