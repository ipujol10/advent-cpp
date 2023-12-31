#include <D6_2015/day6.hpp>
#include <iostream>
#include <fstream>
#include <string>

int main (int argc, char *argv[]) {
    std::string file_name = "../src/files/day6.txt";
    std::string line;
    std::ifstream file(file_name);
    d6::Grid g;
    d6::Grid2 g2;
    std::string operation;
    while (std::getline(file, line)) {
        auto coord = d6::translateLine(line, operation);
        if (operation == "turn off") {
            g.turnOff(coord[0], coord[1], coord[2], coord[3]);
            g2.turnOff(coord[0], coord[1], coord[2], coord[3]);
        } else if (operation == "toggle") { 
            g.toggle(coord[0], coord[1], coord[2], coord[3]);
            g2.toggle(coord[0], coord[1], coord[2], coord[3]);
        } else {
            g.turnOn(coord[0], coord[1], coord[2], coord[3]);
            g2.turnOn(coord[0], coord[1], coord[2], coord[3]);
        }
    }

    std::cout << "Total lights on: " << g.lightsOn() << std::endl;
    std::cout << "Total intensity: " << g2.intensity() << std::endl;
    
    return 0;
}
