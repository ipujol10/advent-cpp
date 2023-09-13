#ifndef DAY9_HPP
#define DAY9_HPP

#include <string>
#include <map>
#include <set>
#include <gtest/gtest.h>

namespace d9 {
class Distances {
private:
    std::map<std::string, int> distances;
    std::set<std::string> cities;
    std::string generateKey(const std::string& pair);
    void getPermutations();
public:
    void generateDistances(const std::string& file_name);
	FRIEND_TEST(DistancesTest, GenerateKey);
	FRIEND_TEST(DistancesTest, GenerateDistances);
};
}

#endif // !DAY9_HPP
