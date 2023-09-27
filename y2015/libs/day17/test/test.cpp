#include "D17_2015/day17.hpp"
#include <gtest/gtest.h>

TEST(FunctionTest, Ways) {
    int containers[] = {20, 15, 10, 5, 5};
    EXPECT_EQ(d17::ways(containers, 5, 25), 4);
}
