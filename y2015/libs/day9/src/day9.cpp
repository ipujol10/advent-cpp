#include "D9_2015/day9.hpp"
#include <algorithm>
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
    if (std::find(cities.begin(), cities.end(), cityA) == cities.end()) {
        cities.push_back(cityA);
    }
    cityB = matches[2];
    if (std::find(cities.begin(), cities.end(), cityB) == cities.end()) {
        cities.push_back(cityB);
    }
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

int Distances::factorial(int n) {
    if (n < 2) {
        return 1;
    }
    return n * factorial(n - 1);
}

void Distances::generatePermutations() {
    permutationRecursive(cities.size());
}

void Distances::permutationRecursive(int k) {
    if (k == 1) {
        permutations.insert(cities);
        return;
    }
    permutationRecursive(k - 1);

    for (int i = 0; i < k - 1; i++) {
        if (k%2 == 0) {
            swap(i, k - 1);
        } else {
            swap(0, k - 1);
        }
        permutationRecursive(k - 1);
    }
}

void Distances::swap(int idxA, int idxB) {
    const auto a = cities[idxA];
    cities[idxA] = cities[idxB];
    cities[idxB] = a;
}
}
