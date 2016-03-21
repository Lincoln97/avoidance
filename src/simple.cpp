#include <ros/ros.h>
#include <std_msgs/Float32.h>
#include <geometry_msgs/Twist.h>

ros::Publisher twist_pub;

geometry_msgs::Twist v;

double fsonar, rsonar, lsonar;

void frontsonarcallback(const std_msgs::Float32ConstPtr &msgf);

void rightsonarcallback(const std_msgs::Float32ConstPtr &msgr);

void leftsonarcallback(const std_msgs::Float32ConstPtr &msgl);

void movement();

int main(int argc, char **argv)
{
    ros::init(argc, argv, "simple_avoidance");
    
    ros::NodeHandle node;
    
    twist_pub = node.advertise<geometry_msgs::Twist>("Velocity", 1);
    
    ros::Subscriber fsonar_sub = node.subscribe("/vrep/vehicle/frontSonar", 1, frontsonarcallback);
    ros::Subscriber rsonar_sub = node.subscribe("/vrep/vehicle/rightSonar", 1, rightsonarcallback);
    ros::Subscriber lsonar_sub = node.subscribe("/vrep/vehicle/leftSonar", 1, leftsonarcallback);
    
    movement();
    
    ros::spin();
    
    return 0;
}

void frontsonarcallback(const std_msgs::Float32ConstPtr &msgf){
    
    fsonar = msgf->data;
    std::cout << "fsonar: " << fsonar << std::endl;
}

void rightsonarcallback(const std_msgs::Float32ConstPtr &msgr){
    
    rsonar = msgr->data;
    std::cout << "rsonar: " << rsonar << std::endl;
}

void leftsonarcallback(const std_msgs::Float32ConstPtr &msgl){
    
    lsonar = msgl->data;
    std::cout << "lsonar: " << lsonar << std::endl;
}

void movement(){
    
}