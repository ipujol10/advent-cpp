#include <D18_2015/day18.hpp>
#include <iostream>

int main (int argc, char *argv[]) {
    const std::string file_name = "../src/files/day18.txt";
    d18::Lights lights(file_name);
    lights.steps(100);
    std::cout << "There are " << lights.lightsOn() << " lights on\n";

    d18::Lights corners(file_name);
    corners.setCorners();
    corners.steps(100);
    std::cout << "There are " << corners.lightsOn() << " lights on\n";
    
    return 0;
}
