#include <gtest/gtest.h>
#include <D7_2015/day7.hpp>

TEST(CircuitTest, SetGet) {
    d7::Circuit c;
    c.set("b", 10);
    EXPECT_EQ(c.get("b"), 10);
    EXPECT_EQ(c.get("a"), 0);
    c.set("a", 654);
    EXPECT_EQ(c.get("a"), 654);
}

TEST(CircuitTest, Constructor) {
    d7::Circuit c;
    EXPECT_EQ(c.get("a"), 0);
}

TEST(CircuitTest, And) {
    d7::Circuit c;
    c.set("a", 5);
    c.set("b", 3);
    c.andGate("a", "b", "c");
    c.set("d", 3);
    c.set("e", 2);
    c.andGate("d", "e", "d");
    EXPECT_EQ(c.get("c"), 1);
    EXPECT_EQ(c.get("d"), 2);
}

TEST(CircuitTest, Or) {
    d7::Circuit c;
    c.set("a", 5);
    c.set("b", 3);
    c.orGate("a", "b", "c");
    c.set("d", 2);
    c.set("e", 8);
    c.orGate("d", "e", "f");
    EXPECT_EQ(c.get("c"), 7);
    EXPECT_EQ(c.get("f"), 10);
}

TEST(CircuitTest, Not) {
    d7::Circuit c;
    c.set("a", 65535);
    c.notGate("a", "a");
    EXPECT_EQ(c.get("a"), 0);
}

TEST(CircuitTest, BitShifting) {
    d7::Circuit c;
    c.set("a", 23);
    c.leftShift("a", 1, "a");
    EXPECT_EQ(c.get("a"), 46);
    c.leftShift("a", 1, "a");
    EXPECT_EQ(c.get("a"), 92);
    c.rightShift("a", 2, "a");
    EXPECT_EQ(c.get("a"), 23);
}
