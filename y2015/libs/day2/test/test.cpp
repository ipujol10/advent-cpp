#include <gtest/gtest.h>
#include <D2_2015/day2.hpp>

TEST(SurfaceTest, Good) {
    EXPECT_EQ(d2::surface(2, 3, 4), 52);
}

TEST(SmallesSurfaceTest, Good) {
    EXPECT_EQ(d2::smallestSurface(1, 1, 10), 1);
    EXPECT_EQ(d2::smallestSurface(10, 1, 1), 1);
}

TEST(ReadLineTest, Good) {
    std::array<int, 3> expected = {1, 2, 3};
    EXPECT_EQ(d2::readLine("1x2x3"), expected);
    expected = {2, 65, 2};
    EXPECT_EQ(d2::readLine("2x65x2"), expected);
}

TEST(RibbonTest, Good) {
    EXPECT_EQ(d2::ribbon(2, 3, 4), 34);
    EXPECT_EQ(d2::ribbon(1, 1, 10), 14);
}

TEST(SmallestPerimeterTest, Good) {
    std::array<int, 2> expected = {2, 3};
    EXPECT_EQ(d2::smallestPerimeter(2, 3, 4), expected);
    expected = {1, 1};
    EXPECT_EQ(d2::smallestPerimeter(1, 1, 10), expected);
}
