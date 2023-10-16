#include "D22_2015/day22.hpp"
#include <gtest/gtest.h>

TEST(StateTest, Constructor) {
    d22::State s(69, 9);
    EXPECT_EQ(s.myHp, 50);
    EXPECT_EQ(s.myMana, 500);
    EXPECT_EQ(s.myArmour, 0);
    EXPECT_EQ(s.enemyHp, 69);
    EXPECT_EQ(s.enemyDamage, 9);
    EXPECT_EQ(s.shieldCounter, 0);
    EXPECT_EQ(s.poisonCounter, 0);
    EXPECT_EQ(s.rechargeCounter, 0);
    EXPECT_EQ(s.cost, 0);

    s = {9, 69};
    EXPECT_EQ(s.myHp, 50);
    EXPECT_EQ(s.myMana, 500);
    EXPECT_EQ(s.myArmour, 0);
    EXPECT_EQ(s.enemyHp, 9);
    EXPECT_EQ(s.enemyDamage, 69);
    EXPECT_EQ(s.shieldCounter, 0);
    EXPECT_EQ(s.poisonCounter, 0);
    EXPECT_EQ(s.rechargeCounter, 0);
    EXPECT_EQ(s.cost, 0);
}
