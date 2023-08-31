#include "D1_2015/day1.hpp"

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
                    throw "Character not valid";
                    break;
            }
        }
        return f;
    }
}
