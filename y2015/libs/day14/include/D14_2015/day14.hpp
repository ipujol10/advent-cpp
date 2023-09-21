#ifndef DAY14_2015
#define DAY14_2015

#include <string>

namespace d14 {
class Reindeer {
private:
    std::string name;
    int velocity;
    int flyTime;
    int restTime;
    int cycleDistance;
    int cycleTime;
public:
    Reindeer(const std::string& line);
    int distance(int time);
};

int getWinnigDistance(const std::string& file_name, int time);
}

#endif // !DAY14_2015
