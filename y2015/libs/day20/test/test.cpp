#include "D20_2015/day20.hpp"
#include <gtest/gtest.h>

TEST(FunctionTest, PresentsHouse) {
    EXPECT_EQ(d20::presentHouse(1), 10);
    EXPECT_EQ(d20::presentHouse(2), 30);
	EXPECT_EQ(d20::presentHouse(3), 40);
	EXPECT_EQ(d20::presentHouse(4), 70);
	EXPECT_EQ(d20::presentHouse(5), 60);
	EXPECT_EQ(d20::presentHouse(6), 120);
	EXPECT_EQ(d20::presentHouse(7), 80);
	EXPECT_EQ(d20::presentHouse(8), 150);
	EXPECT_EQ(d20::presentHouse(9), 130);
}

TEST(FunctionTest, FirstHouse) {
    EXPECT_EQ(d20::firstHouse(60), 4);
    EXPECT_EQ(d20::firstHouse(150), 8);
    EXPECT_EQ(d20::firstHouse(80), 6);
}
