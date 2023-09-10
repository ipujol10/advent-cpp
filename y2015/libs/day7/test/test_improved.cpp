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
