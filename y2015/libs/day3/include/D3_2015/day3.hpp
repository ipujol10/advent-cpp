#ifndef DAY3_HPP
#define DAY3_HPP

#include <string>
#include <vector>

namespace d3 {
    class Point {
    private:
        int x;
        int y;
    public:
        Point(int x, int y);
        int getX();
        int getY();
        bool operator==(const Point& left);
    };

    class Grid {
    private:
        std::vector<Point> grid;
        int visited;
    public:
        Grid();
        bool beenVisited(const Point& p);
        int totalVisited();
        void performRide(const std::string& path);
    };
}

#endif //DAY3_HPP
