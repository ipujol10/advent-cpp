#include <D1_2015/day1.hpp>
#include <iostream>
#include <string>

int main (int argc, char *argv[]) {
    std::string file = "../src/files/day1.txt";
    std::string journey = d1::read_input(file);

    std::cout << "Final floor: " << d1::floor(journey) << std::endl;
    std::cout << "First basement: " << d1::basement(journey) << std::endl;
    
    return 0;
}
