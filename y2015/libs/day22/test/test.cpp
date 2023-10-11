#include "D22_2015/day22.hpp"
#include <gtest/gtest.h>

TEST(FunctionTest, Spells) {
    std::vector<d22::Spell> spells{
        { "Magic Missile", 53, 4, 0, 0, 0, 1 },
        { "Drain", 73, 2, 0, 2, 0, 1 },
        { "Shield", 113, 0, 7, 0, 0, 6 },
        { "Poison", 173, 3, 0, 0, 0, 6 },
        { "Recharge", 229, 0, 0, 0, 101, 5 },
    };
    EXPECT_EQ(d22::getSpells(), spells);
}
