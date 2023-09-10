#include <gtest/gtest.h>
#include <D7_2015/improved.hpp>

TEST(GatesTest, Execute) {
    d7i::SetGate set("a", "x");
    EXPECT_FALSE(set.execute());
    set.setA(123);
    EXPECT_EQ(set.execute().value(), 123);

    d7i::AndGate a("5", "3", "x");
    EXPECT_EQ(a.execute().value(), 1);

    d7i::OrGate o("5", "3", "x");
    EXPECT_EQ(o.execute().value(), 7);

    d7i::NotGate n("0", "x");
    EXPECT_EQ(n.execute().value(), 65535);

    d7i::LeftShift left("23", "1", "x");
    EXPECT_EQ(left.execute().value(), 46);

    d7i::RightShift right("92", "2", "x");
    EXPECT_EQ(right.execute().value(), 23);
}

TEST(HeapTest, Create) {
    d7i::MinHeap h;
    d7i::SetGate a("1", "out0"), 
        b("b", "out1");
    d7i::NotGate c("c", "out2"), d("d", "out3");
    d7i::LeftShift e("e", "1", "out4");
    d7i::RightShift f("f", "1", "out5");
    d7i::AndGate g("g", "1", "out6");
    d7i::OrGate i("i", "1", "out7");

    h.insert(a);
    h.insert(b);
    h.insert(c);
    h.insert(d);
    h.insert(e);
    h.insert(f);
    h.insert(g);
    h.insert(i);

//    auto ga = h.pop();
//    EXPECT_EQ(ga->getOut(), "out0");
//    EXPECT_TRUE(ga->execute());
    for (int x = 0; x < 8; x++) {
        std::cout << h.pop()->getOut() << std::endl;
    }
}
