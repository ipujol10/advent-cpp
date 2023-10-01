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
    this->substitutions = readData(file_name, obj);
    this->objective = obj;
}

int Generate::generate() {
    return this->generate("e");
}

int Generate::generate(const std::string& current) {
    if (current.length() > objective.length() || failed.count(current) != 0) {
        return -1;
    }
    if (current == objective) {
        return 0;
    }
    searching.insert(current);
    for (int i = 0; i < current.length(); i++) {
        for (const auto& pair : substitutions) {
            const auto& key = pair.first;
            if (!match(current, i, key)) {
                continue;
            }
            for (const auto& change : pair.second) {
                std::string replaced = current;
                replaced.replace(i, key.length(), change);
                if (searching.find(replaced) != searching.end()) {
                    continue;
                }
                int iter = generate(replaced);
                if (iter >= 0) {
                    return ++iter;
                }
                failed.insert(replaced);
            }
        }
    }
    failed.insert(current);
    return -1;
}
}
