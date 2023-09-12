#include <D7_2015/improved.hpp>
#include <D7_2015/day7.hpp>
#include <iostream>
#include <fstream>
#include <string>

void slowMethod(const std::string& file_name) {
    d7::Circuit c, c2;
    c.readFromFile(file_name);
    c.pass();

    std::cout << "Final value at a = " << c.get("a") << std::endl;

    c2.override(file_name, "b", c.get("a"));
    c2.pass();
    std::cout << "Final value at a = " << c2.get("a") << std::endl;
}

void fastMethod(const std::string& file_name) {
    d7i::Circuit c, c2;
    c.readFromFile(file_name);
    c.pass();

    std::cout << "Final value at a = " << c.get("a") << std::endl;

    c2.readFromFile(file_name, "b", c.get("a"));
    c2.pass();
    std::cout << "Final value at a = " << c2.get("a") << std::endl;
}

int main (int argc, char *argv[]) {
    std::string file_name = "../src/files/day7.txt";

    // slowMethod(file_name);
    fastMethod(file_name);
    
    return 0;
}
