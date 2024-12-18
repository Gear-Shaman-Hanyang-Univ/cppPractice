#ifndef LIDAR_HPP
#define LIDAR_HPP

#include <vector>
#include "point.hpp"

class LiDAR {
private:
    double maxRange;

public:
    explicit LiDAR(double range);
    std::vector<Point> scan(const std::vector<Point>& obstacles, const Point& robotPos);
};

#endif