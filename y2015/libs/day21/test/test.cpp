#include "D21_2015/day21.hpp"
#include <gtest/gtest.h>

TEST(FunctionTest, GetShop) {
    d21::Shop s = {
        {
            {"Dagger", 8, 4, d21::TypeObject::attack},
            {"Shortsword", 10, 5, d21::TypeObject::attack},
            {"Warhammer", 25, 6, d21::TypeObject::attack},
            {"Longsword", 40, 7, d21::TypeObject::attack},
            {"Greataxe", 74, 8, d21::TypeObject::attack},
        },
        {
            {"Leather", 13, 1, d21::TypeObject::defense},
            {"Chainmail", 31, 2, d21::TypeObject::defense},
            {"Splintmail", 53, 3, d21::TypeObject::defense},
            {"Bandedmail", 75, 4, d21::TypeObject::defense},
            {"Platemail", 102, 5, d21::TypeObject::defense},
        },
        {
            {"Defense +1", 20, 1, d21::TypeObject::defense},
            {"Damage +1", 25, 1, d21::TypeObject::attack},
            {"Defense +2", 40, 2, d21:: TypeObject::defense},
            {"Damage +2", 50, 2, d21::TypeObject::attack},
            {"Defense +3", 80, 3, d21::TypeObject::defense},
            {"Damage +3", 100, 3, d21::TypeObject::attack},
        }
    };
    EXPECT_EQ(d21::getShop(), s);
}

TEST(CharacterTest, Battle) {
    d21::Character me(8, 5, 5), enemy(12, 7, 2);
    EXPECT_TRUE(me.battle(enemy));
    me = {8, 0, 0};
    EXPECT_THROW(me.battle(enemy), int);
}

TEST(CharacterTest, BuyObject) {
    d21::Character me(8, 0, 0), enemy(12, 7, 2);
    const auto shop = d21::getShop();
    me.buyObject(shop.weapons.at(1));
    me.buyObject(shop.armor.at(1));
    EXPECT_FALSE(me.battle(enemy));
    me.buyObject(shop.rings.at(4));
    EXPECT_TRUE(me.battle(enemy));
}
