#include <iostream>
#include <D4_2015/day4.hpp>

int main (int argc, char *argv[]) {
    std::string input = "iwrupvqb";
    std::cout << "The number is: " << d4::getNumber(input, 5) << std::endl;
    std::cout << "The number is: " << d4::getNumber(input, 6) << std::endl;
    
    return 0;
}
