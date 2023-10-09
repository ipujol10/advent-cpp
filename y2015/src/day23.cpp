#include <D23_2015/day23.hpp>
#include <utils/root.hpp>

int main (int argc, char *argv[]) {
    const auto root = utils::getRootFolder();
    const std::string file_name(root + "src/files/day23.txt");
    d23::Computer computer(file_name);
    computer.pass();
    std::cout << "b = " << computer.getRegisterValue(1) << std::endl;
    computer.pass(1);
    std::cout << "b = " << computer.getRegisterValue(1) << std::endl;
    
    return 0;
}
