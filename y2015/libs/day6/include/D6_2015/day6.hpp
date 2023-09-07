#ifndef DAY6_HPP
#define DAY6_HPP

#include <array>
#include <string>
#include <gtest/gtest.h>

namespace d6 {
    class Grid {
    private:
        bool lights[1000][1000];
        const int SIZE;
        void generalTurn(int tlx, int tly, int brx, int bry, bool on);
    public:
        Grid();
        void turnOn(int tlx, int tly, int brx, int bry);
        void turnOff(int tlx, int tly, int brx, int bry);
        void toggle(int tlx, int tly, int brx, int bry);
        int lightsOn();
        FRIEND_TEST(GridTest, Constructor);
		FRIEND_TEST(GridTest, TurnOn);
		FRIEND_TEST(GridTest, TurnOff);
		FRIEND_TEST(GridTest, Toggle);
    };

    std::array<int, 4> translateLine(
            const std::string& input, std::string& out
            );
}

#endif // !DAY6_HPP
