#include "D19_2015/day19.hpp"
#include <gtest/gtest.h>

TEST(FunctionTest, ReadData) {
    std::string original;
    std::map<std::string, std::vector<std::string>> map = {
        {"H", {"HO", "OH"}},
        {"O", {"HH"}}
        };
    const std::string files = "../libs/day19/test/files/";
    EXPECT_EQ(d19::readData(files + "test1.txt", original), map);
    EXPECT_EQ(original, "HOH");
    EXPECT_EQ(d19::readData(files + "test2.txt", original), map);
    EXPECT_EQ(original, "HOHOHO");
}

TEST(FunctionTest, NumberVariants) {
    std::map<std::string, std::vector<std::string>> map = {
        {"H", {"HO", "OH"}},
        {"O", {"HH"}}
        };
    EXPECT_EQ(d19::numberVariants(map, "HOH"), 4);
    EXPECT_EQ(d19::numberVariants(map, "HOHOHO"), 7);
}

TEST(FunctionTest, Match) {
    EXPECT_TRUE(d19::match("HOH", 0, "H"));
    EXPECT_FALSE(d19::match("HOH", 1, "H"));
    EXPECT_TRUE(d19::match("HOH", 2, "H"));
    EXPECT_FALSE(d19::match("HOH", 0, "O"));
    EXPECT_TRUE(d19::match("HOH", 1, "O"));
    EXPECT_TRUE(d19::match("CRnCaCaCaSiRnBP", 3, "Ca"));
    EXPECT_FALSE(d19::match("CRnCaCaCaSiRnBP", 4, "Ca"));
    EXPECT_TRUE(d19::match("CRnCaCaCaSiRnBP", 5, "Ca"));
}
