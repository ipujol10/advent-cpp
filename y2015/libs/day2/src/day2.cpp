#include "D2_2015/day2.hpp"
#include <algorithm>
#include <bits/stdc++.h>

namespace d2 {
    int surface(int l, int w, int h) {
        return 2*l*w + 2*w*h + 2*h*l;
    }

    int smallestSurface(int l, int w, int h) {
        return std::min(std::min(l*w, w*h), h*l);
    }

    std::array<int, 3> readLine(const std::string &line) {
        std::string sep = "x";
        int start, end = -1*sep.size();
        std::array<int, 3> out;
        for (int i = 0; i < 3; i++) {
            start = end + sep.size();
            end = line.find(sep, start);
            out[i] = std::stoi(line.substr(start, end - start));
        }
        return out;
    }

    int ribbon(int l, int w, int h) {
        auto smPer = smallestPerimeter(l, w, h);
        return 2*smPer[0] + 2*smPer[1] + l*w*h;
    }

    std::array<int, 2> smallestPerimeter(int l, int w, int h) {
        std::array<int, 3> all = {l, w, h};
        int min = std::min(l, w);
        int max = std::max(l, w);
        if (h < min) {
            return {h, min};
        }
        if (h < max) {
            return {min, h};
        }
        return {min, max};
    }
}
