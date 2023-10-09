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
    std::string name;
    int cost;
    int value;
    TypeObject type;
    bool operator==(const Object& left) const;
    bool operator<(const Object& left) const;
    friend std::ostream& operator<<(std::ostream& os, const Object& obj);
};

struct Shop {
    std::vector<Object> weapons, armor, rings;
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
    void clear();
    bool buyObject(const Object& obj);
    int cost() const;
    friend std::ostream& operator<<(std::ostream& os, const Character& ch);
};

int cheapestWin(const std::string& file_name);
int expensiveLost(const std::string& file_name);
std::vector<Object> nextBuy(const Shop& shop, int last_cost);
int costObjects(const std::vector<Object> objects);
std::vector<std::vector<Object>> orderedCombinations(const Shop& shop);
std::vector<std::vector<Object>> ringPairs(const Shop& shop);
bool comparePacks(const std::vector<Object>& v1, const std::vector<Object>& v2);
void printOrder(const std::vector<std::vector<Object>>& order);
void printCost(const std::vector<std::vector<Object>>& order);
std::string rprPack(const std::vector<Object>& pack);
}

#endif // !DAY21_2015
