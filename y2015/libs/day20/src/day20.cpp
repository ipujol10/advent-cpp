#include "D20_2015/day20.hpp"
#include <cmath>

namespace d20 {
int presentHouse(int num) {
    int result = 0;
    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            result += i;
        }
    }
    return result * 10;
}

int firstHouse(int presents) {
    int i = 1;
    while (presentHouse(i) < presents) {
        i++;
    }
    return i;
}
}
