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
    const std::vector<Spell> spells;
    int playerHp;
    int playerMana;
    int playerArmor;
    int bossHp;
    int bossDamage;
    int manaSpent;
    std::vector<Spell> activeEffects;
    bool hasBattleEnded() const;
    std::vector<Spell> getAvailableSpells() const;
    bool isSpellAvailable(const Spell& spell) const;
public:
    Battle();
    FRIEND_TEST(BattleTest, Constructor);
    FRIEND_TEST(BattleTest, AvailableSpells);
};
}
