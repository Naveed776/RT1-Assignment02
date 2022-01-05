#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"
#include "geometry_msgs/Twist.h" 
#include "second_assignment/Vel.h"
#include "second_assignment/Velocity.h"
#include "std_srvs/Empty.h"


// add publisher in the global

ros::Publisher pub;
geometry_msgs::Twist my_vel;

// intinalize some varaible that I use in my code

float increment=0;

float addition=0;

//create readdistance function 

float readdistance (float ranges[],int min, int max){

//maximum speed of robot

	float value_min = 30;
	int i;
	for (  i = min; i <= max; i++){
	 if (ranges[i]<=value_min) value_min = ranges[i];
	 }
	 return value_min;
}


// using robotcallback function that control the robot

void robotcallback(const sensor_msgs::LaserScan::ConstPtr& msg)
{
//instruction the robot to move in some directions

 float right , left, front;
 float view[721];
 
 //using for loop to give the input to the array will transfer to the readdistance
 for(int i = 0; i<721; i++)
{
        view[i] = msg->ranges[i];
}
//define the closet distance of robot 

right = readdistance(view, 0, 100);
front = readdistance(view, 300, 400);
left = readdistance(view, 620, 720);



	if (front<1.5){
		if(left>right){
		my_vel.linear.x = 0.1;
		my_vel.angular.z = 1;
		
	}
	else if (right>left){
		my_vel.linear.x = 0.1;
		my_vel.angular.z = -1;

	}
        }
	else{
	my_vel.linear.x = 1 + addition;
	my_vel.angular.z = 0;
	}
	
//develop some strateges to up the velocity	
	float Linear = my_vel. linear.x;
//printf is used for display the addition 

	printf("value of addition:%f\n",my_vel. linear.x);
	
	pub.publish(my_vel);

}


//Velcoitycallback using to get the velocity 

void VelocityCallback(const second_assignment::Vel::ConstPtr& up){
   addition = up->increment;
}
   
int main (int argc, char **argv)

{
// Initialize the node, setup the NodeHandle for handling the communication with the ROS
//system
	ros::init(argc, argv, "moving");
	ros::NodeHandle nh;
	
// Define the subscriber for base scan and for velocity
	ros::Subscriber sub = nh.subscribe("/base_scan", 1, robotcallback);
	ros::Subscriber sub2 = nh.subscribe("/Vel", 1, VelocityCallback);
	
	
//define the publisher to comapre with global one

	pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 1);
//use for spinning	
	ros::spin();
	return 0;
}
