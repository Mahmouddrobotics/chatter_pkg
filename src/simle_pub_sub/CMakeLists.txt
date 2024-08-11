cmake_minimum_required(VERSION 3.0.2)
project(simle_pub_sub)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

## Declare ROS messages, services and actions (none in this case)

## Declare ROS dynamic reconfigure parameters (none in this case)

###################################
## catkin specific configuration ##
###################################
catkin_package(
  CATKIN_DEPENDS roscpp std_msgs
)

###########
## Build ##
###########

## Specify additional locations of header files
include_directories(
  ${catkin_INCLUDE_DIRS}
)

## Declare a C++ executable
add_executable(talker_node src/talker.cpp)
target_link_libraries(talker_node ${catkin_LIBRARIES})

add_executable(int_node src/int_node.cpp)
target_link_libraries(int_node ${catkin_LIBRARIES})

add_executable(listener src/listener.cpp)
target_link_libraries(listener ${catkin_LIBRARIES})

add_executable(sub_int src/sub_int.cpp)
target_link_libraries(sub_int ${catkin_LIBRARIES})

#############
## Install ##
#############

## Mark executables for installation
install(TARGETS talker_node int_node listener sub_int
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

#############
## Testing ##
#############

## Add gtest based cpp test target and link libraries (none in this case)
## Add folders to be run by python nosetests (none in this case)
