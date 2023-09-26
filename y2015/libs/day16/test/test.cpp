#include "D16_2015/day16.hpp"
#include <gtest/gtest.h>

TEST(FunctionTest, Output) {
    std::map<std::string, int> out = {
		{"children", 3},
		{"cats", 7},
		{"samoyeds", 2},
		{"pomeranians", 3},
		{"akitas", 0},
		{"vizslas", 0},
		{"goldfish", 5},
		{"trees", 3},
		{"cars", 2},
		{"perfumes", 1},
    };
    EXPECT_EQ(d16::getOutputData(), out);
}
