#pragma once

namespace d22 {
struct State {
    unsigned int myHp{50};
    unsigned int myMana{500};
    unsigned int myArmour{0};
    unsigned int enemyHp;
    unsigned int enemyDamage;
    unsigned int shieldCounter;
    unsigned int poisonCounter;
    unsigned int rechargeCounter;
    unsigned int cost;

    State(unsigned int enemyHp, unsigned int enemyDamage);

    bool operator==(const State& rhs) const;

    bool applyEffects();
    void hitEnemy(unsigned int damage);
    void hitMe();
    void spendMana(unsigned int amount);
    void enemyTurn();

    [[nodiscard]] State missile() const;
    [[nodiscard]] State drain() const;
    [[nodiscard]] State shield() const;
    [[nodiscard]] State poison() const;
    [[nodiscard]] State recharge() const;
};
}
