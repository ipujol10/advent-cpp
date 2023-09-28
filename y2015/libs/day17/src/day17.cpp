#include "D17_2015/day17.hpp"
#include <fstream>

namespace d17 {
int ways(int* containers, int n, int goal) {
    return ways(containers, n, goal, 0, 0);
}

int ways(int* containers, int n, int goal, int sum, int k) {
    if (sum == goal) {
        return 1;
    }
    if (k > n || sum > goal) {
        return 0;
    }
    return ways(containers, n, goal, sum, k + 1)
        + ways(containers, n, goal, sum + containers[k], k + 1);
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

int waysMin(int* containers, int n, int goal) {
    int min = n;
    return waysMin(containers, n, goal, 0, 0, 0, min);
}

int waysMin(int* containers, int n, int goal, int sum, int k,
        int current, int& min) {
    if (k >= n || sum > goal || current >= min) {
        return 0;
    }
    current++;
    int newWays = 0;
    int lastMin = min;
    for (int i = k; i < n; i++) {
        int newSum = sum + containers[i];
        if (newSum == goal) {
            if (current < min) {
                min = current;
                lastMin = min;
                newWays = 0;
            }
            newWays++;
        } else {
            int nextWays = waysMin(containers, n, goal, newSum, i + k,
                    current, min);
            if (min < lastMin) {
                newWays = nextWays;
                lastMin = min;
            } else if (min == lastMin) {
                newWays += nextWays;
            }
        }
    }
    return newWays;
}
}
