#pragma once

#include <string>
#include <gtest/gtest.h>

namespace d23 {
enum TypeInstruction {
    half,
    triple,
    increment,
    jump,
    jumpEven,
    jumpOdd,
};

struct Instruction {
    TypeInstruction type;
    int reg;
    int value;
    bool operator==(const Instruction& left) const;
};

class Computer {
private:
    unsigned int registers[2];
    Instruction main[50];
    unsigned int line;
    int length;
    void resset();
public:
    Computer(const std::string& file_name);
    void pass();
    [[nodiscard]] int getRegisterValue(int reg) const;
    FRIEND_TEST(ComputerTest, Constructor);
};
}
