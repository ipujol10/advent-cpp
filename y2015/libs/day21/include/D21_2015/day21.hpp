#ifndef DAY21_2015
#define DAY21_2015

#include <map>
#include <string>
#include <iostream>
#include <vector>

namespace d21 {
enum class TypeObject {
    attack,
    defense
};

struct Object {
    int cost;
    int value;
    TypeObject type;
    bool operator==(const Object& left) const;
    friend std::ostream& operator<<(std::ostream& os, const Object& obj);
};

struct Shop {
    std::map<std::string, Object> weapons, armor, rings;
    bool operator==(const Shop& left) const;
    friend std::ostream& operator<<(std::ostream& os, const Shop& shop);
};

Shop getShop();

class Character {
private:
    int hp;
    int attack;
    int defense;
    int coins;
    int rings;
public:
    Character(int hp, int attck, int defense);
    bool battle(const Character& enemy) const;
    void clean();
    void buyObject(const Object& obj, bool ring);
};
}

#endif // !DAY21_2015
