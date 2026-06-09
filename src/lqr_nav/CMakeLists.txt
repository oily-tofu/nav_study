cmake_minimum_required(VERSION 3.8)
project(lqr_nav)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# ===== C++ 标准 =====
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(visualization_msgs REQUIRED)
find_package(Eigen3 REQUIRED)

# ===== 公共头文件目录 =====
set(LQR_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

# ===== 库1: trajectory_manager =====
add_library(trajectory_manager
  src/trajectory_manager.cpp
)
target_include_directories(trajectory_manager
  PUBLIC
    $<BUILD_INTERFACE:${LQR_INCLUDE_DIR}>
    $<INSTALL_INTERFACE:include>
)
ament_target_dependencies(trajectory_manager
  rclcpp
  nav_msgs
  geometry_msgs
  visualization_msgs
  tf2_ros
  tf2_geometry_msgs
  Eigen3
)

# ===== 库2: lqr_solver =====
add_library(lqr_solver
  src/lqr_solver.cpp
)
target_include_directories(lqr_solver
  PUBLIC
    $<BUILD_INTERFACE:${LQR_INCLUDE_DIR}>
    $<INSTALL_INTERFACE:include>
)
ament_target_dependencies(lqr_solver
  rclcpp
  Eigen3
)

# ===== 库3: performance_analyzer =====
add_library(performance_analyzer
  src/performance_analyzer.cpp
)
target_include_directories(performance_analyzer
  PUBLIC
    $<BUILD_INTERFACE:${LQR_INCLUDE_DIR}>
    $<INSTALL_INTERFACE:include>
)
ament_target_dependencies(performance_analyzer
  rclcpp
  Eigen3
)

# ===== 可执行文件 =====
add_executable(lqr_tracking_node
  src/lqr_tracking_node.cpp
  src/lqr_controller_node.cpp
)
target_include_directories(lqr_tracking_node PRIVATE
  ${LQR_INCLUDE_DIR}
)
ament_target_dependencies(lqr_tracking_node
  rclcpp
  geometry_msgs
  nav_msgs
  tf2
  tf2_ros
  tf2_geometry_msgs
  visualization_msgs
  Eigen3
)
target_link_libraries(lqr_tracking_node
  trajectory_manager
  lqr_solver
  performance_analyzer
)

# ===== 安装 =====
install(
  TARGETS
    trajectory_manager
    lqr_solver
    performance_analyzer
  EXPORT ${PROJECT_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

install(
  TARGETS lqr_tracking_node
  DESTINATION lib/${PROJECT_NAME}
)

install(
  DIRECTORY include/
  DESTINATION include/${PROJECT_NAME}
)

install(
  DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()