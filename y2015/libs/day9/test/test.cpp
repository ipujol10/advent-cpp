#include <gtest/gtest.h>
#include <D9_2015/day9.hpp>

namespace d9 {
TEST(DistancesTest, GenerateKey) {
    Distances d;
    EXPECT_EQ(d.generateKey("London to Dublin"), "Dublin-London");
    EXPECT_EQ(d.generateKey("London to Belfast"), "Belfast-London");
    EXPECT_EQ(d.generateKey("Dublin to Belfast"), "Belfast-Dublin");
}

TEST(DistancesTest, GenerateKey2) {
    Distances d;
    EXPECT_EQ(
            d.generateKey({"Dublin", "London", "Belfast"}),
            "Dublin->London->Belfast"
            );
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
    std::set<std::string> cities = {"London", "Dublin", "Belfast"}, other;
    for (const auto& city : d.cities) {
        other.insert(city);
    }
    EXPECT_EQ(other, cities);
}

TEST(DistancesTest, Permutations) {
    std::map<std::string, int> out = {
        {"Dublin->London->Belfast", 982},
        {"London->Dublin->Belfast", 605},
        {"London->Belfast->Dublin", 659},
        {"Dublin->Belfast->London", 659},
        {"Belfast->Dublin->London", 605},
        {"Belfast->London->Dublin", 982},
    };
    Distances d;
    std::string file_name = "../libs/day9/test/files/test.txt";
    d.generateDistances(file_name);
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

TEST(DistancesTest, TotalDistance) {
    Distances d;
    std::string file_name = "../libs/day9/test/files/test.txt";
    d.generateDistances(file_name);
    EXPECT_EQ(d.getTotalDistance({"Dublin", "London", "Belfast"}), 982);
    EXPECT_EQ(d.getTotalDistance({"London", "Dublin", "Belfast"}), 605);
    EXPECT_EQ(d.getTotalDistance({"London", "Belfast", "Dublin"}), 659);
    EXPECT_EQ(d.getTotalDistance({"Dublin", "Belfast", "London"}), 659);
    EXPECT_EQ(d.getTotalDistance({"Belfast", "Dublin", "London"}), 605);
    EXPECT_EQ(d.getTotalDistance({"Belfast", "London", "Dublin"}), 982);
}

TEST(DistancesTest, Shortest) {
    Distances d;
    std::string file_name = "../libs/day9/test/files/test.txt";
    d.generateDistances(file_name);
    EXPECT_EQ(d.getShortest(), 605);
}

TEST(DistancesTest, Longest) {
    Distances d;
    std::string file_name = "../libs/day9/test/files/test.txt";
    d.generateDistances(file_name);
    EXPECT_EQ(d.getLongest(), 982);
}
}
