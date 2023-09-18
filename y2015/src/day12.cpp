#include <D12_2015/day12.hpp>
#include <fstream>
#include <iostream>

int main (int argc, char *argv[]) {
    std::string file_name = "../src/files/day12.txt";
    std::string line;
    std::ifstream file(file_name);
    std::getline(file, line);
    std::cout << "Sum: " << d12::sumNumbers(line) << std::endl;
    std::cout << "Sum: " << d12::sumNumbers(line, "red") << std::endl;
    
    return 0;
}
