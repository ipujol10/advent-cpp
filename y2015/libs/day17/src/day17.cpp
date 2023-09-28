#include "D17_2015/day17.hpp"
#include <algorithm>
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

int getMinContainers(int* containers, int n, int goal) {
    return getMinContainers(containers, n, goal, 0, 0, 0);
}

int getMinContainers(int* containers, int n, int goal, int sum,
        int k, int current) {
    if (sum == goal) {
        return current;
    }
    if (sum > goal || k > n) {
        return n;
    }
    return std::min(
            getMinContainers(containers, n, goal, sum + containers[k],
                k + 1, current + 1),
            getMinContainers(containers, n, goal, sum, k + 1, current));
}

int waysMin(int* containers, int n, int goal, int min) {
    return waysMin(containers, n, goal, 0, 0, 0, min);
}

int waysMin(int* containers, int n, int goal, int sum, int k,
        int current, int min) {
    if (sum == goal && current == min) {
        min = current;
        return 1;
    }
    if (k > n || sum > goal || current >= min) {
        return 0;
    }
    return waysMin(containers, n, goal, sum + containers[k], k + 1,
            current + 1, min)
        + waysMin(containers, n, goal, sum, k + 1, current, min);
}
}
