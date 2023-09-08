#include <fstream>
#include <gtest/gtest.h>
#include <D7_2015/day7.hpp>

TEST(CircuitTest, SetGet) {
    d7::Circuit c;
    c.set(10, "b");
    EXPECT_EQ(c.get("b"), 10);
    c.set(654, "a");
    EXPECT_EQ(c.get("a"), 654);
}

TEST(CircuitTest, And) {
    d7::Circuit c;
    c.andGate(5, 3, "c");
    c.andGate(3, 2, "d");
    EXPECT_EQ(c.get("c"), 1);
    EXPECT_EQ(c.get("d"), 2);
}

TEST(CircuitTest, Or) {
    d7::Circuit c;
    c.orGate(5, 3, "c");
    c.orGate(2, 8, "f");
    EXPECT_EQ(c.get("c"), 7);
    EXPECT_EQ(c.get("f"), 10);
}

TEST(CircuitTest, Not) {
    d7::Circuit c;
    c.notGate(65535, "a");
    EXPECT_EQ(c.get("a"), 0);
}

TEST(CircuitTest, BitShifting) {
    d7::Circuit c;
    c.leftShift(23, 1, "a");
    EXPECT_EQ(c.get("a"), 46);
    c.leftShift(46, 1, "a");
    EXPECT_EQ(c.get("a"), 92);
    c.rightShift(92, 2, "a");
    EXPECT_EQ(c.get("a"), 23);
}

TEST(ReadTest, Input) {
    std::string out[3];
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

TEST(CircuitTest, Pass) {
    std::string file = "../libs/day7/test/files/test.txt";
    d7::Circuit c;
    c.readFromFile(file);
    c.pass();
    EXPECT_EQ(c.get("d"), 72);
    EXPECT_EQ(c.get("e"), 507);
    EXPECT_EQ(c.get("f"), 492);
    EXPECT_EQ(c.get("g"), 114);
    EXPECT_EQ(c.get("h"), 65412);
    EXPECT_EQ(c.get("i"), 65079);
    EXPECT_EQ(c.get("x"), 123);
    EXPECT_EQ(c.get("y"), 456);
}

TEST(CircuitTest, PassDelayedSignal) {
    std::string file = "../libs/day7/test/files/test2.txt";
    d7::Circuit c;
    c.readFromFile(file);
    c.pass();
    EXPECT_EQ(c.get("d"), 72);
    EXPECT_EQ(c.get("e"), 507);
    EXPECT_EQ(c.get("f"), 492);
    EXPECT_EQ(c.get("g"), 114);
    EXPECT_EQ(c.get("h"), 65412);
    EXPECT_EQ(c.get("i"), 65079);
    EXPECT_EQ(c.get("x"), 123);
    EXPECT_EQ(c.get("y"), 456);
}

TEST(CircuitTest, GetNumber) {
    d7::Circuit c;
    c.set(9, "a");
    EXPECT_EQ(c.getNumber("a"), 9);
    EXPECT_EQ(c.getNumber("987"), 987);
    EXPECT_THROW(c.getNumber("b"), int);
}

TEST(CircuitTest, Override) {
    d7::Circuit c;
    std::string file = "../libs/day7/test/files/test2.txt";
    c.override(file, "x", 987);
    c.pass();
    EXPECT_EQ(c.get("x"), 987);
}

namespace d7 {
TEST(CircuitTest, ReadFile) {
    auto file_name = "../libs/day7/test/files/test2.txt";
    Circuit c;
    c.readFromFile(file_name);
    std::string line;
    std::ifstream file(file_name);
    while (std::getline(file, line)) {
        EXPECT_EQ(line, c.queue.front());
        c.queue.pop();
    }
}

TEST(CircuitTest, Exists) {
    Circuit c;
    c.set(0, "a");
    c.set(89, "b");
    EXPECT_TRUE(c.exists("a"));
    EXPECT_TRUE(c.exists("b"));
    EXPECT_FALSE(c.exists("c"));
}
}
