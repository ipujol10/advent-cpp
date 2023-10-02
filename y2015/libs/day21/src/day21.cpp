#include "D21_2015/day21.hpp"
#include <regex>
#include <fstream>

namespace d21 {
Shop getShop() {
    const std::string file_name("../libs/day21/src/files/shop.txt");
    std::regex header(R"(^(\w+):\s+\w+\s+\w+\s+\w+$)");
    std::regex object(R"(^([\w\s\+123]+)\s+(\d+)\s+(\d)\s+(\d)\s*$)");
}
}
