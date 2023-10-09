#include "D23_2015/day23.hpp"
#include <regex>
#include <fstream>

namespace d23 {
Computer::Computer(const std::string& file_name): line(0) {
    registers[0] = 0, registers[1] = 0;
    
    std::ifstream file(file_name);
    std::string line;

    std::string rgxString[] = {
        {R"(^hlf ([ab])$)"},
        {R"(^tpl ([ab])$)"},
        {R"(^inc ([ab])$)"},
        {R"(^jmp ([\+\-])(\d+)$)"},
        {R"(^jie ([ab]), ([\+\-])(\d+)$)"},
        {R"(^jio ([ab]), ([\+\-])(\d+)$)"}
    };
    std::smatch matches;
    int i;
    for (i = 0; std::getline(file, line); i++) {
        for (int j = 0; j < 6; j++) {
            if (std::regex_match(line, matches, std::regex(rgxString[j]))) {
                int reg = (matches[1] == "a") ? 0 : 1;
                int sign, val;
                switch (j) {
                    case 0:
                        main[i] = {TypeInstruction::half, reg, 0};
                        break;
                    case 1:
                        main[i] = {TypeInstruction::triple, reg, 0};
                        break;
                    case 2:
                        main[i] = {TypeInstruction::increment, reg, 0};
                        break;
                    case 3:
                        sign = (matches[1] == "-") ? -1 : 1;
                        val = sign * std::stoi(matches[2]);
                        main[i] = {TypeInstruction::jump, 0, val};
                        break;
                    case 4:
                        sign = (matches[2] == "-") ? -1 : 1;
                        val = sign * std::stoi(matches[3]);
                        main[i] = {TypeInstruction::jumpEven, reg, val};
                        break;
                    case 5:
                        sign = (matches[2] == "-") ? -1 : 1;
                        val = sign * std::stoi(matches[3]);
                        main[i] = {TypeInstruction::jumpOdd, reg, val};
                        break;
                }
                break;
            }
        }
    }
    length = i;
}

bool Instruction::operator==(const Instruction& left) const {
    return type == left.type && reg == left.reg && value == left.value;
}

int Computer::getRegisterValue(int reg) const {
    if (reg < 0 || reg > 1) {
        throw 2;
    }
    return registers[reg];
}

void Computer::pass() {
    while (this->line < this->length) {
        const auto instruction = main[line];
        int reg = instruction.reg;
        switch (instruction.type) {
            case TypeInstruction::half:
                registers[reg] /= 2;
                break;
            case TypeInstruction::triple:
                registers[reg] += 3;
                break;
            case TypeInstruction::increment:
                registers[reg]++;
                break;
            case TypeInstruction::jump:
                line += instruction.value;
                continue;
            case TypeInstruction::jumpEven:
                if (registers[reg] % 2 == 0) {
                    line += instruction.value;
                    continue;
                }
                break;
            case TypeInstruction::jumpOdd:
                if (registers[reg] % 2 != 0) {
                    line += instruction.value;
                    continue;
                }
                break;
        }
        line++;
    }
}
}
