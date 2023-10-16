#pragma once

#include <vector>
#include <string>

namespace d24 {
std::vector<int> readFile(const std::string& file_name);
int quantumEntanglament(const std::vector<int>& group);
}
