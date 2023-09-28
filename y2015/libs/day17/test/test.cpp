#include "D17_2015/day17.hpp"
#include <gtest/gtest.h>

TEST(FunctionTest, Ways) {
    int containers[] = {20, 15, 10, 5, 5};
    EXPECT_EQ(d17::ways(containers, 5, 25), 4);
}

TEST(FunctionTest, WaysMin) {
    int containers[] = {20, 15, 10, 5, 5};
    int min = d17::getMinContainers(containers, 5, 25);
    EXPECT_EQ(min, 2);
    EXPECT_EQ(d17::waysMin(containers, 5, 25, min), 3);
}
