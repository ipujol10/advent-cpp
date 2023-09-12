#include "D8_2015/day8.hpp"

namespace d8 {
    int escapeChars(const std::string &line) {
        int count = 0;
        char curr, next;
        for (int i = 1; i < line.length() - 1; i++) {
            curr = line[i];
            if (curr == '\\') {
                count++;
                i++;
                next = line[i];
                switch (next) {
                    case '\\':
                    case '"':
                        break;
                    case 'x':
                        count += 2;
                        i += 2;
                        break;
                    default:
                        throw -1;
                }
            }
        }
        return count;
    }

    int charsMemory(const std::string &line) {
        return charsCode(line) - 2 - escapeChars(line);
    }

    int charsCode(const std::string &line) {
        return line.length();
    }

    int newEncode(const std::string &line) {
        int length = line.length() + 2;
        for (char c : line) {
            switch (c) {
                case '\\':
                case '"':
                    length++;
            }
        }
        return length;
    }
}
