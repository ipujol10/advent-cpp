#ifndef DAY21_2015
#define DAY21_2015

#include <map>
#include <string>

namespace d21 {
enum class TypeObject {
    attack,
    defense
};

struct Object {
    int cost;
    int value;
    TypeObject type;
};

struct Shop {
    std::map<std::string, Object> weapons, armor, rings;
};

Shop getShop();
}

#endif // !DAY21_2015
