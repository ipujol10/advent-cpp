#include "D18_2015/day18.hpp"
#include <fstream>

namespace d18 {
Lights::Lights(const std::string& file_name): corners(false){
    std::ifstream file(file_name);
    std::string line;
    SIZE = 0;
    int i = 0;
    while (std::getline(file, line)) {
        if (SIZE == 0) SIZE = line.length();
        for (int j = 0; j < SIZE; j++) {
            switch (line[j]) {
                case '.':
                    grid[i][j] = false;
                    break;
                case '#':
                    grid[i][j] = true;
                    break;
            }
        }
        i++;
    }
}

std::string Lights::getState() {
    std::string out = "";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j]) {
                out += "#";
            } else {
                out += ".";
            }
        }
        out += "\n";
    }
    return out;
}

void Lights::steps(int n) {
    for (int i = 0; i < n; i++) {
        step();
    }
}

int Lights::onArround(int i, int j) {
    int on = 0;
    for (int x = i - 1; x <= i + 1; x++) {
        for (int y = j - 1; y <= j + 1; y++) {
            if (x == i && y == j) {
                continue;
            }
            if (x < 0 || x >= SIZE || y < 0 || y >= SIZE) {
                continue;
            }
            if (grid[x][y]) {
                on++;
            }
        }
    }
    return on;
}

bool Lights::switchLight(int i, int j) {
    int arround = onArround(i, j);
    if (grid[i][j]) {
        return arround == 2 || arround == 3;
    }
    return arround == 3;
}

void Lights::step() {
    bool nextGrid[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            nextGrid[i][j] = switchLight(i, j);
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = nextGrid[i][j];
        }
    }
    setCorners(corners);
}

int Lights::lightsOn() {
    int counter = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j]) counter++;
        }
    }
    return counter;
}

void Lights::setCorners(bool set) {
    corners = set;
    if (set) {
        grid[0][0] = true;
        grid[0][SIZE - 1] = true;
        grid[SIZE - 1][0] = true;
        grid[SIZE - 1][SIZE - 1] = true;
    }
}
}
