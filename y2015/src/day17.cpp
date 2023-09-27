#include <D17_2015/day17.hpp>
#include <iostream>

int main (int argc, char *argv[]) {
    const std::string file_name = "../src/files/day17.txt";
    int containers[50];
    int n = d17::getData(file_name, containers);
    std::cout << "There are " << d17::ways(containers, n, 150) << " ways\n";
    
    return 0;
}
