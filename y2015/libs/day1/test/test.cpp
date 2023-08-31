#include <gtest/gtest.h>
#include "D1_2015/day1.hpp"

TEST(FloorTest, Single) {
    EXPECT_EQ(d1::floor("("), 1); // )
    EXPECT_EQ(d1::floor(")"), -1);
    EXPECT_EQ(d1::floor(""), 0);
}

TEST(FloorTest, F0) {
    EXPECT_EQ(d1::floor("(())"), 0);
    EXPECT_EQ(d1::floor("()()"), 0);
}

TEST(FloorTest, F3) {
    EXPECT_EQ(d1::floor("((("), 3); // )))
    EXPECT_EQ(d1::floor("(()(()("), 3); // )))
    EXPECT_EQ(d1::floor("))((((("), 3); // )))
}

TEST(FloorTest, Fm1) {
    EXPECT_EQ(d1::floor("())"), -1);
    EXPECT_EQ(d1::floor("))("), -1);
}

TEST(FloorTest, Fm3) {
    EXPECT_EQ(d1::floor(")))"), -3);
    EXPECT_EQ(d1::floor(")())())"), -3);
}

TEST(FloorTest, Exception) {
    try {
        d1::floor(" ");
    } catch (int e) {
        EXPECT_EQ(e, 10);
    }
    EXPECT_THROW(d1::floor("(()/"), int);
}

TEST(ReadTest, GoodFiles) {
    EXPECT_EQ(d1::read_input("files/test1.txt"), "test1");
    EXPECT_EQ(d1::read_input("files/test2.txt"), "(())");
}

TEST(ReadTest, FileDoesntExist) {
    try {
        d1::read_input("test1.txt");
    } catch (int e) {
        EXPECT_EQ(e, 20);
    }
    EXPECT_THROW(d1::read_input(""), int);
}
