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
