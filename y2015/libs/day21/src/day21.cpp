#include "D21_2015/day21.hpp"
#include <regex>
#include <fstream>

namespace d21 {
Shop getShop() {
    const std::string file_name("../libs/day21/src/files/shop.txt");
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
            int price = std::stoi(matches[2]);
            int attack = std::stoi(matches[3]);
            int defense = std::stoi(matches[4]);
            Object o;
            if (attack == 0) {
                o = {price, defense, TypeObject::defense};
            } else {
                o = {price, attack, TypeObject::attack};
            }
            const std::string name = matches[1];
            if (type == "Weapons") {
                shop.weapons[name] = o;
            } else if (type == "Armor") {
                shop.armor[name] = o;
            } else {
                shop.rings[name] = o;
            }
        }
    }
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
    const std::string type = (obj.type == TypeObject::attack) ? "Attack}" :
        "Defense}";
    os << "{" << obj.cost << " - " << obj.value << " - " << type;
    return os;
}

std::ostream& operator<<(std::ostream& os, const Shop& shop) {
    os << "{Weapons:\n";
    for (const auto& pair : shop.weapons) {
        os << "{" << pair.first << ": " << pair.second << "}\n";
    }
    os << "}\n{Armor:\n";
    for (const auto& pair : shop.armor) {
        os << "{" << pair.first << ": " << pair.second << "}\n";
    }
    os << "}\n{Rings:\n";
    for (const auto& pair : shop.rings) {
        os << "{" << pair.first << ": " << pair.second << "}\n";
    }
    os << "}\n";
    return os;
}

Character::Character(int hp, int attack, int defense): hp(hp), attack(attack),
    defense(defense), coins(0), rings(0) {}

bool Character::battle(const Character& enemy) const {
    int meDamagePerRound = this->attack - enemy.defense;
    int enemYDamagePerRound = enemy.attack - this->defense;
    int meDefeatedIn = this->hp / enemYDamagePerRound;
    int enemyDefeatedIn = enemy.hp / meDamagePerRound;
    return meDefeatedIn >= enemyDefeatedIn;
}
}
