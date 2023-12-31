#include <D19_2015/day19.hpp>
#include <iostream>

int main (int argc, char *argv[]) {
    const std::string file_name("../src/files/day19.txt");
    std::string original;
    auto map = d19::readData(file_name, original);

    std::cout << "Can be created " << d19::numberVariants(map, original)
        << " different molecules\n";
    
    d19::Generate g(file_name);
    std::cout << "The molecule can be created in " <<
        g.generate() << " steps\n";

    return 0;
}
