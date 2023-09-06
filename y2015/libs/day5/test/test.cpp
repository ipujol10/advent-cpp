#include <gtest/gtest.h>
#include <D5_2015/day5.hpp>

TEST(ConditionTest, ThreeVowels) {
    EXPECT_TRUE(d5::threeVowels("ugknbfddgicrmopn"));
    EXPECT_TRUE(d5::threeVowels("aaa"));
    EXPECT_TRUE(d5::threeVowels("jchzalrnumimnmhp"));
    EXPECT_TRUE(d5::threeVowels("haegwjzuvuyypxyu"));
    EXPECT_FALSE(d5::threeVowels("dvszwmarrgswjxmb"));
}

TEST(ConditionTest, RepeatLetter) {
    EXPECT_TRUE(d5::repeatLetter("ugknbfddgicrmopn"));
    EXPECT_TRUE(d5::repeatLetter("aaa"));
    EXPECT_FALSE(d5::repeatLetter("jchzalrnumimnmhp"));
    EXPECT_TRUE(d5::repeatLetter("haegwjzuvuyypxyu"));
    EXPECT_TRUE(d5::repeatLetter("dvszwmarrgswjxmb"));
}

TEST(ConditionTest, NotBanned) {
    EXPECT_TRUE(d5::notBanned("ugknbfddgicrmopn"));
    EXPECT_TRUE(d5::notBanned("aaa"));
    EXPECT_TRUE(d5::notBanned("jchzalrnumimnmhp"));
    EXPECT_FALSE(d5::notBanned("haegwjzuvuyypxyu"));
    EXPECT_TRUE(d5::notBanned("dvszwmarrgswjxmb"));
}
