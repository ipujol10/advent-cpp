#include <gtest/gtest.h>
#include <D7_2015/improved.hpp>

TEST(HeapTest, Create) {
//    d7i::MinHeap h;
//    d7i::SetGate a("a", "out0"), 
//        b("b", "out1");
//    d7i::NotGate c("c", "out2"), d("d", "out3");
//    d7i::LeftShift e("e", "1", "out4");
//    d7i::RightShift f("f", "1", "out5");
//    d7i::AndGate g("g", "1", "out6");
//    d7i::OrGate i("i", "1", "out7");
//
//    h.insert(a);
//    h.insert(b);
//    h.insert(c);
//    h.insert(d);
//    h.insert(e);
//    h.insert(f);
//    h.insert(g);
//    h.insert(i);
//
//    EXPECT_EQ(h.pop(), a);
//    EXPECT_EQ(h.pop(), b);
//    EXPECT_EQ(h.pop(), c);
//    EXPECT_EQ(h.pop(), d);
//    EXPECT_EQ(h.pop(), e);
//    EXPECT_EQ(h.pop(), f);
//    EXPECT_EQ(h.pop(), g);
//    EXPECT_EQ(h.pop(), i);
}

TEST(HeapTest, IsEmpty) {
    d7i::MinHeap h;
    h.insert(d7i::SetGate{"a", "out0"});
    h.insert(d7i::AndGate{"b", "c", "out1"});
    EXPECT_FALSE(h.isEmpty());
    h.pop();
    EXPECT_FALSE(h.isEmpty());
    auto g = h.pop();
    EXPECT_TRUE(h.isEmpty());
    h.insert(g);
    EXPECT_FALSE(h.isEmpty());
    h.pop();
    EXPECT_TRUE(h.isEmpty());
}

namespace d7i {
TEST(HeapTest, TranslateLine) {
    MinHeap h;
    auto g0 = h.translateLine("123 -> x");
    EXPECT_EQ(g0.a, 123);
    EXPECT_EQ(g0.out, "x");

    auto g1 = h.translateLine("x AND y -> d");
    EXPECT_EQ(g1.in_a, "x");
    EXPECT_EQ(g1.in_b, "y");
    EXPECT_EQ(g1.out, "d");
}

TEST(CombineTest, TranslateAndExecute) {
    MinHeap h;
    auto g0 = h.translateLine("123 -> x");
    EXPECT_EQ(g0.execute(), 123);
    EXPECT_TRUE(g0.hasBeenExecuted());

    auto g1 = h.translateLine("x AND y -> d");
    EXPECT_EQ(g1.execute(), 0);
    EXPECT_FALSE(g1.hasBeenExecuted());

    auto g2 = h.translateLine("5 AND 3 -> x");
    EXPECT_EQ(g2.execute(), 1);
    EXPECT_TRUE(g2.hasBeenExecuted());

    auto g3 = h.translateLine("5 OR 3 -> x");
    EXPECT_EQ(g3.execute(), 7);

    auto g4 = h.translateLine("NOT 0 -> x");
    EXPECT_EQ(g4.execute(), 65535);

    auto g5 = h.translateLine("23 LSHIFT 1 -> x");
    EXPECT_EQ(g5.execute(), 46);

    auto g6 = h.translateLine("46 RSHIFT 1 -> x");
    EXPECT_EQ(g6.execute(), 23);
}

TEST(GateTest, Constructor) {
    SetGate g0("123", "x");
    EXPECT_TRUE(g0.a_set);
    EXPECT_EQ(g0.a, 123);

    NotGate g1("x", "h");
    EXPECT_FALSE(g1.a_set);
    EXPECT_EQ(g1.in_a, "x");
    NotGate g2("123", "i");
    EXPECT_TRUE(g2.a_set);

    AndGate g3("x", "123", "d");
    EXPECT_TRUE(g3.b_set);
    EXPECT_FALSE(g3.a_set);
    EXPECT_EQ(g3.b, 123);

    OrGate g4("x", "123", "d");
    EXPECT_TRUE(g4.b_set);
    EXPECT_FALSE(g4.a_set);
    EXPECT_EQ(g4.b, 123);

    RightShift g5("x", "123", "d");
    EXPECT_TRUE(g5.b_set);
    EXPECT_FALSE(g5.a_set);
    EXPECT_EQ(g5.b, 123);

    LeftShift g6("x", "123", "d");
    EXPECT_TRUE(g6.b_set);
    EXPECT_FALSE(g6.a_set);
    EXPECT_EQ(g6.b, 123);
}
}
