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
    EXPECT_EQ(c.registers[0], 0);
    EXPECT_EQ(c.registers[1], 0);
    EXPECT_EQ(c.line, 0);
    EXPECT_EQ(c.length, 4);
}

TEST(ComputerTest, Pass) {
    const auto root = utils::getRootFolder();
    const std::string file_name(root + "libs/day23/test/files/test.txt");
    Computer c(file_name);
    c.pass();
    EXPECT_EQ(c.getRegisterValue(0), 2);
    EXPECT_EQ(c.getRegisterValue(1), 0);
    EXPECT_THROW((void) c.getRegisterValue(2), int);
}
}
