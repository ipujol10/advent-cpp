#include <gtest/gtest.h>
#include "D1_2015/day1.hpp"

TEST(D1_2015Test, Single) {
    EXPECT_EQ(d1::floor("("), 1); // )
    EXPECT_EQ(d1::floor(")"), -1);
    EXPECT_EQ(d1::floor(""), 0);
}
