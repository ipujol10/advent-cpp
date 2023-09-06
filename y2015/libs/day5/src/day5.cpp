#include "D5_2015/day5.hpp"

namespace d5 {
    bool threeVowels(const std::string& text) {
        int count = 0;
        std::string compare = "aeiou";
        for (char letter : text) {
            if (compare.find(letter) != std::string::npos) {
                count++;
            }
            if (count == 3) return true;
        }
        return false;
    }

    bool repeatLetter(const std::string& text) {
        for (int i = 0; i < text.length() - 1; i++) {
            if (text[i] == text[i + 1]) return true;
        }
        return false;
    }

    bool notBanned(const std::string& text) {
        std::string banned[] = {"ab", "cd", "pq", "xy"};
        for (int i = 0; i < text.length() - 1; i++) {
            std::string looking = text.substr(i, 2);
            for (auto el : banned) {
                if (looking == el) return false;
            }
        }
        return true;
    }

    bool notNaighty(const std::string &text) {
        return threeVowels(text) && repeatLetter(text) && notBanned(text);
    }
}
