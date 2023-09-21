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
    int points;
public:
    Reindeer(const std::string& line);
    int distance(int time) const;
    void addPoint();
    int getPoints() const;
    std::string getName() const;
};

int getWinnigDistance(const std::string& file_name, int time);
int getWinnigPoints(const std::string& file_name, int time);
}

#endif // !DAY14_2015
