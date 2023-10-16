#include <D22_2015/day22.hpp>
#include <iostream>

int main (int argc, char *argv[]) {
    std::cout << "Minimum mana: " << d22::winMinMana(51, 9) << std::endl;
    std::cout << "Minimum mana: " << d22::winMinMana(51, 9, true) << std::endl;
    
    return 0;
}
