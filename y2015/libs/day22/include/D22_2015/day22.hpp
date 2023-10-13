#pragma once

#include <string>
#include <vector>
#include <gtest/gtest.h>

namespace d22 {
struct Spell {
    std::string name;
    int cost;
    int damage;
    int armor;
    int heal;
    int mana;
    int turns;
    bool operator==(const Spell& s) const;
};

class Battle {
private:
    int playerHp;
    int playerMana;
    int playerArmor;
    int bossHp;
    int bossDamage;
    int manaSpent;
    std::vector<Spell> activeEffects;
public:
    Battle();
    FRIEND_TEST(BattleTest, Constructor);
};

std::vector<Spell> getSpells();
bool hasBattleEnded(const Battle& state);
std::vector<Spell> getAvailableSeplls(const Battle& state);
}
