#include "D19_2015/day19.hpp"
#include <fstream>
#include <regex>

namespace d19 {
std::map<std::string, std::vector<std::string>> readData(
        const std::string &file_name, std::string &original) {
    std::map<std::string, std::vector<std::string>> map;
    bool originalMolecule = false;
    std::ifstream file(file_name);
    std::string line;
    std::regex rgx(R"(^(\w+) => (\w+)$)");
    std::smatch matches;
    while (std::getline(file, line)) {
        if (originalMolecule) {
            original = line;
            break;
        }
        if (line == "") {
            originalMolecule = true;
            continue;
        }
        if (!std::regex_match(line, matches, rgx)) {
            throw -1;
        }
        std::string key = matches[1], value = matches[2];
        if (map.find(key) == map.end()) {
            map[key] = {value};
        } else {
            map[key].push_back(value);
        }
    }
    return map;
}
}
