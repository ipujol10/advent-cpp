#include "utils/root.hpp"
#include <string>
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

namespace utils {
std::string getRootFolder() {
    bool found = false;
    std::string current_check(fs::current_path());
    std::cout << current_check << std::endl;
    std::string out;
    do {
        const auto path = fs::directory_iterator{current_check + "/" + out};
        for (const auto& el : path) {
            if (el.is_directory() && el.path().filename() == "src") {
                found = true;
                return out;
            }
        }
        out += "../";
    } while (!found);
    throw -1;
}
}
