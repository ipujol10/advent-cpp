#include "D11_2015/day11.hpp"

namespace d11 {
    bool increaseLetter(char &c) {
        if (++c > 'z') {
            c = 'a';
            return true;
        }
        return false;
    }

    void nextWord(std::string &word) {
        for (int i = word.length() - 1; i >= 0; i--) {
            if (!increaseLetter(word[i])) {
                return;
            }
        }
    }

    bool incresing(const std::string &word) {
        for (int i = 0; i < word.length() - 2; i++) {
            if (word[i] + 1 == word[i + 1] && word[i] + 2 == word[i + 2]) {
                return true;
            }
        }
        return false;
    }

    bool notConfusing(const std::string &word) {
        auto end = std::string::npos;
        return (word.find('i') == end
                && word.find('o') == end
                && word.find('l') == end);
    }

    bool twoPairs(const std::string &word) {
        bool first = false;
        for (int i = 0; i < word.length() - 1; i++) {
            if (word[i] == word[i + 1]) {
                i++;
                if (first) {
                    return true;
                }
                first = true;
            }
        }
        return false;
    }

    bool rightPassword(const std::string &word) {
        return incresing(word) && notConfusing(word) && twoPairs(word);
    }

    void nextPassword(std::string &password) {
        do {
            nextWord(password);
        } while (!rightPassword(password));
    }
}
