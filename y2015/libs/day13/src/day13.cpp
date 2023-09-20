#include "D13_2015/day13.hpp"
#include <algorithm>
#include <fstream>
#include <regex>

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
        insert(name1);
        insert(name2);
        key = {name1, name2};
        int v = std::stoi(value);
        if (sign == "lose") v *= -1;
        if (building.count(key)) {
            happiness[key] = v + building[key];
        } else {
            building[key] = v;
        }
    }
    head = *std::min_element(people.begin(), people.end());
    generatePermutations();
}

void Gathering::normalize(std::vector<std::string>& order) {
    if (order[1] < order.back()) {
        return;
    }
    std::vector<std::string> out = {head};
    for (int i = order.size() - 1; i > 0; i--) {
        out.push_back(order[i]);
    }
    order = out;
}

void Gathering::insert(const std::string& name) {
    if (std::find(people.begin(), people.end(), name) == people.end()) {
        people.push_back(name);
    }
}

void Gathering::generatePermutations() {
    generatePermutations(people.size());
}

void Gathering::generatePermutations(int k) {
    if (k == 1) {
        if (people[0] != head) {
            return;
        }
        std::vector<std::string> order = people;
        normalize(order);
        if (!existsOrder(order)) {
            permutations[order] = getHappiness(order);
        }
        return;
    }
    generatePermutations(k - 1);

    for (int i = 0; i < k - 1; i++) {
        if (k%2 == 0) {
            swap(i, k - 1);
        } else {
            swap(0, k - 1);
        }
        generatePermutations(k - 1);
    }
}

bool Gathering::existsOrder(const std::vector<std::string>& order) {
    return permutations.find(order) != permutations.end();
}

int Gathering::getHappiness(const std::vector<std::string>& order) {
    std::set<std::string> pair = {order[0], order.back()};
    int sum = happiness[pair];
    for (int i = 0; i < order.size() - 1; i++) {
        pair = {order[i], order[i + 1]};
        sum += happiness[pair];
    }
    return sum;
}

void Gathering::swap(int idx1, int idx2) {
    auto temp = people[idx1];
    people[idx1] = people[idx2];
    people[idx2] = temp;
}

int Gathering::sitArroundMax() {
    int max = -1;
    for (const auto& pair : permutations) {
        if (max == -1 || pair.second > max) {
            max = pair.second;
        }
    }
    return max;
}

void Gathering::include(const std::string& name, int value) {
    permutations.clear();
    for (const auto& el : people) {
        happiness[{name, el}] = value;
    }
    people.push_back(name);
    generatePermutations();
}
}
