#include <D7_2015/day7.hpp>
#include <iostream>
#include <fstream>
#include <string>

int main (int argc, char *argv[]) {
    std::string file_name = "../src/files/day7.txt";
    std::string line;
    std::ifstream file(file_name);
    d7::Circuit c;
    std::string variables[3];
    d7::valType value;
    while (std::getline(file, line)) {
        auto operation = d7::getElements(line, variables);
        switch (operation) {
            case d7::operations::set:
                value = (d7::valType)std::stoi(variables[0]);
                c.set(variables[1], value);
                break;
            case d7::operations::leftShift:
                value = (d7::valType)std::stoi(variables[1]);
                c.leftShift(variables[0], value, variables[2]);
                break;
            case d7::rightShift:
                value = (d7::valType)std::stoi(variables[1]);
                c.rightShift(variables[0], value, variables[2]);
                break;
            case d7::notGate:
                c.notGate(variables[0], variables[1]);
                break;
            case d7::andGate:
                c.andGate(variables[0], variables[1], variables[2]);
                break;
            case d7::orGate:
                c.orGate(variables[0], variables[1], variables[2]);
                break;
        }
    }
    std::cout << "Final value at a = " << c.get("a") << std::endl;
    
    return 0;
}
