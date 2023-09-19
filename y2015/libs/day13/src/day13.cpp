#include "D13_2015/day13.hpp"
#include <fstream>
#include <regex>
#include <iostream>

namespace d13 {
Gathering::Gathering(const std::string& file_name) {
    std::string line;
    std::ifstream file(file_name);
    std::regex rgx(R"(^([A-Za-z]+) would (gain|lose) ([0-9]+) happiness )"
            R"(units by sitting next to ([A-Za-z]+)\.$)");
    std::smatch matches;
    std::string name1, name2, sign, value;
    std::set<std::string> key;
    std::map<std::set<std::string>, int> building;
    while (std::getline(file, line)) {
        std::regex_match(line, matches, rgx);
        name1 = matches[1];
        name2 = matches[4];
        sign = matches[2];
        value = matches[3];
        participants.insert(name1);
        participants.insert(name2);
        key = {name1, name2};
        int v = std::stoi(value);
        if (sign == "lose") v *= -1;
        if (building.count(key)) {
            happiness[key] = v + building[key];
        } else {
            building[key] = v;
        }
    }
}
}
