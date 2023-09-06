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

    bool anyPairRepeted2(const std::string &text) {
        std::string pair;
        std::string compare;
        for (int i = 0; i < text.length() - 1; i++) {
            pair = text.substr(i, 2);
            for (int j = i + 2; j < text.length() - 1; j++) {
                compare = text.substr(j, 2);
                if (compare == pair) return true;
            }
        }
        return false;
    }

    bool letterInBetween(const std::string &text) {
        for (int i = 0; i < text.length() - 2; i++) {
            if (text[i] == text[i + 2]) return true;
        }
        return false;
    }

    bool notNaughty2(const std::string &text) {
        return anyPairRepeted2(text) && letterInBetween(text);
    }
}
