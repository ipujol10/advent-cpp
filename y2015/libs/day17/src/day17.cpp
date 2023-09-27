#include "D17_2015/day17.hpp"
#include <fstream>

namespace d17 {
int ways(int* containers, int n, int goal) {
    return ways(containers, n, goal, 0, 0);
}

int ways(int* containers, int n, int goal, int sum, int k) {
    if (k >= n || sum > goal) {
        return 0;
    }
    int newWays = 0;
    for (int i = k; i < n; i++) {
        int newSum = sum + containers[i];
        if (newSum == goal) {
            newWays++;
        } else {
            newWays += ways(containers, n, goal, newSum, i + 1);
        }
    }
    return newWays;
}

int getData(const std::string &file_name, int *containers) {
    std::ifstream file(file_name);
    std::string line;
    int n = 0;
    while (std::getline(file, line)) {
        containers[n] = std::stoi(line);
        n++;
    }
    return n;
}
}
