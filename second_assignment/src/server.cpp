#include "ros/ros.h"
#include "second_assignment/Velocity.h"
#include "std_srvs/Empty.h"

std_srvs::Empty res_server;
float n = 0;

// developing the call back function to user to increase and descrease and reset the robot

bool Callback(second_assignment::Velocity::Request &req, second_assignment::Velocity::Response &res)
{
//fuction use for the increase ,decrease and reset the robot speed
//increase
    if(req.taken =='i'){ 
    n += 0.5;

    }
//decrease   
    if(req.taken =='d'){ 
    n -= 0.5;
  
    }
    
//reset   
    if(req.taken =='r'){ 
    ros::service::call("/reset_positions", res_server);
    }
    
    
    res.value=n;
    // printf is used for display the speed 
   printf("Value of speed:%f\n", n);
    return true;
}

int main(int argc, char **argv){

	// Initializing the node.

	ros::init(argc, argv, "server");
	ros::NodeHandle nh;

	// Declaring the service /accelarate.

	ros::ServiceServer service =  nh.advertiseService("/Velocity", Callback);

	// Spinning the callback function.
	
	ros::spin();
	return 0;
}
