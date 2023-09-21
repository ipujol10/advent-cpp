#include <gtest/gtest.h>
#include "D14_2015/day14.hpp"

TEST(ReindeerTest, Distance) {
    d14::Reindeer comet("Comet can fly 14 km/s for 10 seconds, but "
            "then must rest for 127 seconds.");
    d14::Reindeer dancer("Dancer can fly 16 km/s for 11 seconds, but "
            "then must rest for 162 seconds.");
    EXPECT_EQ(comet.distance(0), 0);
    EXPECT_EQ(dancer.distance(0), 0);
    EXPECT_EQ(comet.distance(1), 14);
    EXPECT_EQ(dancer.distance(1), 16);
    EXPECT_EQ(comet.distance(10), 140);
    EXPECT_EQ(dancer.distance(10), 160);
    EXPECT_EQ(comet.distance(11), 140);
    EXPECT_EQ(dancer.distance(11), 176);
    EXPECT_EQ(comet.distance(1000), 1120);
    EXPECT_EQ(dancer.distance(1000), 1056);
}

TEST(FunctionTest, WinningDistance) {
    std::string file = "../libs/day14/test/files/test.txt";
    EXPECT_EQ(d14::getWinnigDistance(file, 1000), 1120);
}
