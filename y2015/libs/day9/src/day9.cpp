#include "D9_2015/day9.hpp"
#include <regex>
#include <fstream>
#include <iostream>

namespace d9 {
std::string Distances::generateKey(const std::string &pair) {
    std::regex rgx("^([a-zA-Z]+) to ([a-zA-Z]+)$");
    std::smatch matches;
    std::string cityA, cityB;
    std::regex_match(pair, matches, rgx);
    cityA = matches[1];
    cities.insert(cityA);
    cityB = matches[2];
    cities.insert(cityB);
    if (cityB < cityA) {
        return cityB + "-" + cityA;
    }
    return cityA + "-" + cityB;
}

void Distances::generateDistances(const std::string &file_name) {
    std::regex rgx("^([a-zA-Z]+ to [a-zA-Z]+) = ([0-9]+)$");
    std::smatch matches;
    std::string line, key, value;
    std::ifstream file(file_name);
    while (std::getline(file, line)) {
        std::regex_match(line, matches, rgx);
        key = matches[1], value = matches[2];
        distances[generateKey(key)] = std::stoi(value);
    }
}
}
