#ifndef SLAM_SYSTEM_HPP
#define SLAM_SYSTEM_HPP

#include <memory>
#include "map.hpp"
#include "lidar.hpp"
#include "point.hpp"

class SLAMSystem {
private:
    std::shared_ptr<Map> map;
    std::unique_ptr<LiDAR> lidar;
    Point robotPosition;

public:
    SLAMSystem(std::shared_ptr<Map> map, std::unique_ptr<LiDAR> lidar);
    void moveRobot(double dx, double dy);
    void performSLAM(const std::vector<Point>& obstacles);
}

#endif