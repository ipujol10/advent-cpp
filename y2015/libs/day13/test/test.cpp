#include <gtest/gtest.h>
#include <D13_2015/day13.hpp>

namespace d13 {
TEST(GatheringTest, Constructor) {
    std::string file_name = "../libs/day13/test/files/test.txt";
    d13::Gathering g(file_name);
    std::map<std::set<std::string>, int> happiness = {
        {{"Alice", "Bob"}, 137},
        {{"Alice", "Carol"}, -141},
        {{"Alice", "David"}, 44},
        {{"Bob", "Carol"}, 53},
        {{"Bob", "David"}, -70},
        {{"Carol", "David"}, 96}
    };
    std::set<std::string> names = {"Alice", "Bob", "Carol", "David"};
    std::map<std::string, std::set<std::string>> neighbours = {
        {"Alice", {}},
        {"Bob", {}},
        {"Carol", {}},
        {"David", {}},
    };
    EXPECT_EQ(g.happiness, happiness);
    EXPECT_EQ(g.participants, names);
    EXPECT_EQ(g.neighbours, neighbours);
}

TEST(GatheringTest, GetMax) {
    std::string file_name = "../libs/day13/test/files/test.txt";
    d13::Gathering g(file_name);
    auto tup = g.getMax();
    EXPECT_EQ(tup.value, 137);
    std::set<std::string> pair = {"Alice", "Bob"};
    EXPECT_EQ(tup.pair, pair);
    std::map<std::set<std::string>, int> happiness = {
        {{"Alice", "Carol"}, -141},
        {{"Alice", "David"}, 44},
        {{"Bob", "Carol"}, 53},
        {{"Bob", "David"}, -70},
        {{"Carol", "David"}, 96}
    };
    EXPECT_EQ(g.happiness, happiness);
    tup = g.getMax();
    EXPECT_EQ(tup.value, 96);
    tup = g.getMax();
    EXPECT_EQ(tup.value, 53);
    tup = g.getMax();
    EXPECT_EQ(tup.value, 44);
}

TEST(GatheringTest, End) {
    std::string file_name = "../libs/day13/test/files/test.txt";
    d13::Gathering g(file_name);
    EXPECT_FALSE(g.end());
    g.neighbours = {
        {"Alice", {"a", ""}},
        {"Bob", {"a", ""}},
        {"Carol", {}},
        {"David", {}},
    };
    EXPECT_FALSE(g.end());
    g.neighbours = {
        {"Alice", {"a", ""}},
        {"Bob", {"a", ""}},
        {"Carol", {"a", ""}},
        {"David", {"a"}},
    };
    EXPECT_FALSE(g.end());
    g.neighbours = {
        {"Alice", {"a", ""}},
        {"Bob", {"a", ""}},
        {"Carol", {"a", ""}},
        {"David", {"a", ""}},
    };
    EXPECT_TRUE(g.end());
}

TEST(GatheringTest, AddPair) {
    std::string file_name = "../libs/day13/test/files/test.txt";
    d13::Gathering g(file_name);
    EXPECT_TRUE(g.addPair({"Alice", "Bob"}));
    std::map<std::string, std::set<std::string>> neighbours = {
        {"Alice", {"Bob"}},
        {"Bob", {"Alice"}},
        {"Carol", {}},
        {"David", {}},
    };
    EXPECT_EQ(g.neighbours, neighbours);
    EXPECT_TRUE(g.addPair({"Alice", "Bob"}));
    EXPECT_EQ(g.neighbours, neighbours);
    EXPECT_TRUE(g.addPair({"Alice", "David"}));
    neighbours = {
        {"Alice", {"Bob", "David"}},
        {"Bob", {"Alice"}},
        {"Carol", {}},
        {"David", {"Alice"}},
    };
    EXPECT_EQ(g.neighbours, neighbours);
    EXPECT_FALSE(g.addPair({"Alice", "Carol"}));
    EXPECT_EQ(g.neighbours, neighbours);
}
}
