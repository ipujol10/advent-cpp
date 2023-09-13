#ifndef DAY9_HPP
#define DAY9_HPP

#include <string>
#include <map>
#include <set>
#include <tuple>
#include <vector>
#include <gtest/gtest.h>

namespace d9 {
class Distances {
private:
    std::map<std::string, int> distances;
    std::vector<std::string> cities;
    std::set<std::vector<std::string>> permutations;
    int factorial(int n);
    std::string generateKey(const std::string& pair);
    void generatePermutations();
    void permutationRecursive(int k);
    void swap(int idxA, int idxB);
    int getTotalDistance(const std::vector<std::string>& path);
public:
    void generateDistances(const std::string& file_name);
    int getShortest();
	FRIEND_TEST(DistancesTest, GenerateKey);
	FRIEND_TEST(DistancesTest, GenerateDistances);
	FRIEND_TEST(DistancesTest, Factorial);
	FRIEND_TEST(DistancesTest, Permutations);
	FRIEND_TEST(DistancesTest, Swap);
	FRIEND_TEST(DistancesTest, TotalDistance);
};
}

#endif // !DAY9_HPP
