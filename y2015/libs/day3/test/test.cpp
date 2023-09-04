#include <gtest/gtest.h>
#include <D3_2015/day3.hpp>

TEST(PointTest, Constructor) {
    d3::Point p(0, 1);
    EXPECT_EQ(p.getX(), 0);
    EXPECT_EQ(p.getY(), 1);
}

TEST(PointTest, Compare) {
    d3::Point a(0, 0);
    d3::Point b(0, 0);
    d3::Point c(1, 0);
    EXPECT_TRUE(a == b);
    EXPECT_FALSE(a == c);
}

TEST(PointTest, Add) {
    d3::Point a(1, 2);
    d3::Point b(3, 4);
    d3::Point out(4, 6);
    EXPECT_EQ(a + b, out);
}

TEST(PointTest, LessThan) {
    d3::Point p1(0, 0);
    d3::Point p2(1, 0);
    d3::Point p3(-1, 0);
    d3::Point p4(0, 1);
    d3::Point p5(0, -1);
    d3::Point p6(1, 2);
    d3::Point p7(2, 1);

    EXPECT_FALSE(p1 < p1);
    EXPECT_TRUE(p1 < p2);
    EXPECT_TRUE(p3 < p1);
    EXPECT_TRUE(p1 < p4);
    EXPECT_FALSE(p1 < p5);
    EXPECT_TRUE(p2 < p4);
    EXPECT_TRUE(p5 < p3);
}

namespace d3 {
TEST(GridTest, Constructor) {
    Grid g;
    std::set<Point> s;
    s.insert({0, 0});
    EXPECT_EQ(g.grid, s);
}

TEST(GridTest, BeenVisited) {
    Grid g;
    Point p0(0, 0), p1(1, 2), p2(2, 2);

    EXPECT_TRUE(g.beenVisited(p0));
    EXPECT_FALSE(g.beenVisited(p1));
    EXPECT_FALSE(g.beenVisited(p2));

    g.grid.insert(p1);

    EXPECT_TRUE(g.beenVisited(p0));
    EXPECT_TRUE(g.beenVisited(p1));
    EXPECT_FALSE(g.beenVisited(p2));

    g.grid.insert(p1);
    EXPECT_TRUE(g.beenVisited(p0));
    EXPECT_TRUE(g.beenVisited(p1));
    EXPECT_FALSE(g.beenVisited(p2));

    g.grid.insert(p2);
    EXPECT_TRUE(g.beenVisited(p0));
    EXPECT_TRUE(g.beenVisited(p1));
    EXPECT_TRUE(g.beenVisited(p2));
}

TEST(GridTest, TotalVisited) {
    Grid g;
    EXPECT_EQ(g.totalVisited(), 1);

    g.grid.insert({1, 1});
    EXPECT_EQ(g.totalVisited(), 2);

    g.grid.insert({2, 2});
    EXPECT_EQ(g.totalVisited(), 3);
}

TEST(GridTest, PerformRide) {
    Point start(0, 0), up(0, 1), right(1, 0), diag(1, 1);
    Grid g;
    g.performRide(">");
    EXPECT_EQ(g.totalVisited(), 2);
    EXPECT_TRUE(g.beenVisited(start));
    EXPECT_TRUE(g.beenVisited(right));
    EXPECT_FALSE(g.beenVisited(up));
    EXPECT_FALSE(g.beenVisited(diag));

    g.performRide("^>v<");
    EXPECT_EQ(g.totalVisited(), 4);
    EXPECT_TRUE(g.beenVisited(start));
    EXPECT_TRUE(g.beenVisited(right));
    EXPECT_TRUE(g.beenVisited(up));
    EXPECT_TRUE(g.beenVisited(diag));

    g.performRide("^v^v^v^v^v");
    EXPECT_EQ(g.totalVisited(), 2);
    EXPECT_TRUE(g.beenVisited(start));
    EXPECT_FALSE(g.beenVisited(right));
    EXPECT_TRUE(g.beenVisited(up));
    EXPECT_FALSE(g.beenVisited(diag));
}
}
