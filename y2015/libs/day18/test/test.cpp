#include "D18_2015/day18.hpp"
#include <gtest/gtest.h>

TEST(LightsTest, Constructor) {
    const std::string file_name = "../libs/day18/test/files/test.txt";
    d18::Lights lights(file_name);
    EXPECT_EQ(lights.getState(),
            ".#.#.#\n"
            "...##.\n"
            "#....#\n"
            "..#...\n"
            "#.#..#\n"
            "####..\n"
            );
}

TEST(LightsTest, Steps) {
    const std::string file_name = "../libs/day18/test/files/test.txt";
    d18::Lights lights(file_name);
    lights.steps();
    EXPECT_EQ(lights.getState(),
            "..##..\n"
            "..##.#\n"
            "...##.\n"
            "......\n"
            "#.....\n"
            "#.##..\n"
            );
    lights.steps();
    EXPECT_EQ(lights.getState(),
            "..###.\n"
            "......\n"
            "..###.\n"
            "......\n"
            ".#....\n"
            ".#....\n"
            );
    lights.steps(2);
    EXPECT_EQ(lights.getState(),
            "......\n"
            "......\n"
            "..##..\n"
            "..##..\n"
            "......\n"
            "......\n"
            );
    EXPECT_EQ(lights.lightsOn(), 4);
}
