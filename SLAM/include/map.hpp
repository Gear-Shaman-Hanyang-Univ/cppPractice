#ifndef MAP_HPP
#define MAP_HPP

#include <vector>
class Map {
private:
    int width, height;
    std::vector<std::vector<char>> grid;

public:
    Map(int weight, int height);
    void addObstacle(int x, int y);
    void print() const;
}

#endif