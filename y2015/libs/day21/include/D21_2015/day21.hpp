#ifndef DAY21_2015
#define DAY21_2015

#include <map>
#include <string>
#include <iostream>

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
}

#endif // !DAY21_2015
