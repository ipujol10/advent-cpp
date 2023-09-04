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
        bool operator<(const Point& left) const;
    };

    class Grid {
    private:
        std::set<Point> grid;
        Point lastPoint;
        const Point UP, DOWN, RIGHT, LEFT;
        FRIEND_TEST(GridTest, Constructor);
        FRIEND_TEST(GridTest, BeenVisited);
        FRIEND_TEST(GridTest, TotalVisited);
        FRIEND_TEST(GridTest, Combine);
    public:
        Grid();
        bool beenVisited(const Point& p) const;
        int totalVisited() const;
        void performRide(const std::string& path);
        void combineGrids(const Grid& left_grid);
    };

    void split(const std::string& in, std::string& out1, std::string& out2);
}

#endif //DAY3_HPP
