#ifndef DAY19_2015
#define DAY19_2015

#include <map>
#include <string>
#include <vector>

namespace d19 {
std::map<std::string, std::vector<std::string>> readData(
        const std::string& file_name, std::string& original);
int numberVariants(
        const std::map<std::string, std::vector<std::string>>& substitutions,
        const std::string& original);
/* @param input string where to look
 * @param idx the position where to look
 * @param tmplt the templete where to match against
 */
bool match(const std::string& input, int idx, const std::string& tmplt);
}

#endif // !DAY19_2015
