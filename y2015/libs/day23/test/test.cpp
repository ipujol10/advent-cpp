#include "D23_2015/day23.hpp"
#include <utils/root.hpp>

namespace d23 {
TEST(ComputerTest, Constructor) {
    const auto root = utils::getRootFolder();
    const std::string file_name(root + "libs/day23/test/files/test.txt");
    Computer c(file_name);

    Instruction main[] = {
        {TypeInstruction::increment, 0, 0},
        {TypeInstruction::jumpOdd, 0, 2},
        {TypeInstruction::triple, 0, 0},
        {TypeInstruction::increment, 0, 0}
    };
    for (int i = 0; i < 4; i++) {
        EXPECT_EQ(c.main[i], main[i]);
    }
}
}
