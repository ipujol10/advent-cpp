#include "D20_2015/day20.hpp"
#include <cmath>
#include <iostream>
#include <map>

namespace d20 {
void print(const std::map<int, int>& map) {
    std::cout << "{\n";
    for (const auto& pair : map) {
        std::cout << "{" << pair.first << ", " << pair.second << "},\n";
    }
    std::cout << "}\n";
}

int presentsHouse(int num) {
    int result = 0;
    for (int i = 1; i <= std::sqrt(num); i++) {
        if (num % i == 0) {
            result += i;
            if (num / i != i) {
                result += num / i;
            }
        }
    }
    return result * 10;
}

int presents50House(int num) {
    int result = 0;
    for (int i = 1; i <= std::sqrt(num); i++) {
        if (num % i == 0) {
            if (num / i <= 50) {
                result += i;
            }
            if (num / i != i && i <= 50) {
                result += num / i;
            }
        }
    }
    return result * 11;
}

int firstHouse(int presents) {
    int i = 1;
    while (presentsHouse(i) < presents) {
        i++;
    }
    return i;
}

int firstHouse2(int presents) {
    int i = 1;
    while (presents50House(i) < presents) {
        i++;
    }
    return i;
}
}
