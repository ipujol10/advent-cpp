#include "D2_2015/day2.hpp"
#include <algorithm>

namespace d2 {
    int surface(int l, int w, int h) {
        return 2*l*w + 2*w*h + 2*h*l;
    }

    int smallestSurface(int l, int w, int h) {
        return std::min(std::min(l*w, w*h), h*l);
    }
}
