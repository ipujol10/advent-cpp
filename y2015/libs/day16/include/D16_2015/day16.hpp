#ifndef DAY16_2015
#define DAY16_2015

#include <string>
#include <map>

namespace d16 {
std::map<std::string, int> getOutputData();
int auntNumber(const std::string& file_name);
int auntNumberRange(const std::string& file_name);
bool failConditions(const std::string& key, int value, int realValue);
}

#endif // !DAY16_2015
