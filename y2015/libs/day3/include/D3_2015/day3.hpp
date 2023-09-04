#ifndef DAY3_HPP
#define DAY3_HPP

#include <string>
#include <set>
#include <gtest/gtest.h>

namespace d3 {
    class Point {
    private:
        int x;
        int y;
    public:
        Point(int x, int y);
        int getX() const;
        int getY() const;
        bool operator==(const Point& left) const;
        Point operator+(const Point& left) const;
    };

    class Grid {
    private:
        std::set<Point> grid;
        FRIEND_TEST(GridConstructorTest, Good);
    public:
        Grid();
        bool beenVisited(const Point& p);
        int totalVisited();
        void performRide(const std::string& path);
    };
}

#endif //DAY3_HPP
