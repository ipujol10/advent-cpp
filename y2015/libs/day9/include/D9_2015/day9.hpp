#ifndef DAY9_HPP
#define DAY9_HPP

#include <string>
#include <map>
#include <set>

namespace d9 {
    std::map<std::string, int> generateDistances(const std::string& file_name);
    std::set<std::string> getPerm(const std::map<std::string, int>& map);
    std::string generateKey(const std::string& pair);
}

#endif // !DAY9_HPP
