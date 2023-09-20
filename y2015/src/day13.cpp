#include <D13_2015/day13.hpp>
#include <iostream>

int main (int argc, char *argv[]) {
    std::string file_name = "../src/files/day13.txt";
    d13::Gathering g(file_name);
    std::cout << "Maximum happiness: " << g.sitArroundMax() << std::endl;

    g.include("You", 0);
    std::cout << "Maximum happiness: " << g.sitArroundMax() << std::endl;
    
    return 0;
}
