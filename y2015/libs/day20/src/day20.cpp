#include "D20_2015/day20.hpp"
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

int presentHouse(int num) {
    static std::map<int, int> memoize = {{1, 10}};
    if (memoize.find(num) != memoize.end()) {
        return memoize[num];
    }
    int result = num * 10 + 10;
    for (int i = num - 1; i > 1; i--) {
        if (num % i == 0) {
            result += i * 10;
            if (i != num / i) {
                result += presentHouse(num / i) - 10;
            }
            break;
        }
    }
    memoize[num] = result;
    return result;
}

int firstHouse(int presents) {
    int i = 1;
    while (presentHouse(i) < presents) {
        i++;
    }
    return i;
}
}
