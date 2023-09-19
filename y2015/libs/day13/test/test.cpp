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
}
}
