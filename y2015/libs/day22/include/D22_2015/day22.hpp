#pragma once

#include <string>

namespace d22 {
struct Spell {
    std::string name;
    int cost;
    int damage;
    int armor;
    int heal;
    int mana;
    int turns;
};

struct BattleState {
    int playerHp;
    int playerMana;
    int playerArmor;
    int bossHp;
    int bossDamage;
    int manaSpent;
    Spell activeEffects[20];
};
}
