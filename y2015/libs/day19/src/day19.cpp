#include "D19_2015/day19.hpp"
#include <fstream>
#include <regex>
#include <set>

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

int numberVariants(
        const std::map<std::string, std::vector<std::string>> &substitutions,
        const std::string &original) {
    std::set<std::string> newMolecules;
    for (int i = 0; i < original.length(); i++) {
        for (const auto& pair : substitutions) {
            auto key = pair.first;
            if (!match(original, i, key)) {
                continue;
            }
            for (const auto& replace : pair.second) {
                std::string replaced = original;
                replaced.replace(i, key.length(), replace);
                newMolecules.insert(replaced);
            }
        }
    }
    return newMolecules.size();
}

bool match(const std::string &input, int idx, const std::string &tmplt) {
    if (tmplt.length() + idx > input.length()) {
        return false;
    }
    for (int i = 0; i < tmplt.length(); i++) {
        if (input[idx + i] != tmplt[i]) {
            return false;
        }
    }
    return true;
}

int generate(const std::string &objective, const std::map<std::string,
        std::vector<std::string>> &substitutions) {
    return generate(objective, substitutions, "e");
}

int generate(const std::string &objective, const std::map<std::string,
        std::vector<std::string>> &substitutions,
        const std::string& current) {
    if (current.length() > objective.length()) {
        return -1;
    }
    if (current == objective) {
        return 0;
    }
    for (int i = 0; i < current.length(); i++) {
        for (const auto& pair : substitutions) {
            const auto& key = pair.first;
            if (!match(current, i, key)) {
                continue;
            }
            for (const auto& replace : pair.second) {
                std::string replaced = current;
                replaced.replace(i, key.length(), replace);
                int iter = generate(objective, substitutions, replaced);
                if (iter >= 0) {
                    return ++iter;
                }
            }
        }
    }
    return -1;
}

Generate::Generate(const std::string& file_name) {
    std::string obj;
    auto map = readData(file_name, obj);
    for (const auto& pair : map) {
        for (const auto& v : pair.second) {
            this->substitutions.push_back({v, pair.first});
        }
    }
    std::sort(substitutions.begin(), substitutions.end(), sortAlgorithm);
    this->objective = obj;
}

bool sortAlgorithm(const Subs s1, const Subs s2) {
    return s1.from.length() > s2.from.length();
}

int Generate::generate() {
    std::string variant = objective;
    int steps = 0;
    while(variant != "e") {
        for (const auto& sub : substitutions) {
            int i = exists(variant, sub.from);
            if (i >= 0) {
                variant.replace(i, sub.from.length(), sub.to);
                steps++;
                break;
            }
        }
    }
    return steps;
}

int exists(const std::string &full, const std::string &snip) {
    for (int i = 0; i < full.length() - snip.length() + 1; i++) {
        if (full.at(i) == snip.at(0)) {
            if (match(full, i, snip)) {
                return i;
            }
        }
    }
    return -1;
}
}
