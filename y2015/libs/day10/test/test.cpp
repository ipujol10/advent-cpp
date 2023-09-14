#include <gtest/gtest.h>
#include <D10_2015/day10.hpp>

TEST(FunctionTest, LookNSay) {
    EXPECT_EQ(d10::lookNsay("1"), "11");
    EXPECT_EQ(d10::lookNsay("11"), "21");
    EXPECT_EQ(d10::lookNsay("21"), "1211");
    EXPECT_EQ(d10::lookNsay("1211"), "111221");
    EXPECT_EQ(d10::lookNsay("111221"), "312211");
}

TEST(FunctionTest, Repeat) {
    EXPECT_EQ(d10::repeat("1", 5), "312211");
}
