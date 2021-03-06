#include <ros/ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Int32.h>
#include <geometry_msgs/Point.h>

#include <sstream>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    ros::init(argc, argv, "talker");
    
    ros::NodeHandle nh;
    //ros::Publisher chatter_pub = nh.advertise<geometry_msgs::Point /*std_msgs::Int32*/ /*std_msgs::String*/>("chatter", 1000); //for testing
    ros::Publisher chatter_pub = nh.advertise<geometry_msgs::Point /*std_msgs::Int32*/ /*std_msgs::String*/>("tablet/geometry_msgs/point", 1000); //for testing w/ obj_sep
    
    ros::Rate loop_rate(10);
    
    //int count = 0;
    while(ros::ok() )
    {
        geometry_msgs::Point msg;
        msg.x = 100.0;
        msg.y = 100.0;
        msg.z = -1.0;
        ROS_INFO("x: %f, y: %f, z: %f\n", msg.x, msg.y, msg.z);
        chatter_pub.publish(msg);
        
        /*
        std_msgs::String msg;
        stringstream ss;
        ss << "Arise, my robot army!";//<< count;
        msg.data = ss.str();
        ROS_INFO("%s", msg.data.c_str() );
        chatter_pub.publish(msg);
        /*
        
        /*
        std_msgs::Int32 msg;
        msg.data = 43;
        ROS_INFO("%d", msg.data);
        cout << "testconv: " << (int) msg.data << endl;
        chatter_pub.publish(msg);
        */
        
        ros::spinOnce();
        
        loop_rate.sleep();
        //count++;
    }
    
    return 0;
}
