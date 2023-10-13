#include "D22_2015/day22.hpp"
#include <gtest/gtest.h>

namespace d22 {
TEST(BattleTest, Constructor) {
    std::vector<Spell> spells{
        { "Magic Missile", 53, 4, 0, 0, 0, 1 },
        { "Drain", 73, 2, 0, 2, 0, 1 },
        { "Shield", 113, 0, 7, 0, 0, 6 },
        { "Poison", 173, 3, 0, 0, 0, 6 },
        { "Recharge", 229, 0, 0, 0, 101, 5 },
    };
    Battle battle;
    EXPECT_EQ(battle.spells, spells);
}

TEST(BattleTest, AvailableSpells) {
    Battle battle;
    std::vector<Spell> available{
        { "Magic Missile", 53, 4, 0, 0, 0, 1 },
        { "Drain", 73, 2, 0, 2, 0, 1 },
        { "Shield", 113, 0, 7, 0, 0, 6 },
        { "Poison", 173, 3, 0, 0, 0, 6 },
        { "Recharge", 229, 0, 0, 0, 101, 5 },
    };
    EXPECT_EQ(battle.getAvailableSpells(), available);

    battle.activeEffects.push_back(battle.spells.at(0));
    EXPECT_EQ(battle.getAvailableSpells(), available);

    available = {
        { "Magic Missile", 53, 4, 0, 0, 0, 1 },
        { "Drain", 73, 2, 0, 2, 0, 1 },
    };
    battle.playerMana = 100;
    EXPECT_EQ(battle.getAvailableSpells(), available);

    battle.playerMana = 50;
    available = {};
    EXPECT_EQ(battle.getAvailableSpells(), available);

}
}
