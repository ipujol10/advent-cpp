#include "D22_2015/day22.hpp"
#include <iostream>

namespace d22 {
State::State(unsigned int enemyHp, unsigned int enemyDamage): enemyHp(enemyHp),
    enemyDamage(enemyDamage) {}

bool State::operator==(const State& rhs) const {
    return myHp == rhs.myHp && myMana == rhs.myMana && myArmour == rhs.myArmour
        && enemyHp == rhs.enemyHp && enemyDamage == rhs.enemyDamage
        && shieldCounter == rhs.shieldCounter && poisonCounter == rhs.poisonCounter
        && rechargeCounter == rhs.rechargeCounter;
}

bool State::applyEffects() {
    if (shieldCounter > 0) {
        if (--shieldCounter == 0) {
            myArmour -= 7;
        }
    }

    if (poisonCounter > 0) {
        hitEnemy(3);
        poisonCounter--;
    }

    if (rechargeCounter > 0) {
        myMana += 101;
        rechargeCounter--;
    }

    return enemyHp == 0;
}

void State::hitEnemy(unsigned int damage) {
    enemyHp = (damage > enemyHp) ? 0 : enemyHp - damage;
}

void State::hitMe() {
    auto damage{(myArmour >= enemyDamage) ? 1 : enemyDamage - myArmour};
    myHp = (damage > myHp) ? 0 : myHp - damage;
}

void State::spendMana(unsigned int amount) {
    if (myMana < amount) {
        std::cout << "Spent more mana than having it\n";
        throw -1;
    }
    myMana -= amount;
    cost += amount;
}

void State::enemyTurn() {
    if (!applyEffects()) {
        hitMe();
    }
}

State State::missile() const {
    State next{*this};
    next.spendMana(53);
    next.hitEnemy(4);
    next.enemyTurn();
    return next;
}

State State::drain() const {
    State next{*this};
    next.spendMana(73);
    next.hitEnemy(2);
    next.myHp += 2;
    next.enemyTurn();
    return next;
}

State State::shield() const {
    State next{*this};
    if (shieldCounter > 0) {
        std::cout << "Shield still active\n";
        throw -1;
    }
    next.spendMana(113);
    next.myArmour += 7;
    next.shieldCounter = 6;
    next.enemyTurn();
    return next;
}

State State::poison() const {
    State next{*this};
    if (poisonCounter > 0) {
        std::cout << "Poison still active\n";
        throw -1;
    }
    next.spendMana(173);
    next.poisonCounter = 6;
    next.enemyTurn();
    return next;
}

State State::recharge() const {
    State next{*this};
    if (rechargeCounter > 0) {
        std::cout << "Recharge still active\n";
        throw -1;
    }
    next.spendMana(229);
    next.rechargeCounter = 5;
    next.enemyTurn();
    return next;
}
}
