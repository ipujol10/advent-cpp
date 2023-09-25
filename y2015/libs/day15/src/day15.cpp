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

int getCapacity(const Ingredient *ingredients, int n, int *weights) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += weights[i] * ingredients[i].capacity;
    }
    return std::max(0, sum);
}

int getDurability(const Ingredient *ingredients, int n, int *weights) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += weights[i] * ingredients[i].durability;
    }
    return std::max(0, sum);
}

int getFlavor(const Ingredient *ingredients, int n, int *weights) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += weights[i] * ingredients[i].flavor;
    }
    return std::max(0, sum);
}

int getTexture(const Ingredient *ingredients, int n, int *weights) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += weights[i] * ingredients[i].texture;
    }
    return std::max(0, sum);
}

int getTotalScore(const Ingredient *ingredients, int n, int *weights) {
    return getCapacity(ingredients, n, weights)
        * getDurability(ingredients, n, weights)
        * getFlavor(ingredients, n, weights)
        * getTexture(ingredients, n, weights);
}

int bestScore(const Ingredient *ingredients, int n, int *weights, int k) {
    if (k == 0) {
        int sumWeights = 0;
        for (int i = 0; i < n; i++) {
            sumWeights += weights[i];
        }
        if (sumWeights != 100) {
            return -1;
        }
        return getTotalScore(ingredients, n, weights);
    }
    int currentWeight = 0;
    for (int i = k; i < n; i++) {
        currentWeight += weights[i - 1];
    }
    int maxScore = 0;
    int remainigWeight = 100 - currentWeight;
    for (int i = 0; i <= remainigWeight; i++) {
        weights[k - 1] = i;
        int result = bestScore(ingredients, n, weights, k - 1);
        maxScore = (result > maxScore) ? result : maxScore;
    }
    return maxScore;
}
}
