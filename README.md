# udacity_gochaseit
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
cd /change_to_your_local_path_where_this_repo_has_been_cloned/udacity_whereiam
mkdir catkin_ws
mv Project\ 3/ catkin_ws/src
```

## Build
Do the following to build the project:
```
cd /change_to_your_local_path_where_this_repo_has_been_cloned/udacity_whereiam/catkin_ws
catkin_make
```

## Usage
After project has been correctly built, open a first terminal and do the following:
```
cd /change_to_your_local_path_where_this_repo_has_been_cloned/udacity_whereiam/catkin_ws
source devel/setup.bash
roslaunch my_robot world.launch
```
TODO

## Support
If you have some questions or need some support, please use the [Discussions](https://github.com/quesiu/udacity_whereiam/discussions) section.

## License
GNU General Public License v3.0
