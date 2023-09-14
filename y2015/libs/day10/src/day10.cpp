#include "D10_2015/day10.hpp"

namespace d10 {
std::string lookNsay(const std::string &in) {
    char curr = in[0];
    int count = 0;
    std::string out;
    for (char c : in) {
        if (c == curr) {
            count++;
        } else {
            out += std::to_string(count) + curr;
            curr = c;
            count = 1;
        }
    }
    out += std::to_string(count) + curr;
    return out;
}

std::string repeat(const std::string &in, int repeat) {
    std::string current = in;
    while (repeat > 0) {
        current = lookNsay(current);
        repeat--;
    }
    return current;
}
}
