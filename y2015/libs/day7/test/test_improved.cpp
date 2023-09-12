#include <gtest/gtest.h>
#include <D7_2015/improved.hpp>

TEST(GatesTest, Execute) {
    d7i::Gate set("a", "x", d7i::SetGate);
    EXPECT_FALSE(set.execute());
    set.setA(123);
    EXPECT_EQ(set.execute().value(), 123);
    d7i::Gate set1("1", "x", d7i::SetGate);
    EXPECT_EQ(set1.execute().value(), 1);

    d7i::Gate a("5", "3", "x", d7i::AndGate);
    EXPECT_EQ(a.execute().value(), 1);

    d7i::Gate o("5", "3", "x", d7i::OrGate);
    EXPECT_EQ(o.execute().value(), 7);

    d7i::Gate n("0", "x", d7i::NotGate);
    EXPECT_EQ(n.execute().value(), 65535);

    d7i::Gate left("23", "1", "x", d7i::LeftShift);
    EXPECT_EQ(left.execute().value(), 46);

    d7i::Gate right("92", "2", "x", d7i::RightShift);
    EXPECT_EQ(right.execute().value(), 23);
}

TEST(HeapTest, Create) {
    d7i::MinHeap h;
    d7i::Gate a("1", "out0", d7i::SetGate),
        b("b", "out1", d7i::SetGate),
        c("c", "out2", d7i::NotGate),
        d("d", "out3", d7i::NotGate),
        e("e", "1", "out4", d7i::LeftShift),
        f("f", "1", "out5", d7i::RightShift),
        g("g", "1", "out6", d7i::AndGate),
        i("i", "1", "out7", d7i::OrGate);

    h.insert(i);
    h.insert(g);
    h.insert(f);
    h.insert(e);
    h.insert(d);
    h.insert(c);
    h.insert(b);
    h.insert(a);

    d7i::Gate gate;
    while (!h.isEmpty()) {
        gate = h.pop();
        if (gate.getOut() == "out0") {
            EXPECT_TRUE(gate.execute());
            EXPECT_EQ(gate.execute().value(), 1);
        } else {
            EXPECT_FALSE(gate.execute());
            if (!gate.isOneEntry()) {
                EXPECT_EQ(gate.getB(), "1");
            }
        }
    }
}
