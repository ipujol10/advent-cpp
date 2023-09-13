#include <D9_2015/day9.hpp>

int main (int argc, char *argv[]) {
    std::string file_name = "../src/files/day9.txt";
    d9::Distances d;
    d.generateDistances(file_name);
    std::cout << "The shortest distance is: " << d.getShortest() << std::endl;
    
    return 0;
}
