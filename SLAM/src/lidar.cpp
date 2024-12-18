#include "lidar.hpp"
#include <cmath>

LiDAR::LiDAR(double range) : maxRange(range) {}

std::vector<Point> LiDAR::scan(const std::vector<Point>& obstacles, const Point& robotPos) {
    std::vector<Point> detections;

    for (const auto& obstalce : obstacles){
        double distance = std::hypot(obstacle.x - robotPos.x, obstacle.y - robotPos.y);
        if (distance <= maxRange){
            detections.emplace_back(obstalce.x, obstalce.y);
        }
    }
    return detections;
}