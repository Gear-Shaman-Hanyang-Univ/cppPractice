#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
#include <random>

// Point 구조체: 좌표를 표현
struct Point {
    double x, y;
    Point(double x, double y) : x(x), y(y) {}
};

// 라이다 데이터 시뮬레이션 클래스
class LiDAR {
public:
    explicit LiDAR(double range) : maxRange(range) {
        std::cout << "LiDAR initialized with range: " << maxRange << " meters.\n";
    }

    // 환경 데이터를 기반으로 거리 측정 시뮬레이션
    std::vector<Point> scan(const std::vector<Point>& obstacles, const Point& robotPos) {
        std::vector<Point> detections;

        for (const auto& obstacle : obstacles) {
            double distance = std::hypot(obstacle.x - robotPos.x, obstacle.y - robotPos.y);
            if (distance <= maxRange) {
                detections.emplace_back(obstacle.x, obstacle.y);
            }
        }
        return detections;
    }

private:
    double maxRange;
};

// 2D 맵 클래스
class Map {
public:
    Map(int width, int height) : width(width), height(height) {
        grid.resize(width, std::vector<char>(height, '.'));
    }

    // 장애물 추가
    void addObstacle(int x, int y) {
        if (x >= 0 && x < width && y >= 0 && y < height) {
            grid[x][y] = '#';
        }
    }

    // 맵 출력
    void print() {
        for (const auto& row : grid) {
            for (char cell : row) {
                std::cout << cell << ' ';
            }
            std::cout << '\n';
        }
    }

private:
    int width, height;
    std::vector<std::vector<char>> grid;
};

// SLAM 시스템 클래스
class SLAMSystem {
public:
    SLAMSystem(std::shared_ptr<Map> map, std::unique_ptr<LiDAR> lidar)
        : map(std::move(map)), lidar(std::move(lidar)), robotPosition(5, 5) {}

    // 로봇 이동
    void moveRobot(double dx, double dy) {
        robotPosition.x += dx;
        robotPosition.y += dy;
        std::cout << "Robot moved to (" << robotPosition.x << ", " << robotPosition.y << ")\n";
    }

    // 라이다 스캔 및 맵 업데이트
    void performSLAM(const std::vector<Point>& obstacles) {
        std::vector<Point> detections = lidar->scan(obstacles, robotPosition);

        std::cout << "LiDAR detected " << detections.size() << " obstacles:\n";
        for (const auto& point : detections) {
            std::cout << " - Obstacle at (" << point.x << ", " << point.y << ")\n";
        }
    }

private:
    std::shared_ptr<Map> map;             // 맵 공유
    std::unique_ptr<LiDAR> lidar;         // 라이다 소유권 관리
    Point robotPosition;                  // 로봇 위치
};

// 메인 함수
int main() {
    // 맵과 장애물 생성
    auto map = std::make_shared<Map>(10, 10);
    map->addObstacle(3, 3);
    map->addObstacle(7, 8);
    map->addObstacle(6, 2);

    std::cout << "Initial Map:\n";
    map->print();

    // LiDAR와 SLAM 시스템 초기화
    auto lidar = std::make_unique<LiDAR>(5.0);
    SLAMSystem slam(map, std::move(lidar));

    // 로봇 이동 및 SLAM 수행
    std::vector<Point> obstacles = {{3, 3}, {7, 8}, {6, 2}};
    slam.performSLAM(obstacles);

    slam.moveRobot(1.0, 1.0);
    slam.performSLAM(obstacles);

    return 0;
}
