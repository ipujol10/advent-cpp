#include <iostream>
#include <D2_2015/day2.hpp>
#include <fstream>
#include <tuple>

int main (int argc, char *argv[]) {
    int totatSurface = 0;
    int totalRibbon = 0;
    std::string file_name = "../src/files/day2.txt";
    std::string line;
    std::ifstream file(file_name);
    while (std::getline(file, line)) {
        auto vals = d2::readLine(line);
        int l = vals[0];
        int w = vals[1];
        int h = vals[2];
        totatSurface += d2::surface(l, w, h) + d2::smallestSurface(l, w, h);
        totalRibbon += d2::ribbon(l, w, h);
    }

    file.close();

    std::cout << "Total surface: " << totatSurface << std::endl;
    std::cout << "Total ribbon: " << totalRibbon << std::endl;
    
    return 0;
}
