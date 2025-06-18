cmake_minimum_required(VERSION 3.0.2)
project(motor_driver)

find_package(catkin REQUIRED COMPONENTS
  rospy
  std_msgs
  armcontrol_demo_pkg
)

catkin_package()

catkin_install_python(PROGRAMS
  scripts/motor_control_node.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
