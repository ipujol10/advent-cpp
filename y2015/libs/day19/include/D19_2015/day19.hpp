#ifndef DAY19_2015
#define DAY19_2015

#include <map>
#include <string>
#include <vector>
#include <set>

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
int generate(const std::string& objective,
        const std::map<std::string, std::vector<std::string>>& substitutions);
int generate(const std::string& objective,
        const std::map<std::string, std::vector<std::string>>& substitutions,
        const std::string& current);

struct Subs {
    std::string from, to;
};

bool sortAlgorithm(const Subs s1, const Subs s2);
int exists(const std::string& full, const std::string& snip);

class Generate {
private:
    std::vector<Subs> substitutions;
    std::string objective;
public:
    Generate(const std::string& file_name);
    int generate();
};
}

#endif // !DAY19_2015
