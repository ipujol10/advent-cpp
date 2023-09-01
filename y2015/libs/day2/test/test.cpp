#include <gtest/gtest.h>
#include <D2_2015/day2.hpp>

TEST(SurfaceTest, Good) {
    EXPECT_EQ(d2::surface(2, 3, 4), 52);
}

TEST(SmallesSurfaceTest, Good) {
    EXPECT_EQ(d2::smallestSurface(1, 1, 10), 1);
    EXPECT_EQ(d2::smallestSurface(10, 1, 1), 1);
}
