#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{
  /**
  Before calling any other roscpp functions in a node you must call one of the ros::init() functions
  ----ros::init(<command line or remapping arguments>, std::string node_name, uint32_t options)
  ROS uses 'argc and argv' to parse remapping arguments from the command line
   */
  ros::init(argc, argv, "talker");

  /**
  NodeHandle is the roscpp's interface for creating subscribers, publishers, etc. This class is used for writing nodes. It provides a RAII interface to this process' node.
  when the first NodeHandle is created, it instantiates everything necessary for this node, and when the last NodeHandle goes out of scope it shuts down the node.
   */
  ros::NodeHandle n;

  /**
  Publisher ros::NodeHandle::advertise	(	const std::string & 	 topic,
                                                      uint32_t 	 queue_size,
                                                      const      SubscriberStatusCallback & 	connect_cb,
                                                      const      SubscriberStatusCallback & 	disconnect_cb = SubscriberStatusCallback(),
                                                      const      VoidConstPtr & 	tracked_object = VoidConstPtr(),
                                                      bool 	     latch = false 
                                                      )	
          topic           : 	Topic to advertise on
          queue_size	    :   Maximum number of outgoing messages to be queued for delivery to subscribers
          connect_cb	    :   Function to call when a subscriber connects
          disconnect_cb	(optional) : Function to call when a subscriber disconnects
          tracked_object	(optional) : A shared pointer to an object to track for these callbacks. If set, the a weak_ptr will be created to this object, and if the reference count goes to 0 the subscriber callbacks will not get called. Note that setting this will cause a new reference to be added to the object before the callback, and for it to go out of scope (and potentially be deleted) in the code path (and therefore thread) that the callback is invoked from.
          latch	(optional) : If true, the last message published on this topic will be saved and sent to new subscribers when they connect

    This call connects to the master to publicize that the node will be
    publishing messages on the given topic.  This method returns a Publisher object that allows you to
    publish a message on this topic.
   */
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);


  /*
  Need to
  */
  ros::Rate loop_rate(10);

  int count = 0;
  while (ros::ok())
  {
    /**
     * This is a message object. You stuff it with data, and then publish it.
     */
    std_msgs::String msg;

    std::stringstream ss;
    ss << "hello world " << count;
    msg.data = ss.str();

    ROS_INFO("%s", msg.data.c_str());

    /**
     * The publish() function is how you send messages. The parameter
     * is the message object. The type of this object must agree with the type
     * given as a template parameter to the advertise<>() call, as was done
     * in the constructor above.
     */
    chatter_pub.publish(msg);


    /**
    rospy.spin() and ros::spin() both block the main thread from exiting until ROS invokes a 
    shutdown - via a Ctrl + C for example.
   */
    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}