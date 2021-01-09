# udacity_whereiam
Git repository for **Project 3 - Where Am I?**, part of [Robotics Software Engineer nanodegree](https://www.udacity.com/course/robotics-software-engineer--nd209).

## Description
In the Where Am I? project, students are asked to use ROS AMCL to localize a robot inside a Gazebo map with great accuracy, by following the next steps:
- Create a ROS package that launches a custom robot model in a custom Gazebo world
- Utilize the ROS AMCL package and the Tele-Operation / Navigation Stack to localize the robot
- Explore, add, and tune specific parameters corresponding to each package to achieve the best possible localization results

## Content
TODO
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
git clone https://github.com/udacity/pgm_map_creator.git
```

## Build
Do the following to build the project:
```
cd /<YOUR_LOCAL_PATH>/udacity_whereiam/catkin_ws
catkin_make
```

## Generate a PGM Map
As the PGM map is too heavy to be committed, please generate your own by following these two procedures:
```
cd /<YOUR_LOCAL_PATH>/udacity_whereiam/catkin_ws
source devel/setup.bash
gzserver src/pgm_map_creator/world/test_course.world
```

Open a second terminal and simply type:
`roslaunch pgm_map_creator request_publisher.launch`

Then copy the map:
`src/pgm_map_creator/maps/map.pgm src/my_robot/maps/map.pgm`

## Usage
TODO

## Support
If you have some questions or need some support, please use the [Discussions](https://github.com/quesiu/udacity_whereiam/discussions) section.

## License
GNU General Public License v3.0
