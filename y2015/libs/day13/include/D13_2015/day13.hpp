#ifndef DAY13_2015
#define DAY13_2015

#include <string>
#include <set>
#include <vector>
#include <map>
#include <gtest/gtest.h>
#include <tuple>

namespace d13 {
class Gathering {
private:
    std::map<std::set<std::string>, int> happiness;
    std::vector<std::string> people;
    std::map<std::vector<std::string>, int> permutations;
    std::string head;
    void normalize(std::vector<std::string>& order);
    int getHead(std::vector<std::string>& order);
    void insert(const std::string& name);
public:
    Gathering(const std::string& file);
    std::optional<int> sitArround();
    FRIEND_TEST(GatheringTest, Constructor);
    FRIEND_TEST(GatheringTest, Normalize);
};
}

#endif // !DAY13_2015
