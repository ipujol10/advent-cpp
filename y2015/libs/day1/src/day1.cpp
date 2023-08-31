#include "D1_2015/day1.hpp"
#include <iostream>
#include <fstream>

namespace d1 {
    int floor(const std::string &trajectory) {
        int f = 0;

        for (char dir : trajectory) {
            switch (dir) {
                case '(':
                    f++;
                    break;
                case ')':
                    f--;
                    break;
                default:
                    std::cout << "Character not valid\n";
                    throw 10;
                    break;
            }
        }
        return f;
    }

    std::string read_input(const std::string &file_name) {
        if (file_name.length() < 5) {
            throw 20;
        }
        if (file_name.substr(file_name.find_last_of(".") + 1) != "txt") {
            throw 20;
        }

        std::string trajectory;

        std::ifstream file(file_name);
        if (file.good()) {
            std::getline(file, trajectory);
            file.close();
        } else {
            throw 20;
        }

        return trajectory;
    }

    int basement(const std::string &trajectory) {
        int fl = 0;
        int bas = 1;

        for (char dir : trajectory) {
            switch (dir) {
                case '(':
                    fl++;
                    break;
                case ')':
                    fl--;
                    break;
            }
            if (fl == -1) {
                return bas;
            }
            bas++;
        }
        return -1;
    }
}
