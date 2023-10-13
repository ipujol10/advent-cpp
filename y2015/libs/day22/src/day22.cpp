#include "D22_2015/day22.hpp"

namespace d22 {
bool Spell::operator==(const Spell& s) const {
    return name == s.name && cost == s.cost && damage == s.damage
        && armor == s.armor && heal == s.heal && mana == s.mana
        && turns == s.turns;
}

Battle::Battle() {
    this->playerHp = 50;
    this->playerMana = 500;
    this->playerArmor = 0;
    this->bossHp = 51;
    this->bossDamage = 9;
    this->manaSpent = 0;
    this->activeEffects = {
        {"Magic Missile", 53, 4, 0, 0, 0, 1},
        {"Drain", 73, 2, 0, 2, 0, 1},
        {"Shield", 113, 0, 7, 0, 0, 6},
        {"Poison", 173, 3, 0, 0, 0, 6},
        {"Recharge", 229, 0, 0, 0, 101, 5}
    };
}

// bool hasBattleEnded(const Battle &state) {
//     return state.bossHp <= 0 || state.playerHp <= 0;
// }
// 
// std::vector<Spell> getAvailableSeplls(const Battle &state) {
//     if (hasBattleEnded(state)) return {};
// 
//     std::vector<Spell> out;
//     for (const auto spell : getSpells()) {
//         if (spell.cost <= state.playerMana) {
//             bool include = true;
//             for (const auto& effect : state.activeEffects) {
//                 if (effect.name == spell.name) {
//                     include = effect.turns == 1;
//                 }
//             }
//             if (include) out.push_back(spell);
//         }
//     }
//     return out;
// }
}
