#include <D11_2015/day11.hpp>
#include <iostream>

int main (int argc, char *argv[]) {
    std::string password = "hepxcrrq";
    d11::nextPassword(password);
    std::cout << "Next password: " << password << std::endl;
    d11::nextPassword(password);
    std::cout << "Next password: " << password << std::endl;
    
    return 0;
}
