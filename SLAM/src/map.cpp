#include "map.hpp"
#include <iostream>

Map::Map(int width, int height) : width(width), height(height) {
    grid.resize(width, std::vector<char>(height, '.'));
}

void Map::addObstacle(int x, int y) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        grid[x][y] = '#';
    }
}

void Map::print() const {
    for (const auto& row : grid) {
        for (char cell : row) {
            std::cout << cell << ' ';
        }
        std::cout << '\n';
    }
}
