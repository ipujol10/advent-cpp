#ifndef DAY2_HPP
#define DAY2_HPP

#include <array>
#include <string>

namespace d2 {
    int surface(int l, int w, int h);
    int smallestSurface(int l, int w, int h);
    std::array<int, 3> readLine(const std::string& line);
    int ribbon(int l, int w, int h);
    std::array<int, 2> smallestPerimeter(int l, int w, int h);
}

#endif
