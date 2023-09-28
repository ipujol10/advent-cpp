#ifndef DAY18_2015
#define DAY18_2015

#include <string>

namespace d18 {
class Lights {
private:
    bool grid[100][100];
    size_t SIZE;
    int onArround(int i, int j);
    bool switchLight(int i, int j);
    void step();
public:
    Lights(const std::string& file_name);
    std::string getState();
    void steps(int n = 1);
    int lightsOn();
};
}

#endif // !DAY18_2015
