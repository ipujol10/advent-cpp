#include <D21_2015/day21.hpp>
#include <utils/root.hpp>

int main (int argc, char *argv[]) {
    const auto root = utils::getRootFolder();
    const std::string file_name(root + "src/files/day21.txt");
    std::cout << "Total cost: " << d21::cheapestWin(file_name) << std::endl;
    std::cout << "Lost spending " << d21::expensiveLost(file_name) << std::endl;
    
    return 0;
}
