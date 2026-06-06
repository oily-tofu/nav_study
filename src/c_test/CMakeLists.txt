cmake_minimum_required(VERSION 3.8)
project(c_test)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
# find_package(sensor_msgs REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(rosidl_default_generators REQUIRED)


#添加消息文件和依赖
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/Novel.msg"
  "action/Atest.action"
  #  DEPENDENCIES sensor_msgs
  DEPENDENCIES builtin_interfaces
)


add_executable(hello_node src/hello.cpp)
ament_target_dependencies(hello_node rclcpp)

add_executable(hello2_node src/hello_class.cpp)
ament_target_dependencies(hello2_node rclcpp)

add_executable(t_pub src/t_pub.cpp)
ament_target_dependencies(t_pub rclcpp std_msgs)

add_executable(t_pub_msg src/t_pub_msg.cpp)
ament_target_dependencies(t_pub_msg rclcpp std_msgs)

add_executable(t_action_s src/t_action_s.cpp)
ament_target_dependencies(t_action_s rclcpp std_msgs rclcpp_action)

add_executable(t_action_c src/t_action_c.cpp)
ament_target_dependencies(t_action_c rclcpp std_msgs rclcpp_action)

rosidl_get_typesupport_target(
  cpp_typesupport_target
  ${PROJECT_NAME}
  "rosidl_typesupport_cpp"
)
target_link_libraries(
  t_pub_msg
  ${cpp_typesupport_target}
)
target_link_libraries(
  t_action_s
  ${cpp_typesupport_target}
)

target_link_libraries(
  t_action_c
  ${cpp_typesupport_target}
)


install(TARGETS
  hello_node
  hello2_node
  t_pub
  t_pub_msg
  t_action_s
  t_action_c
  DESTINATION lib/${PROJECT_NAME}
)



if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
