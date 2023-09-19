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
    bool end();
    bool addPair(const std::set<std::string>& pair);
    bool addNeighbour(const std::string& key, const std::string& value);
    void removePair(const std::set<std::string>& pair);
public:
    Gathering(const std::string& file);
    std::optional<int> sitArround();
    FRIEND_TEST(GatheringTest, Constructor);
    FRIEND_TEST(GatheringTest, GetMax);
    FRIEND_TEST(GatheringTest, End);
    FRIEND_TEST(GatheringTest, AddPair);
};
}

#endif // !DAY13_2015
