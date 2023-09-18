#include "D12_2015/day12.hpp"
#include <nlohmann/json.hpp>
#include <iostream>

using json = nlohmann::json;

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

    int sumNumbers(const std::string& line, const std::string& bad) {
        int sum = 0;
        json data = json::parse(line);
        bool isObject = data.is_object();
        for (auto el : data) {
            if (el == bad && isObject) {
                return 0;
            }
            if (el.is_number()) {
                sum += (int)el;
            } else if (el.is_object() || el.is_array()) {
                sum += sumNumbers(el.dump(), bad);
            }
        }
        return sum;
    }
}
