#include "D16_2015/day16.hpp"
#include <fstream>
#include <regex>

namespace d16 {
std::map<std::string, int> getOutputData() {
    const std::string file_name = "../libs/day16/src/output.txt";
    std::ifstream file(file_name);
    std::string line;
    std::regex rgx(R"(^(\w+): (\d+)$)");
    std::smatch matches;

    std::map<std::string, int> map;

    while (std::getline(file, line)) {
        std::regex_match(line, matches, rgx);
        map[matches[1].str()] = std::stoi(matches[2].str());
    }
    return map;
}

int auntNumber(const std::string &file_name) {
    auto real = getOutputData();
    std::ifstream file(file_name);
    std::string line;
    std::regex rgx(R"(^Sue (\d+): (\w+): (\d+), (\w+): (\d+), (\w+): (\d+))");
    std::smatch matches;

    while (std::getline(file, line)) {
        bool possible = true;
        std::regex_match(line, matches, rgx);
        for (int i = 2; i < 8; i += 2) {
            auto key = matches[i].str();
            int value = std::stoi(matches[i + 1].str());
            if (real[key] != value) {
                possible = false;
                break;
            }
        }
        if (possible) {
            return std::stoi(matches[1].str());
        }
    }
    throw -1;
}

int auntNumberRange(const std::string &file_name) {
    auto real = getOutputData();
    std::ifstream file(file_name);
    std::string line;
    std::regex rgx(R"(^Sue (\d+): (\w+): (\d+), (\w+): (\d+), (\w+): (\d+))");
    std::smatch matches;

    while (std::getline(file, line)) {
        bool possible = true;
        std::regex_match(line, matches, rgx);
        for (int i = 2; i < 8; i += 2) {
            auto key = matches[i].str();
            int value = std::stoi(matches[i + 1].str());
            int realV = real[key];
            if (failConditions(key, value, realV)) {
                possible = false;
                break;
            }
        }
        if (possible) {
            return std::stoi(matches[1].str());
        }
    }
    throw -1;
}

bool failConditions(const std::string &key, int value, int realValue) {
    if (key == "cats" || key == "trees") {
        return !(value > realValue);
    }
    if (key == "pomeranians" || key == "goldfish") {
        return !(value < realValue);
    }
    return  value != realValue;
}
}
