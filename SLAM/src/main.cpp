#include <memory>
#include "map.hpp"
#include "lidar.hpp"
#include "slam_system.hpp"

int main() {
    auto map = std::make_shared<Map>(10, 10);
    map->addObstacle(3, 3);
    map->addObstacle(7, 8);
    map->addObstacle(6, 2);

    std::cout << "Initial Map:\n";
    map->print();

    auto lidar = std::make_unique<LiDAR>(5.0);
    SLAMSystem slam(map, std::move(lidar));

    std::vector<Point> obstacles = {{3, 3}, {7, 8}, {6, 2}};
    slam.performSLAM(obstacles);

    slam.moveRobot(1.0, 1.0);
    slam.performSLAM(obstacles);

    return 0;
}
