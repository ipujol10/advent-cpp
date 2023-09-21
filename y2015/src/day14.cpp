#include <D14_2015/day14.hpp>
#include <iostream>

int main (int argc, char *argv[]) {
    std::string file = "../src/files/day14.txt";
    std::cout << "Winning distance: " << d14::getWinnigDistance(file, 2503)
        << std::endl;
    
    return 0;
}
