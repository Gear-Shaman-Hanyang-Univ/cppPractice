#ifndef LIDAR_HPP
#define LIDAR_HPP

#include <vector>
#include "point.hpp"

class LiDAR {
public:
    explicit LiDAR(double range);
    std::vector<Point> scan(const std::vector<Point>& obstacles, const Point& robotPos);

private:
    double maxRange;
};

#endif
