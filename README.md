# _**RT1-Assignment02**_
The Assignment is given by Professor Carmine Department of robotics Engineering University of Genoa. 

# Assignment Description :memo:
The Assignment is based on ROS There is some specific task that completed in this assignment the assignment is depend on robot. The robot move around a circuit. Here we can use ROS for controlling the robot have ability a laser scaneer and we can use some node to increase and decrease the speed of the robot and reset the position of robot this all above specific task is done  in C++

**How to Run Assignemnt** 


First step is run the master node using the comand 

`roscore &`

Second setp is run the stageros node using this commmand 

`rosrun stage_ros stageros $(rospack find second_assignment)/world/my_world.world`

Third Step is run the robot moving node with this command

`rosrun second_assignment robot_node`

fourth Step is run the server_node with this command

` rosrun second_assignment server_node`

Last Step is run the Userinformation_node with this command

` rosrun second_assignment userinformation_node`

## ASSIGNMENT ESSENTIALS

The blue dot robot moving in the circuit There are three way to completed this Process

1 Robot_node 

2 Server_node is create to increase, decrease and reset the position of robot

3 UserInfromation_node that ask the user to provide the information


![Screenshot from 2022-01-04 01-04-30](https://user-images.githubusercontent.com/91262613/147993378-9e100044-d4fe-4ab6-8038-87eb650bb9ca.png)

# Detailed view of this Program
The first step is to controlling the robot there is some intially checking processing. Behind the Enviorment there is some task running it checked by using shell. first started the enviorment and then type the`rostopic list` found the some structure of each node.for me /base_scan and /cmd_vel which proivde me data of the enviorment for more information that i type `rostopic info /base_scan` that show me the type sensor_msgs/LaserScan  and  clear show me that its a PUBLISHER and then checking the structure of the command i type `rosmsg show sensor_msgs/LaserScan`that provide me all detais of structure but for me float32[] ranges is very essentials and for the details of /cmd_vel that i type `rostopic info /cmd_vel ` that show me the type of geometry_msgs/Twist and it clealry show me that its SUBSCRIBERS and for more information i checked `rosmsg show geometry_msgs/Twist`and it shw me linear and angular velocity can depend on x,y,z axes
 `![Screenshot from 2022-01-04 02-19-34](https://user-images.githubusercontent.com/91262613/147997664-6481dbdf-f321-4324-8600-3e1bf8729e6b.png)

# logic and coding

**robot_node**

The robot_node.cpp has completed some task first move the robot in the enviorment and second chnages the velocity of robot

**Flow chart**

![Screenshot from 2022-01-05 19-23-20](https://user-images.githubusercontent.com/91262613/148269028-c2a77c54-ad18-417a-a72b-9457e102ce5c.png)


**Server_node**

The server node is used to increase,decrease and reset the robot position

  - I is used for increase the robot speed
  - D is used for decrease the robot speed
  - r is used for reset the robot postion

**Userinformation_node**

The Userinformation node is get response from user and sent ot the server and chnage speed of the the robot

# RQT_GRAPH!

![Rqt_graph](https://user-images.githubusercontent.com/91262613/148270861-13d5619d-3970-433a-a320-777c0e694192.png)

### conculsion

The work overall satisfied me especially because this is the first real kind of project I've ever approached with ROS. I understood the potentional of this tool and what can be easily created with it. To conclude the communication of the nodes,

### possible improvements 

First of all the algorithm managing the direction and speed of the robot can be improved because, as you can see when running, the robot has difficult when turning in the circuit.

Second, the UI interface has simple outputs and visuals for the user. If the UI node had more aesthetic values it can be easier to use and appreciatable.
