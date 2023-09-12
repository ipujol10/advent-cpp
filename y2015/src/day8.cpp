#include <D8_2015/day8.hpp>
#include <iostream>
#include <fstream>

int main (int argc, char *argv[]) {
    std::string file_name = "../src/files/day8.txt";
    std::string line;
    std::ifstream file(file_name);
    int count = 0;
    int newEncode = 0;
    while (std::getline(file, line)) {
        count += d8::charsCode(line) - d8::charsMemory(line);
        newEncode += d8::newEncode(line) - d8::charsCode(line);
    }
    std::cout << "Difference: " << count << std::endl;
    std::cout << "New encode: " << newEncode << std::endl;
    
    return 0;
}
