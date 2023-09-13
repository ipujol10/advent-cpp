#include "D9_2015/day9.hpp"
#include <regex>
#include <fstream>
#include <iostream>

namespace d9 {
    std::string generateKey(const std::string &pair) {
        std::regex rgx("^([a-zA-Z]+) to ([a-zA-Z]+)$");
        std::smatch matches;
        std::string cityA, cityB;
        std::regex_match(pair, matches, rgx);
        cityA = matches[1];
        cityB = matches[2];
        if (cityB < cityA) {
            return cityB + "-" + cityA;
        }
        return cityA + "-" + cityB;
    }

    std::map<std::string, int> generateDistances(const std::string &file_name) {
        std::regex rgx("^([a-zA-Z]+ to [a-zA-Z]+) = ([0-9]+)$");
        std::smatch matches;
        std::string line, key, value;
        std::ifstream file(file_name);
        std::map<std::string, int> map;
        while (std::getline(file, line)) {
            std::regex_match(line, matches, rgx);
            key = matches[1], value = matches[2];
            map[generateKey(key)] = std::stoi(value);
        }
        return map;
    }
}
