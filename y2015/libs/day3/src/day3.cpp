#include "D3_2015/day3.hpp"

namespace d3 {
    Point::Point(int x, int y): x(x), y(y) {}

    int Point::getX() const { return x; }

    int Point::getY() const { return y; }

    bool Point::operator==(const Point& left) const {
        return this->x == left.getX() && this->y == left.getY();
    }

    Point Point::operator+(const Point& left) const {
        int nx = this->x + left.getX();
        int ny = this->y + left.getY();
        return {nx, ny};
    }

    bool Point::operator<(const Point& left) const {
        if (this->y < left.getY()) { return true; }
        if (this->y > left.getY()) { return false; }
        if (this->x < left.getX()) { return true; }
        return false;
    }

    Grid::Grid(): lastPoint({0, 0}), RIGHT({1, 0}), LEFT({-1, 0}),
        UP({0, 1}), DOWN({0, -1}) {
            grid.insert({0, 0});
        }

    bool Grid::beenVisited(const Point& p) const {
        return grid.find(p) != grid.end();
    }

    int Grid::totalVisited() const {
        return grid.size();
    }

    void Grid::performRide(const std::string& path) {
        lastPoint = {0, 0};
        grid = {{0, 0}};
        for (char dir : path) {
            switch (dir) {
                case '<':
                    lastPoint = lastPoint + LEFT;
                    break;
                case '>':
                    lastPoint = lastPoint + RIGHT;
                    break;
                case '^':
                    lastPoint = lastPoint + UP;
                    break;
                case 'v':
                    lastPoint = lastPoint + DOWN;
                    break;
            }
            grid.insert(lastPoint);
        }
    }

    void Grid::combineGrids(const Grid& left_grid) {
        this->grid.insert(left_grid.grid.begin(), left_grid.grid.end());
    }

    void split(const std::string &in, std::string &out1, std::string &out2) {
        out1 = "";
        out2 = "";
        bool first = true;
        for (char letter : in) {
            if (first) {
                first = false;
                out1.push_back(letter);
            } else {
                first = true;
                out2.push_back(letter);
            }
        }
    }
}
