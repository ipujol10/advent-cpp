#include <gtest/gtest.h>
#include <D7_2015/day7.hpp>

TEST(CircuitTest, SetGet) {
    d7::Circuit c;
    c.set("b", "10");
    EXPECT_EQ(c.get("b"), 10);
    EXPECT_EQ(c.get("a"), 0);
    c.set("a", "654");
    EXPECT_EQ(c.get("a"), 654);
}

TEST(CircuitTest, Constructor) {
    d7::Circuit c;
    EXPECT_EQ(c.get("a"), 0);
}

TEST(CircuitTest, And) {
    d7::Circuit c;
    c.set("a", "5");
    c.set("b", "3");
    c.andGate("a", "b", "c");
    c.set("d", "3");
    c.set("e", "2");
    c.andGate("d", "e", "d");
    EXPECT_EQ(c.get("c"), 1);
    EXPECT_EQ(c.get("d"), 2);
}

TEST(CircuitTest, Or) {
    d7::Circuit c;
    c.set("a", "5");
    c.set("b", "3");
    c.orGate("a", "b", "c");
    c.set("d", "2");
    c.set("e", "8");
    c.orGate("d", "e", "f");
    EXPECT_EQ(c.get("c"), 7);
    EXPECT_EQ(c.get("f"), 10);
}

TEST(CircuitTest, Not) {
    d7::Circuit c;
    c.set("a", "65535");
    c.notGate("a", "a");
    EXPECT_EQ(c.get("a"), 0);
}

TEST(CircuitTest, BitShifting) {
    d7::Circuit c;
    c.set("a", "23");
    c.leftShift("a", "1", "a");
    EXPECT_EQ(c.get("a"), 46);
    c.leftShift("a", "1", "a");
    EXPECT_EQ(c.get("a"), 92);
    c.rightShift("a", "2", "a");
    EXPECT_EQ(c.get("a"), 23);
}

TEST(ReadTest, Input) {
    std::string* out;
    d7::operations op;
    op = d7::getElements("123 -> x", out);
    EXPECT_EQ(op, d7::operations::set);
    EXPECT_EQ(out[0], "123");
    EXPECT_EQ(out[1], "x");

    op = d7::getElements("456 -> ye", out);
    EXPECT_EQ(op, d7::operations::set);
    EXPECT_EQ(out[0], "456");
    EXPECT_EQ(out[1], "ye");

    op = d7::getElements("x AND y -> d", out);
    EXPECT_EQ(op, d7::operations::andGate);
    EXPECT_EQ(out[0], "x");
    EXPECT_EQ(out[1], "y");
    EXPECT_EQ(out[2], "d");

    op = d7::getElements("xa OR ya -> ea", out);
    EXPECT_EQ(op, d7::operations::orGate);
    EXPECT_EQ(out[0], "xa");
    EXPECT_EQ(out[1], "ya");
    EXPECT_EQ(out[2], "ea");

    op = d7::getElements("x LSHIFT 2 -> f", out);
    EXPECT_EQ(op, d7::operations::leftShift);
    EXPECT_EQ(out[0], "x");
    EXPECT_EQ(out[1], "2");
    EXPECT_EQ(out[2], "f");

    op = d7::getElements("y RSHIFT 2 -> g", out);
    EXPECT_EQ(op, d7::operations::rightShift);
    EXPECT_EQ(out[0], "y");
    EXPECT_EQ(out[1], "2");
    EXPECT_EQ(out[2], "g");

    op = d7::getElements("NOT x -> h", out);
    EXPECT_EQ(op, d7::operations::notGate);
    EXPECT_EQ(out[0], "x");
    EXPECT_EQ(out[1], "h");

    op = d7::getElements("NOT y -> i", out);
    EXPECT_EQ(op, d7::operations::notGate);
    EXPECT_EQ(out[0], "y");
    EXPECT_EQ(out[1], "i");
}
