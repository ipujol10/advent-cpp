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
}
