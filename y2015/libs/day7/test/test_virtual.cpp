#include <D7_2015/virtual.hpp>
#include <gtest/gtest.h>
#include <iostream>

TEST(GatesTest, Execute) {
  d7v::Gate *set = new d7v::Set("a", "x");
  EXPECT_FALSE(set->execute());
  set->setA(123);
  EXPECT_EQ(set->execute().value(), 123);
  d7v::Gate *set1 = new d7v::Set("1", "x");
  EXPECT_EQ(set1->execute().value(), 1);

  d7v::Gate *a = new d7v::And("5", "3", "x");
  EXPECT_EQ(a->execute().value(), 1);

  d7v::Gate *o = new d7v::Or("5", "3", "x");
  EXPECT_EQ(o->execute().value(), 7);

  d7v::Gate *n = new d7v::Not("0", "x");
  EXPECT_EQ(n->execute().value(), 65535);

  d7v::Gate *left = new d7v::LShift("23", "1", "x");
  EXPECT_EQ(left->execute().value(), 46);

  d7v::Gate *right = new d7v::RShift("92", "2", "x");
  EXPECT_EQ(right->execute().value(), 23);
}

TEST(HeapTest, Create) {
  d7v::MinHeap h;
  d7v::Gate *a = new d7v::Set("1", "out0"),
    *b = new d7v::Set("b", "out1"),
    *c = new d7v::Not("c", "out2"),
    *d = new d7v::Not("d","out3"),
    *e = new d7v::LShift("e", "1", "out4"),
    *f = new d7v::RShift("f", "1", "out5"),
    *g = new d7v::And("g", "1", "out6"),
    *i = new d7v::Or("i", "1", "out7");

  h.insert(i);
  h.insert(g);
  h.insert(f);
  h.insert(e);
  h.insert(d);
  h.insert(c);
  h.insert(b);
  h.insert(a);

  d7v::Gate *gate;
  while (!h.isEmpty()) {
    gate = h.pop();
    std::cout << gate->getOut() << std::endl;
    if (gate->getOut() == "out0") {
      EXPECT_TRUE(gate->execute());
      EXPECT_EQ(gate->execute().value(), 1);
    } else {
      EXPECT_FALSE(gate->execute());
      if (!gate->isOneEntry()) {
        EXPECT_EQ(gate->getB(), "1");
      }
    }
  }
}
