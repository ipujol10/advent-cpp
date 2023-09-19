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
}

void Gathering::normalize(std::vector<std::string>& order) {
    int headIdx = getHead(order);
    std::vector<std::string> out;
    for (int i = headIdx; i < order.size(); i++) {
        if (i == headIdx) continue;
        out.push_back(order[i]);
    }
    for (int i = 0; i < headIdx; i++) {
        out.push_back(order[i]);
    }
    order = {head};
    if (out[0] > *out.end()) {
        std::reverse(out.begin(), out.end());
    }
    order.emplace_back(out);
}

int Gathering::getHead(std::vector<std::string>& order) {
    for (int i = 0; i < order.size(); i++) {
        if (order[i] == head) {
            return i;
        }
    }
    throw -1;
}

void Gathering::insert(const std::string& name) {
    if (std::find(people.begin(), people.end(), name) == people.end()) {
        people.push_back(name);
    }
}

std::optional<int> Gathering::sitArround() {
}
}
