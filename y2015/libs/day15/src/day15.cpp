#include "D15_2015/day15.hpp"
#include <fstream>
#include <regex>

namespace d15 {
Ingredient::Ingredient() {}

Ingredient::Ingredient(const std::string* info) {
    name = info[0];
    capacity = std::stoi(info[1]);
    durability = std::stoi(info[2]);
    flavor = std::stoi(info[3]);
    texture = std::stoi(info[4]);
    calories = std::stoi(info[5]);
}

Ingredient getIngredient(const std::string &line) {
    std::string info[6];
    std::regex rgx(R"(^([A-Za-z]+): capacity (-?\d+), durability (-?\d+), )"
            R"(flavor (-?\d+), texture (-?\d+), calories (-?\d+))");
    std::smatch matches;
    std::regex_match(line, matches, rgx);
    for (int i = 0; i < 6; i++) {
        info[i] = matches[i + 1].str();
    }
    return {info};
}

int readFile(const std::string &file_name, Ingredient *ingredients) {
    std::ifstream file(file_name);
    std::string line;
    int n = 0;
    while (std::getline(file, line)) {
        ingredients[n] = getIngredient(line);
        n++;
    }
    return n;
}
}
