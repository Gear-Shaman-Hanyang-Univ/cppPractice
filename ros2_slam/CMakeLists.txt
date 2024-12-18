cmake_minimum_required(VERSION 3.5)
project(ros2_slam)

# C++ 표준 설정
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ROS2 패키지 종속성
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

# 헤더 파일 경로
include_directories(include)

# LiDAR 퍼블리셔 빌드
add_executable(lidar_publisher src/lidar.cpp src/lidar_publisher.cpp)
ament_target_dependencies(lidar_publisher rclcpp std_msgs)

# Python 설치
install(
    DIRECTORY slam/
    DESTINATION lib/${PROJECT_NAME}
)

# C++ 실행 파일 설치
install(TARGETS
    lidar_publisher
    DESTINATION lib/${PROJECT_NAME}
)

ament_package()
