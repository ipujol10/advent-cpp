#include <gtest/gtest.h>
#include <D9_2015/day9.hpp>

TEST(Ex1Test, GenerateKey) {
    EXPECT_EQ(d9::generateKey("London to Dublin"), "Dublin-London");
    EXPECT_EQ(d9::generateKey("London to Belfast"), "Belfast-London");
    EXPECT_EQ(d9::generateKey("Dublin to Belfast"), "Belfast-Dublin");
}

TEST(Ex1Test, GenerateDistances) {
    std::map<std::string, int> map = {
        {"Dublin-London", 464},
        {"Belfast-London", 518},
        {"Belfast-Dublin", 141}};
    std::string file_name = "../libs/day9/test/files/test.txt";
    auto out = d9::generateDistances(file_name);
    EXPECT_EQ(out, map);
}
