#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "ball_chaser/DriveToTarget.h"
#include "std_msgs/Float64.h"

//DONE: Include the ball_chaser "DriveToTarget" header file

// ROS::Publisher motor commands;
ros::Publisher motor_command_publisher;

// DONE: Create a handle_drive_request callback function that executes whenever a drive_bot service is requested
// This function should publish the requested linear x and angular velocities to the robot wheel joints
// After publishing the requested velocities, a message feedback should be returned with the requested wheel velocities
bool handle_drive_request(ball_chaser::DriveToTarget::Request& req,
    ball_chaser::DriveToTarget::Response& res)
{
	// Declare local variables for both linear and angular velocilities
	std_msgs::Float64 linear_x, angular_z;
	linear_x.data = (float)req.linear_x; 
	angular_z.data = (float)req.angular_z;
	
	// Notify that request has been input with given parameters
	ROS_INFO("DriveToTargetRequest received - j1:%1.2f, j2:%1.2f", linear_x.data, angular_z.data);
	
	// Create a motor_command object of type geometry_msgs::Twist
    geometry_msgs::Twist motor_command;
    // Set wheel velocities
    motor_command.linear.x = linear_x.data;
    motor_command.angular.z = angular_z.data;
    // Publish angles to drive the robot
    motor_command_publisher.publish(motor_command);
    
    // Return feedback message
    res.msg_feedback = "Motor commands set - linear x: " + std::to_string(linear_x.data) + " , angular z: " + std::to_string(angular_z.data);
    ROS_INFO_STREAM(res.msg_feedback);
	
	return true;
}

int main(int argc, char** argv)
{
    // Initialize a ROS node
    ros::init(argc, argv, "drive_bot");

    // Create a ROS NodeHandle object
    ros::NodeHandle n;

    // Inform ROS master that we will be publishing a message of type geometry_msgs::Twist on the robot actuation topic with a publishing queue size of 10
    motor_command_publisher = n.advertise<geometry_msgs::Twist>("/cmd_vel", 10);

    // DONE: Define a drive /ball_chaser/command_robot service with a handle_drive_request callback function
    ros::ServiceServer service = n.advertiseService("/ball_chaser/command_robot", handle_drive_request);
    ROS_INFO("Ready to send velocities commands");

    // DONE: Delete the loop, move the code to the inside of the callback function and make the necessary changes to publish the requested velocities instead of constant values

    // DONE: Handle ROS communication events
    ros::spin();

    return 0;
}
