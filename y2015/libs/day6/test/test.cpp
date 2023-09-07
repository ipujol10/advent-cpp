#include <gtest/gtest.h>
#include <D6_2015/day6.hpp>

namespace d6 {
TEST(GridTest, Constructor) {
    Grid g;
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            EXPECT_FALSE(g.lights[i][j]);
        }
    }
}

TEST(GridTest, TurnOn) {
    Grid g;
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            EXPECT_FALSE(g.lights[i][j]);
        }
    }

    g.turnOn(0, 0, 999, 999);
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            EXPECT_TRUE(g.lights[i][j]);
        }
    }

    Grid g2;
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            EXPECT_FALSE(g2.lights[i][j]);
        }
    }
    g2.turnOn(0, 0, 999, 0);
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            if (j == 0) {
                EXPECT_TRUE(g2.lights[i][j]);
            } else {
                EXPECT_FALSE(g2.lights[i][j]);
            }
        }
    }
}

TEST(GridTest, TurnOff) {
    Grid g;
    g.turnOn(0, 0, 999, 999);
    g.turnOff(0, 0, 999, 999);
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            EXPECT_FALSE(g.lights[i][j]);
        }
    }
}

TEST(GridTest, Toggle) {
    Grid g;
    g.turnOn(0, 0, 499, 0);
    for (int i = 0; i < 1000; i++) {
        if (i < 500) {
            EXPECT_TRUE(g.lights[i][0]);
        } else {
            EXPECT_FALSE(g.lights[i][0]);
        }
    }
    g.toggle(0, 0, 999, 0);
    for (int i = 0; i < 1000; i++) {
        if (i < 500) {
            EXPECT_FALSE(g.lights[i][0]);
        } else {
            EXPECT_TRUE(g.lights[i][0]);
        }
    }
}
}

TEST(GridTest, LightsOn) {
    d6::Grid g;
    g.turnOn(0, 0, 999, 999);
    EXPECT_EQ(g.lightsOn(), 1000000);
    g.toggle(0, 0, 999, 0);
    EXPECT_EQ(g.lightsOn(), 999000);
    g.turnOff(499, 499, 500, 500);
    EXPECT_EQ(g.lightsOn(), 999000 - 4);
    g.toggle(498, 499, 501, 500);
    EXPECT_EQ(g.lightsOn(), 999000 - 4);
}

TEST(InputTest, Good) {
    std::string out;
    std::array<int, 4> coordinates, compare;
    coordinates = d6::translateLine("turn off 660,55 through 986,197", out);
    compare = {660, 55, 986, 197};
    EXPECT_EQ(out, "turn off");
    EXPECT_EQ(coordinates, compare);

    coordinates = d6::translateLine("toggle 322,558 through 977,958", out);
    compare = {322, 558, 977, 958};
    EXPECT_EQ(out, "toggle");
    EXPECT_EQ(coordinates, compare);

    coordinates = d6::translateLine("turn on 226,196 through 599,390", out);
    compare = {226, 196, 599, 390};
    EXPECT_EQ(out, "turn on");
    EXPECT_EQ(coordinates, compare);
}

TEST(Grid2Test, Good) {
    d6::Grid2 g;
    EXPECT_EQ(g.intensity(), 0);
    g.turnOn(0, 0, 0, 0);
    EXPECT_EQ(g.intensity(), 1);
    g.toggle(0, 0, 999, 999);
    EXPECT_EQ(g.intensity(), 2000001);
}
