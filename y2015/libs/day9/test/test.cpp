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
    std::vector<std::string> cities = {"London", "Dublin", "Belfast"};
    EXPECT_EQ(d.cities, cities);
}

TEST(DistancesTest, Permutations) {
    std::set<std::vector<std::string>> out = {
        {"Dublin", "London", "Belfast"},
        {"London", "Dublin", "Belfast"},
        {"London", "Belfast", "Dublin"},
        {"Dublin", "Belfast", "London"},
        {"Belfast", "Dublin", "London"},
        {"Belfast", "London", "Dublin"},
    };
    Distances d;
    std::string file_name = "../libs/day9/test/files/test.txt";
    d.generateDistances(file_name);
    d.generatePermutations();
    EXPECT_EQ(d.permutations, out);
}

TEST(DistancesTest, Factorial) {
    Distances d;
    EXPECT_EQ(d.factorial(3), 6);
    EXPECT_EQ(d.factorial(1), 1);
}

TEST(DistancesTest, Swap) {
    Distances d;
    d.cities = {"a", "b", "c"};
    d.swap(0, 1);
    std::vector<std::string> out1 = {"b", "a", "c"}, out2 = {"c", "a", "b"};
    EXPECT_EQ(d.cities, out1);
    d.swap(0, 2);
    EXPECT_EQ(d.cities, out2);
}
}
