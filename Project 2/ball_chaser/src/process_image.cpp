#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h"
#include <sensor_msgs/Image.h>

// Define a global client that can request services
ros::ServiceClient client;

// This function calls the command_robot service to drive the robot in the specified direction
void drive_robot(float lin_x, float ang_z)
{
	// DONE: Request a service and pass the velocities to it to drive the robot
	ROS_INFO_STREAM("Driving the robot towards the sphere");

	// Request both velocities as per function arguments
    ball_chaser::DriveToTarget srv;
    srv.request.linear_x = lin_x;
    srv.request.angular_z = ang_z;

    // Call the drive to target service and pass the requested velocities
    if (!client.call(srv))
        ROS_ERROR("Failed to call service safe_move");    
}

// This callback function continuously executes and reads the image data
void process_image_callback(const sensor_msgs::Image img)
{
	ROS_INFO_STREAM("Image callback");
    int white_pixel_rgb = 255;
	bool white_detected = false;
	int detected_pixel_row = 0;

    // DONE: Loop through each pixel in the image and check if there's a bright white one
	// Get camera informations
	int height = img.height;
	int width = img.width;
	int step = img.step;
	
	for (int y = 0; y < height ; y++){
		for (int x = 0; x < step ; x+=3){
			// Go through each elements of the image			
			if ((img.data[y*step+x] == white_pixel_rgb) 
			&& (img.data[y*step+x+1] == white_pixel_rgb) 
			&& (img.data[y*step+x+2] == white_pixel_rgb)){
				// White pixel detected
				ROS_INFO_STREAM("White pixel detected");
				white_detected = true;
				detected_pixel_row = (int)floor(x/3);
				break;
			}
		if (white_detected){
			break;
			}
		}
	}

    // DONE: Then, identify if this pixel falls in the left, mid, or right side of the image
	// White pixel
	if (white_detected){
		// Left
		if (detected_pixel_row < (int)floor(width/3)){
			drive_robot(0.0, 0.5);	
		}
		// Right
		else if (detected_pixel_row > width - (int)floor(width/3)){
			drive_robot(0.0, -0.5);
		}
		// Front
		else{
			drive_robot(0.5, 0.0);
		}
	// DONE: Depending on the white ball position, call the drive_bot function and pass velocities to it
	}
	// DONE: Request a stop when there's no white ball seen by the camera
	// No white pixel; stop
	else {
		ROS_INFO_STREAM("No white pixel");
		drive_robot(0.0, 0.0);
	}
    ROS_INFO_STREAM("Image callback done");
}

int main(int argc, char** argv)
{
    // Initialize the process_image node and create a handle to it
    ros::init(argc, argv, "process_image");
    ros::NodeHandle n;

    // Define a client service capable of requesting services from command_robot
    client = n.serviceClient<ball_chaser::DriveToTarget>("/ball_chaser/command_robot");

    // Subscribe to /camera/rgb/image_raw topic to read the image data inside the process_image_callback function
    ros::Subscriber sub1 = n.subscribe("/camera/rgb/image_raw", 10, process_image_callback);

    // Handle ROS communication events
    ros::spin();

    return 0;
}
