cmake_minimum_required(VERSION 3.8)
project(my_costmap)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(nav_msgs REQUIRED)

# 包含头文件目录
include_directories(
  include
)

# 创建膨胀节点库
add_library(inflator
  src/inflator.cpp
)

target_include_directories(inflator
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(inflator
  rclcpp::rclcpp
  ${nav_msgs_TARGETS}
)

# 创建可执行节点
add_executable(inflator_node
  src/inflator_node.cpp
)

target_include_directories(inflator_node
  PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(inflator_node
  inflator
  rclcpp::rclcpp
  ${nav_msgs_TARGETS}
)

# 安装
install(
  TARGETS
    inflator
    inflator_node
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION lib/${PROJECT_NAME}
)

install(
  DIRECTORY include/
  DESTINATION include
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()