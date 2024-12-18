#include "slam_system.hpp"
#include <iostream>

SLAMSystem::SLAMSystem(std::shared_ptr<Map> map, std::unique_ptr<LiDAR> lidar)
    : map(std::move(map)), lidar(std::move(lidar)), robotPosition(5, 5) {}

void SLAMSystem::moveRobot(double dx, double dy) {
    robotPosition.x += dx;
    robotPosition.y += dy;
    std::cout << "Robot moved to (" << robotPosition.x << ", " << robotPosition.y << ")\n";
}

void SLAMSystem::performSLAM(const std::vector<Point>& obstacles) {
    auto detections = lidar->scan(obstacles, robotPosition);

    std::cout << "LiDAR detected " << detections.size() << " obstacles:\n";
    for (const auto& point : detections) {
        std::cout << " - Obstacle at (" << point.x << ", " << point.y << ")\n";
    }
}
