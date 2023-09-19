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
    std::vector<std::string> names = {"Alice", "Bob", "Carol", "David"};
    EXPECT_EQ(g.happiness, happiness);
    EXPECT_EQ(g.people, names);
    EXPECT_EQ(g.head, "Alice");
}

TEST(GatheringTest, Normalize) {
    std::string file_name = "../libs/day13/test/files/test.txt";
    Gathering g(file_name);
    std::vector<std::string> order = {"Alice", "Bob", "Carol", "David"};
    std::vector<std::string> expect = {"Alice", "Bob", "Carol", "David"};
    g.normalize(order);
    EXPECT_EQ(order, expect);
    order = {"Bob", "Carol", "David", "Alice"};
    g.normalize(order);
    EXPECT_EQ(order, expect);
    order = {"David", "Carol", "Bob", "Alice"};
    g.normalize(order);
    EXPECT_EQ(order, expect);
};

TEST(GatheringTest, SitArround) {
//    std::string file_name = "../libs/day13/test/files/test.txt";
//    Gathering g(file_name);
//    auto h = g.sitArround();
//    ASSERT_TRUE(h);
//    EXPECT_EQ(h.value(), 330);
}
}
