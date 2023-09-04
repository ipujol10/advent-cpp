#include <gtest/gtest.h>
#include <D3_2015/day3.hpp>

TEST(PointCreationTest, Good) {
    d3::Point p(0, 1);
    EXPECT_EQ(p.getX(), 0);
    EXPECT_EQ(p.getY(), 1);
}

TEST(PointCompareTest, Good) {
    d3::Point a(0, 0);
    d3::Point b(0, 0);
    d3::Point c(1, 0);
    EXPECT_TRUE(a == b);
    EXPECT_FALSE(a == c);
}

TEST(PointAddTest, Good) {
    d3::Point a(1, 2);
    d3::Point b(3, 4);
    d3::Point out(4, 6);
    EXPECT_EQ(a + b, out);
}

namespace d3 {
TEST(GridConstructorTest, Good) {
    d3::Grid g;
    // std::set<d3::Point> s({0, 0});
    std::set<Point> s;
    Point p(0, 0);
    s.insert(p);
    // EXPECT_EQ(g.grid, s);
}
}
