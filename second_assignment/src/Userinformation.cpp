#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"
#include "geometry_msgs/Twist.h" 
#include "second_assignment/Vel.h"
#include "second_assignment/Velocity.h"
#include "std_srvs/Empty.h"

//declare the serverclient
ros::ServiceClient client1;

//declare the Publisher
ros::Publisher pub;


//declare the function to take input from user
//using char our input is in character
char Getput()
{
	char v;
//print the display for the user that take value i,d,r 
	std::cout<< "------Please input the value-----\n";
	std::cout<<"for increasing the speed of robot press i\n";
	std::cout<<"for decreasing the speed of robot press d\n";
	std::cout<<"for reset the position of robot press r\n";
	std::cout<<"--------------------------------------------\n";
	std::cin >> v;
	return v;
}

void callback()
{
//provide Velocity and send a request
 second_assignment::Velocity a_srv;
 //
 char input = Getput();
 a_srv.request.taken=input;
 // waiting for thr server to send response
 client1.waitForExistence();
 client1.call(a_srv);
 
 second_assignment::Vel n;
 n.increment=a_srv.response.value;
 
 pub.publish(n);
 }
 
int main (int argc, char **argv)

{
// Initialize the node, setup the NodeHandle for handling the communication with the ROS
//system
	ros::init(argc, argv, "Userinformation");
	ros::NodeHandle nh;
	
	
//connect the client and service here
	client1 =nh.serviceClient<second_assignment::Velocity>("Velocity", callback);	
	
	pub=nh.advertise<second_assignment::Vel>("Vel",10);
	
	
//use for spinning
	while(ros::ok){
	   callback();
	ros::spinOnce();
	}
	return 0;
}

