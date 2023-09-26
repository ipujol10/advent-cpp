#include <D16_2015/day16.hpp>
#include <iostream>

int main (int argc, char *argv[]) {
    const std::string file_name = "../src/files/day16.txt";
    std::cout << "Send to Sue num " << d16::auntNumber(file_name) << std::endl;
    std::cout << "Send to Sue num " << d16::auntNumberRange(file_name)
        << std::endl;
    
    return 0;
}
