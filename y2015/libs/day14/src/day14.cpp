#include "D14_2015/day14.hpp"
#include <regex>
#include <fstream>

namespace d14 {
Reindeer::Reindeer(const std::string& line) {
    std::regex rgx(R"(^([A-Za-z]+) can fly ([0-9]+) km/s for ([0-9]+) )"
            R"(seconds, but then must rest for ([0-9]+) seconds\.$)");
    std::smatch matches;
    std::regex_match(line, matches, rgx);
    name = matches[1];
    velocity = std::stoi(matches[2].str());
    flyTime = std::stoi(matches[3].str());
    restTime = std::stoi(matches[4].str());
    cycleDistance = velocity * flyTime;
    cycleTime = flyTime + restTime;
}

int Reindeer::distance(int time) {
    int distance = time / cycleTime * cycleDistance;
    int reminder = time % cycleTime;
    if (reminder > flyTime) {
        return distance + cycleDistance;
    }
    return distance + reminder * velocity;
}

int getWinnigDistance(const std::string &file_name, int time) {
    std::ifstream file(file_name);
    std::string line;
    int max = 0;
    while (std::getline(file, line)) {
        d14::Reindeer current(line);
        max = std::max(max, current.distance(time));
    }
    return max;
}
}
