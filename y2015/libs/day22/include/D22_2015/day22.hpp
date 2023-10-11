#pragma once

#include <string>
#include <vector>

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

struct BattleState {
    int playerHp;
    int playerMana;
    int playerArmor;
    int bossHp;
    int bossDamage;
    int manaSpent;
    std::vector<Spell> activeEffects;
};

std::vector<Spell> getSpells();
bool hasBattleEnded(const BattleState& state);
std::vector<Spell> getAvailableSeplls(const BattleState& state);
}
