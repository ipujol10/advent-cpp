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
    void insert(const std::string& name);
    void generatePermutations();
    void generatePermutations(int k);
    bool existsOrder(const std::vector<std::string>& order);
    int getHappiness(const std::vector<std::string>& order);
    void swap(int idx1, int idx2);
public:
    Gathering(const std::string& file);
    void include(const std::string& name, int value);
    int sitArroundMax();
    FRIEND_TEST(GatheringTest, Constructor);
    FRIEND_TEST(GatheringTest, Normalize);
    FRIEND_TEST(GatheringTest, GetHappiness);
};
}

#endif // !DAY13_2015
