#include "D12_2015/day12.hpp"

namespace d12 {
    int sumNumbers(const std::string &line) {
        int sum = 0;
        std::string current = "";
        for (char ch : line) {
            if (ch == '-' || isNumber(ch)) {
                current += ch;
            } else if (current != "") {
                sum += std::stoi(current);
                current = "";
            }
        }
        return sum;
    }

    bool isNumber(char ch) {
        std::string base = "1234567890";
        return base.find(ch) != std::string::npos;
    }
}
