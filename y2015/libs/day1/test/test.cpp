#include <gtest/gtest.h>
#include "D1_2015/day1.hpp"

TEST(FloorTest, Single) {
    EXPECT_EQ(d1::floor("("), 1); // )
    EXPECT_EQ(d1::floor(")"), -1);
    EXPECT_EQ(d1::floor(""), 0);
}

TEST(FloorTest, F0) {
    EXPECT_EQ(d1::floor("(())"), 0);
    EXPECT_EQ(d1::floor("()()"), 0);
}

TEST(FloorTest, F3) {
    EXPECT_EQ(d1::floor("((("), 3); // )))
    EXPECT_EQ(d1::floor("(()(()("), 3); // )))
    EXPECT_EQ(d1::floor("))((((("), 3); // )))
}

TEST(FloorTest, Fm1) {
    EXPECT_EQ(d1::floor("())"), -1);
    EXPECT_EQ(d1::floor("))("), -1);
}

TEST(FloorTest, Fm3) {
    EXPECT_EQ(d1::floor(")))"), -3);
    EXPECT_EQ(d1::floor(")())())"), -3);
}
