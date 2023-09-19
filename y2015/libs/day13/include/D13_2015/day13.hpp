#ifndef DAY13_2015
#define DAY13_2015

#include <string>
#include <set>
#include <map>
#include <gtest/gtest.h>

namespace d13 {
class Gathering {
private:
    std::map<std::set<std::string>, int> happiness;
    std::set<std::string> participants;
public:
    Gathering(const std::string& file);
    FRIEND_TEST(GatheringTest, COnstructor);
};
}

#endif // !DAY13_2015
