#include <gtest/gtest.h>
#include <D9_2015/day9.hpp>

namespace d9 {
TEST(DistancesTest, GenerateKey) {
    Distances d;
    EXPECT_EQ(d.generateKey("London to Dublin"), "Dublin-London");
    EXPECT_EQ(d.generateKey("London to Belfast"), "Belfast-London");
    EXPECT_EQ(d.generateKey("Dublin to Belfast"), "Belfast-Dublin");
}

TEST(DistancesTest, GenerateDistances) {
    std::map<std::string, int> map = {
        {"Dublin-London", 464},
        {"Belfast-London", 518},
        {"Belfast-Dublin", 141}};
    std::string file_name = "../libs/day9/test/files/test.txt";
    Distances d;
    d.generateDistances(file_name);
    EXPECT_EQ(d.distances, map);
    std::set<std::string> cities = {"London", "Dublin", "Belfast"};
    EXPECT_EQ(d.cities, cities);
}

TEST(DistancesTest, Permutations) {
    std::set<std::vector<std::string>> out;
}

TEST(DistancesTest, Factorial) {
    Distances d;
    EXPECT_EQ(d.factorial(3), 6);
    EXPECT_EQ(d.factorial(1), 1);
}
}
