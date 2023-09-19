#ifndef DAY13_2015
#define DAY13_2015

#include <string>
#include <set>
#include <map>
#include <gtest/gtest.h>
#include <tuple>

namespace d13 {
struct Max {
    int value;
    std::set<std::string> pair;
};

class Gathering {
private:
    std::map<std::set<std::string>, int> happiness;
    std::set<std::string> participants;
    std::map<std::string, std::set<std::string>> neighbours;
    Max getMax();
public:
    Gathering(const std::string& file);
    FRIEND_TEST(GatheringTest, Constructor);
    FRIEND_TEST(GatheringTest, GetMax);
};
}

#endif // !DAY13_2015
