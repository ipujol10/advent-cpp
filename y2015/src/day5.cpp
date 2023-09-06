#include <D5_2015/day5.hpp>
#include <iostream>
#include <fstream>
#include <string>

int main (int argc, char *argv[]) {
    std::string file_name = "../src/files/day5.txt";
    std::string line;
    std::ifstream file(file_name);
    int count = 0;
    while (std::getline(file, line)) {
        if (d5::notNaighty(line)) count++;
    }

    std::cout << "Nice strings: " << count << std::endl;

    return 0;
}
