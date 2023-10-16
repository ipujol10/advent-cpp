#include "D24_2015/day24.hpp"
#include <fstream>

namespace d24 {
std::vector<int> readFile(const std::string &file_name) {
    std::ifstream file(file_name);
    std::string line;
    std::vector<int> data;
    while (std::getline(file, line)) {
        data.push_back(std::stoi(line));
    }
    return data;
}

int quantumEntanglament(const std::vector<int> &group) {
    int ent = 1;
    for (const int num : group) {
        ent *= num;
    }
    return ent;
}
}
