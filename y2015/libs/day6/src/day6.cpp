#include "D6_2015/day6.hpp"
#include <algorithm>
#include <regex>

namespace d6 {
    Grid::Grid(): SIZE(1000) {
        generalTurn(0, 0, SIZE - 1, SIZE - 1, false);
    }

    void Grid::turnOn(int tlx, int tly, int brx, int bry) {
        generalTurn(tlx, tly, brx, bry, true);
    }

    void Grid::turnOff(int tlx, int tly, int brx, int bry) {
        generalTurn(tlx, tly, brx, bry, false);
    }

    void Grid::generalTurn(int tlx, int tly, int brx, int bry, bool on) {
        for (int i = tlx; i < brx + 1; i++) {
            for (int j = tly; j < bry + 1; j++) {
                lights[i][j] = on;
            }
        }
    }

    void Grid::toggle(int tlx, int tly, int brx, int bry) {
        for (int i = tlx; i < brx + 1; i++) {
            for (int j = tly; j < bry + 1; j++) {
                lights[i][j] = !lights[i][j];
            }
        }
    }

    int Grid::lightsOn() {
        int count = 0;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (lights[i][j]) count++;
            }
        }
        return count;
    }

    Grid2::Grid2(): SIZE(1000) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                lights[i][j] = 0;
            }
        }
    }

    void Grid2::turnOn(int tlx, int tly, int brx, int bry) {
        generalTurn(tlx, tly, brx, bry, true);
    }

    void Grid2::turnOff(int tlx, int tly, int brx, int bry) {
        generalTurn(tlx, tly, brx, bry, false);
    }

    void Grid2::generalTurn(int tlx, int tly, int brx, int bry, bool on) {
        for (int i = tlx; i < brx + 1; i++) {
            for (int j = tly; j < bry + 1; j++) {
                int current = lights[i][j];
                if (on) {
                    lights[i][j] = ++current;
                } else {
                    lights[i][j] = std::max(--current, 0);
                }
            }
        }
    }

    void Grid2::toggle(int tlx, int tly, int brx, int bry) {
        turnOn(tlx, tly, brx, bry);
        turnOn(tlx, tly, brx, bry);
    }

    int Grid2::intensity() {
        int count = 0;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                count += lights[i][j];
            }
        }
        return count;
    }


    std::array<int, 4> translateLine(
            const std::string &input, std::string &out) {
        std::regex rgx(
                "(.+) ([0-9]+),([0-9]+) through ([0-9]+),([0-9]+)");
        std::smatch matches;
        std::array<int, 4> coordinates;

        if (std::regex_match(input, matches, rgx)) {
            for (size_t i = 1; i < matches.size(); ++i) {
                std::string match = matches[i];
                if (i == 1) {
                    out = match;
                } else {
                    coordinates[i - 2] = std::stoi(match);
                }
            }
        }
        return coordinates;
    }
}
