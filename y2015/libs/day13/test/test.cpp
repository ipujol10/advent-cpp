#include <gtest/gtest.h>
#include <D13_2015/day13.hpp>

namespace d13 {
TEST(GatheringTest, Constructor) {
    std::string file_name = "../libs/day13/test/files/test.txt";
    Gathering g(file_name);
    std::map<std::set<std::string>, int> happiness = {
        {{"Alice", "Bob"}, 137},
        {{"Alice", "Carol"}, -141},
        {{"Alice", "David"}, 44},
        {{"Bob", "Carol"}, 53},
        {{"Bob", "David"}, -70},
        {{"Carol", "David"}, 96}
    };
    EXPECT_EQ(g.happiness, happiness);
    EXPECT_EQ(g.head, "Alice");
}

TEST(GatheringTest, Normalize) {
    std::string file_name = "../libs/day13/test/files/test.txt";
    Gathering g(file_name);
    std::vector<std::string> order = {"Alice", "Bob", "Carol", "David"};
    std::vector<std::string> expect = {"Alice", "Bob", "Carol", "David"};
    g.normalize(order);
    EXPECT_EQ(order, expect);
    order = {"Alice", "David", "Carol", "Bob"};
    g.normalize(order);
    EXPECT_EQ(order, expect);
    expect = {"Alice", "Carol", "Bob", "David"};
    order = {"Alice", "David", "Bob", "Carol"};
    g.normalize(order);
    EXPECT_EQ(order, expect);
}

TEST(GatheringTest, GetHappiness) {
    std::string file_name = "../libs/day13/test/files/test.txt";
    Gathering g(file_name);
    std::vector<std::string> order = {"Alice", "Bob", "Carol", "David"};
    EXPECT_EQ(g.getHappiness(order), 330);
    order = {"Alice", "David", "Carol", "Bob"};
    EXPECT_EQ(g.getHappiness(order), 330);
}

TEST(GatheringTest, SitArround) {
    std::string file_name = "../libs/day13/test/files/test.txt";
    Gathering g(file_name);
    EXPECT_EQ(g.sitArroundMax(), 330);
}
}
