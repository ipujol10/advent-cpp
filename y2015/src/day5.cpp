#include <D5_2015/day5.hpp>
#include <iostream>
#include <fstream>
#include <string>

int main (int argc, char *argv[]) {
    std::string file_name = "../src/files/day5.txt";
    std::string line;
    std::ifstream file(file_name);
    int count1 = 0, count2 = 0;
    while (std::getline(file, line)) {
        if (d5::notNaighty(line)) count1++;
        if (d5::notNaughty2(line)) count2++;
    }

    std::cout << "Nice strings method 1: " << count1 << std::endl;
    std::cout << "Nice strings method 2: " << count2 << std::endl;

    return 0;
}
