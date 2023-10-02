#include "D20_2015/day20.hpp"
#include <gtest/gtest.h>

TEST(FunctionTest, PresentsHouse) {
    EXPECT_EQ(d20::presentsHouse(1), 10);
    EXPECT_EQ(d20::presentsHouse(2), 30);
    EXPECT_EQ(d20::presentsHouse(3), 40);
    EXPECT_EQ(d20::presentsHouse(4), 70);
    EXPECT_EQ(d20::presentsHouse(5), 60);
    EXPECT_EQ(d20::presentsHouse(6), 120);
    EXPECT_EQ(d20::presentsHouse(7), 80);
    EXPECT_EQ(d20::presentsHouse(8), 150);
    EXPECT_EQ(d20::presentsHouse(9), 130);
}

TEST(FunctionTest, FirstHouse) {
    EXPECT_EQ(d20::firstHouse(60), 4);
    EXPECT_EQ(d20::firstHouse(150), 8);
    EXPECT_EQ(d20::firstHouse(80), 6);
}
