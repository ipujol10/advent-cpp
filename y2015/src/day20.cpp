#include <D20_2015/day20.hpp>
#include <iostream>

int main (int argc, char *argv[]) {
    std::cout << "The first house is the number " << d20::firstHouse(29000000)
        << std::endl;
    std::cout << "The first house is the number " << d20::firstHouse2(29000000)
        << std::endl;
    
    return 0;
}
