#include <D10_2015/day10.hpp>
#include <iostream>

int main (int argc, char *argv[]) {
    std::cout << "Output length: " << 
        d10::repeat("3113322113", 40).length() << std::endl;
    std::cout << "Output length: " << 
        d10::repeat("3113322113", 50).length() << std::endl;
    
    return 0;
}
