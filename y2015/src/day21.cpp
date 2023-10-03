#include <D21_2015/day21.hpp>

int main (int argc, char *argv[]) {
    const std::string file_name("../src/files/day21.txt");
    std::cout << "Total cost: " << d21::cheapestWin(file_name) << std::endl;
    
    return 0;
}
