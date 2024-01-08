#include <D7_2015/virtual.hpp>
#include <gtest/gtest.h>

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
