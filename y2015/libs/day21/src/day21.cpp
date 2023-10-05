#include "D21_2015/day21.hpp"
#include <algorithm>
#include <regex>
#include <fstream>
#include <utils/root.hpp>

namespace d21 {
Shop getShop() {
    const auto root = utils::getRootFolder();
    const std::string file_name(root + "libs/day21/src/files/shop.txt");
    std::regex header(R"(^(\w+):\s+\w+\s+\w+\s+\w+$)");
    std::regex object(R"(^(\w+(?:\s\+\d)?)\s+(\d+)\s+(\d)\s+(\d)\s*$)");
    std::fstream file(file_name, std::ios::in);
    std::string line, type;
    std::smatch matches;
    Shop shop;
    while (std::getline(file, line)) {
        if (std::regex_match(line, matches, header)) {
            type = matches[1];
            continue;
        }
        if (std::regex_match(line, matches, object)) {
            const std::string name = matches[1];
            int price = std::stoi(matches[2]);
            int attack = std::stoi(matches[3]);
            int defense = std::stoi(matches[4]);
            Object o;
            if (attack == 0) {
                o = {name, price, defense, TypeObject::defense};
            } else {
                o = {name, price, attack, TypeObject::attack};
            }
            if (type == "Weapons") {
                shop.weapons.push_back(o);
            } else if (type == "Armor") {
                shop.armor.push_back(o);
            } else {
                shop.rings.push_back(o);
            }
        }
    }
    std::sort(shop.weapons.begin(), shop.weapons.end());
    std::sort(shop.armor.begin(), shop.armor.end());
    std::sort(shop.rings.begin(), shop.rings.end());
    return shop;
}

bool Object::operator==(const Object& left) const {
    return cost == left.cost && value == left.value && type == left.type;
}

bool Shop::operator==(const Shop& left) const {
    return weapons == left.weapons && rings == left.rings
        && armor == left.armor;
}

std::ostream& operator<<(std::ostream& os, const Object& obj) {
    const std::string type = (obj.type == TypeObject::attack) ? "Attack}\n" :
        "Defense}\n";
    os << "{" << obj.name << " - " << obj.cost << " - " << obj.value
        << " - " << type;
    return os;
}

std::ostream& operator<<(std::ostream& os, const Shop& shop) {
    os << "{Weapons:\n";
    for (const auto& obj : shop.weapons) {
        os << obj;
    }
    os << "}\n{Armor:\n";
    for (const auto& obj : shop.armor) {
        os << obj;
    }
    os << "}\n{Rings:\n";
    for (const auto& obj : shop.rings) {
        os << obj;
    }
    os << "}\n";
    return os;
}

Character::Character(int hp, int attack, int defense): hp(hp), attack(attack),
    defense(defense), coins(0), rings(0) {}

bool Character::battle(const Character& enemy) const {
    if (attack < 1 || enemy.attack < 1) {
        throw -1;
    }
    int meDamagePerRound = std::max(this->attack - enemy.defense, 1);
    int enemYDamagePerRound = std::max(enemy.attack - this->defense, 1);
    int meDefeatedIn = this->hp / enemYDamagePerRound;
    int enemyDefeatedIn = enemy.hp / meDamagePerRound;
    return meDefeatedIn >= enemyDefeatedIn;
}

bool Object::operator<(const Object& left) const {
    return cost < left.cost;
}

void Character::clear() {
    attack = 0;
    defense = 0;
    coins = 0;
    rings = 0;
}

bool Character::buyObject(const Object& obj) {
    std::regex rgx(R"(\+\d)");
    if (std::regex_search(obj.name, rgx)) {
        rings++;
        if (rings > 2) {
            return false;
        }
    }
    coins += obj.cost;
    if (obj.type == TypeObject::attack) {
        attack += obj.value;
    } else {
        defense += obj.value;
    }
    return true;
}

int cheapestWin(const std::string &file_name) {
    std::ifstream file(file_name);
    std::string line;
    std::regex rgx(R"(^.+\: (\d+)$)");
    std::smatch matches;
    std::vector<int> enemyData;
    while (std::getline(file, line)) {
        std::regex_match(line, matches, rgx);
        enemyData.push_back(std::stoi(matches[1].str()));
    }
    Character me(100, 0, 0);
    Character enemy(enemyData.at(0), enemyData.at(1), enemyData.at(2));
    const Shop shop = getShop();
    int i = 0;
    me.buyObject(shop.weapons.at(0));
    int weapon = shop.weapons.at(0).cost, armor = 0, ring = 0;
    while (!me.battle(enemy)) {
    }
    return me.cost();
}

int Character::cost() const {
    return coins;
}

std::ostream& operator<<(std::ostream& os, const Character& ch) {
    os << ch.hp << " - " << ch.attack << " - " << ch.defense << std::endl;
    return os;
}
}
