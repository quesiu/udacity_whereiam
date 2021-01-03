# udacity_gochaseit
Git repository for **Project 2 - Go Chase It!**, part of [Robotics Software Engineer nanodegree](https://www.udacity.com/course/robotics-software-engineer--nd209).

## Description
In the Go Chase It! project, students are asked to define a URDF robot, place it into a 3D world and code functions in ROS flavored C++ to all the robot to chase a white ball when it is placed in the robot's camera field of view.

## Content
- **my_robot**
  - launch: scripts to launch the world when using `roslaunch` command
  - meshes: external 3D models; in this case, of a lidar
  - rviz: RViz configuration that can be loaded at launch
  - urdf: URDF definition of the robot model
  - worlds: 3D environments in which the robot runs
- **ball_chaser** 
  - launch: scripts to launch the main code when using `roslaunch` command
  - src: source code; both to handle robot movements and image_processing to detect a white ball 
  - srv: ROS services; in this case, to request robot to drive to a given target 
## Pre-requisites
This project requires a Linux machine with Gazebo and ROS (including catkin and RViz), as well as all of their dependencies.
Git is also recommended to clone this repository.

## Installation
Please follow the procedure below to be able to correctly build the project:
```
git clone https://github.com/quesiu/udacity_gochaseit.git
cd /change_to_your_local_path_where_this_repo_has_been_cloned/udacity_gochaseit
mkdir catkin_ws
mv Project\ 2/ catkin_ws/src
```

## Build
Do the following to build the project:
```
cd /change_to_your_local_path_where_this_repo_has_been_cloned/udacity_gochaseit/catkin_ws
catkin_make
```

## Usage
After project has been correctly built, open a first terminal and do the following:
```
cd /change_to_your_local_path_where_this_repo_has_been_cloned/udacity_gochaseit/catkin_ws
source devel/setup.bash
roslaunch my_robot world.launch
```
A Gazebo and RViz windows should open and you should be able to see the robot in a 3D world.
Then open a second terminal and do the following:
```
cd /change_to_your_local_path_where_this_repo_has_been_cloned/udacity_gochaseit/catkin_ws
source devel/setup.bash
roslaunch ball_chaser ball_chaser.launch
```
If you grab the white ball on the left side in Gazebo and place it in front of the robot, you should now see the robot moving towards the ball.

## Support
If you have some questions or need some support, please use the [Discussions](https://github.com/quesiu/udacity_gochaseit/discussions) section.

## License
GNU General Public License v3.0
