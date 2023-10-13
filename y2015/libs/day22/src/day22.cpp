#include "D22_2015/day22.hpp"

namespace d22 {
bool Spell::operator==(const Spell& s) const {
    return name == s.name && cost == s.cost && damage == s.damage
        && armor == s.armor && heal == s.heal && mana == s.mana
        && turns == s.turns;
}

Battle::Battle(): spells({ 
        {"Magic Missile", 53, 4, 0, 0, 0, 1},
        {"Drain", 73, 2, 0, 2, 0, 1},
        {"Shield", 113, 0, 7, 0, 0, 6},
        {"Poison", 173, 3, 0, 0, 0, 6},
        {"Recharge", 229, 0, 0, 0, 101, 5}
        }) {
    this->playerHp = 50;
    this->playerMana = 500;
    this->playerArmor = 0;
    this->bossHp = 51;
    this->bossDamage = 9;
    this->manaSpent = 0;
}

bool Battle::hasBattleEnded() const {
    return bossHp <= 0 || playerHp <= 0;
}

bool Battle::isSpellAvailable(const Spell& spell) const {
    if (spell.cost > this->playerMana) return false;

    for (const Spell& active : this->activeEffects) {
        if (active.name == spell.name) {
            return active.turns == 1;
        }
    }
    return true;
}

std::vector<Spell> Battle::getAvailableSpells() const {
    if (hasBattleEnded()) return {};

    std::vector<Spell> out;
    for (const auto spell : this->spells) {
        if (isSpellAvailable(spell)) {
            out.push_back(spell);
        }
    }
    return out;
}

int Battle::sumProps(const SumProps& type) const {
    int sum = 0;
    for (const Spell& spell : this->activeEffects) {
        switch (type) {
            case SumProps::damage:
                sum += spell.damage;
                break;
            case SumProps::mana:
                sum += spell.mana;
                break;
            case SumProps::armor:
                sum += spell.armor;
                break;
        }
    }
    return sum;
}
}
