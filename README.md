# udacity_whereiam
Git repository for **Project 3 - Where Am I?**, part of [Robotics Software Engineer nanodegree](https://www.udacity.com/course/robotics-software-engineer--nd209).

## Description
In the Where Am I? project, students are asked to use ROS AMCL to localize a robot inside a Gazebo map with great accuracy, by following the next steps:
- Create a ROS package that launches a custom robot model in a custom Gazebo world
- Utilize the ROS AMCL package and the Tele-Operation / Navigation Stack to localize the robot
- Explore, add, and tune specific parameters corresponding to each package to achieve the best possible localization results

## Content
- my_robot: Main package containing gazebo world, robot definition and amcl filter
- pgm_map_creator: To create a pgm map of a gazebo world
- teleop_twist_keyboard: To manually drive the robot via teleop
- ball_chaser: leftover from Project 2:　Go Chase It! Can be used to make the robot follow a white ball, but not goal of this exercise.
## Pre-requisites
This project requires a Linux machine with Gazebo and ROS (including catkin and RViz), as well as all of their dependencies.
Following packages are also required: _ros-kinetic-navigation_, _ros-kinetic-map-server_, _ros-kinetic-move-base_ and _ros-kinetic-amcl_.
Git is also recommended to clone this repository.

## Installation
Please follow the procedure below to be able to correctly build the project:
```
git clone https://github.com/quesiu/udacity_whereiam.git
cd /<YOUR_LOCAL_PATH>/udacity_whereiam
mkdir catkin_ws
mv Project_3/ catkin_ws/src
cd catkin_ws/src
```

## Build
Do the following to build the project:
```
cd /<YOUR_LOCAL_PATH>/udacity_whereiam/catkin_ws
catkin_make
```

## Unzip PGM Map
As the PGM map is too heavy to be committed direclty, please unzip it using this method:
```
cd /<YOUR_LOCAL_PATH>/udacity_whereiam/catkin_ws/src/my_robot/maps
tar -xzf map.pgm.tar.gz
```
## Usage
Open a first terminal and do:
```
cd /<YOUR_LOCAL_PATH>/udacity_whereiam/catkin_ws
source devel/setup.bash
roslaunch my_robot world.launch
```
In a second terminal do the following*

```
cd /<YOUR_LOCAL_PATH>/udacity_whereiam/catkin_ws
source devel/setup.bash
roslaunch my_robot amcl.launch
```
Then there are two options to drive the robot around and make the AMCL algorithm converge/match.
### Using 2D Nav Goal in RViz
In RViz, select _2D Nav Goal_ and place the green arrow somewhere on the map. 
The robot should start to move towards it, and the map should start to match with the laser input.

### Using teleop
Open another terminal and input:
```
rosrun teleop_twist_keyboard teleop_twist_keyboard.py
```
Then in the same terminal use `i`, `j`, `l` and `k` keys to respectively go forward, turn left, turn right and stop. Speed can be adjusted with `q`.
As the robot is being moved around, the map should start to match with the laser input.

## Support
If you have some questions or need some support, please use the [Discussions](https://github.com/quesiu/udacity_whereiam/discussions) section.

## License
GNU General Public License v3.0
