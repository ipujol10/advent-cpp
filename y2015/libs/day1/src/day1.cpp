#include "D1_2015/day1.hpp"
#include <iostream>

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
}
