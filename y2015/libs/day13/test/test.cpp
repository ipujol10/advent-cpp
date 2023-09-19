#include <gtest/gtest.h>
#include <D13_2015/day13.hpp>

namespace d13 {
TEST(GatheringTest, COnstructor) {
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
    EXPECT_EQ(g.happiness, happiness);
    EXPECT_EQ(g.participants, names);
}
}
