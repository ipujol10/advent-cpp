#include "D21_2015/day21.hpp"
#include <algorithm>
#include <fstream>
#include <regex>
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

bool Object::operator==(const Object &left) const {
  return cost == left.cost && value == left.value && type == left.type;
}

bool Shop::operator==(const Shop &left) const {
  return weapons == left.weapons && rings == left.rings && armor == left.armor;
}

std::ostream &operator<<(std::ostream &os, const Object &obj) {
  const std::string type =
      (obj.type == TypeObject::attack) ? "Attack}\n" : "Defense}\n";
  os << "{" << obj.name << " - " << obj.cost << " - " << obj.value << " - "
     << type;
  return os;
}

std::ostream &operator<<(std::ostream &os, const Shop &shop) {
  os << "{Weapons:\n";
  for (const auto &obj : shop.weapons) {
    os << obj;
  }
  os << "}\n{Armor:\n";
  for (const auto &obj : shop.armor) {
    os << obj;
  }
  os << "}\n{Rings:\n";
  for (const auto &obj : shop.rings) {
    os << obj;
  }
  os << "}\n";
  return os;
}

Character::Character(int hp, int attack, int defense)
    : hp(hp), attack(attack), defense(defense), coins(0), rings(0) {}

bool Character::battle(const Character &enemy) const {
  if (attack < 1 || enemy.attack < 1) {
    throw -1;
  }
  int meDamagePerRound = std::max(this->attack - enemy.defense, 1);
  int enemYDamagePerRound = std::max(enemy.attack - this->defense, 1);
  int meDefeatedIn = this->hp / enemYDamagePerRound;
  if (this->hp % enemYDamagePerRound != 0) {
      meDefeatedIn++;
  }
  int enemyDefeatedIn = enemy.hp / meDamagePerRound;
  if (enemy.hp % meDamagePerRound != 0) {
      enemyDefeatedIn++;
  }
  return meDefeatedIn >= enemyDefeatedIn;
}

bool Object::operator<(const Object &left) const { return cost < left.cost; }

void Character::clear() {
  attack = 0;
  defense = 0;
  coins = 0;
  rings = 0;
}

bool Character::buyObject(const Object &obj) {
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
  const auto combinations = orderedCombinations(shop);
  int i = 0;
  do {
      me.clear();
      for (const Object& obj : combinations.at(i)) {
          me.buyObject(obj);
      }
      i++;
  } while(!me.battle(enemy) && i < combinations.size());
  return me.cost();
}

int expensiveLost(const std::string& file_name) {
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
  const auto combinations = orderedCombinations(shop);
  for (int i = combinations.size() - 1; i >= 0; i--) {
      me.clear();
      for (const Object& obj : combinations.at(i)) {
          me.buyObject(obj);
      }
      if (!me.battle(enemy)) {
          return costObjects(combinations.at(i));
      }
  }
  throw -1;
}

int Character::cost() const { return coins; }

std::ostream &operator<<(std::ostream &os, const Character &ch) {
  os << ch.hp << " - " << ch.attack << " - " << ch.defense << std::endl;
  return os;
}

std::vector<Object> nextBuy(const Shop &shop, int last_cost) {
  int min = last_cost;
  std::vector<Object> out;
  return out;
}

int costObjects(const std::vector<Object> objects) {
  int cost = 0;
  for (const auto &obj : objects) {
    cost += obj.cost;
  }
  return cost;
}

std::vector<std::vector<Object>> orderedCombinations(const Shop &shop) {
    std::vector<std::vector<Object>> combinations;
    const auto pairs = ringPairs(shop);
    for (const Object& weapon : shop.weapons) {
        combinations.push_back({weapon});
        for (const Object& armor : shop.armor) {
            combinations.push_back({weapon, armor});
            for (const Object& ring : shop.rings) {
                combinations.push_back({weapon, armor, ring});
            }
            for (const auto& pair : pairs) {
                std::vector<Object> vect = {weapon, armor};
                vect.push_back(pair.at(0));
                vect.push_back(pair.at(1));
                combinations.push_back(vect);
            }
        }
        for (const Object& ring : shop.rings) {
            combinations.push_back({weapon, ring});
        }
        for (const auto& pair : pairs) {
            std::vector<Object> vect{weapon};
            vect.push_back(pair.at(0));
            vect.push_back(pair.at(1));
            combinations.push_back(vect);
        }
    }
    std::sort(combinations.begin(), combinations.end(), comparePacks);
    return combinations;
}

std::vector<std::vector<Object>> ringPairs(const Shop &shop) {
    std::vector<std::vector<Object>> pairs;
    int n = shop.rings.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            pairs.push_back({shop.rings.at(i), shop.rings.at(j)});
        }
    }
    return pairs;
}

bool comparePacks(const std::vector<Object>& v1, const std::vector<Object>& v2){
    return costObjects(v1) < costObjects(v2);
}

void printOrder(const std::vector<std::vector<Object>> &order) {
    std::cout << "{\n";
    for (const auto& pack : order) {
        std::cout << rprPack(pack);
    }
    std::cout << "}\n";
}

void printCost(const std::vector<std::vector<Object>>& order) {
    std::cout << "{";
    int i = 0;
    for (const auto& pack : order) {
        std::cout << costObjects(pack) << ", ";
        i++;
        if (i == 10) {
            i = 0;
            std::cout << std::endl;
        }
    }
    std::cout << "}\n";
}

std::string rprPack(const std::vector<Object>& pack) {
    std::string out("{");
    for (const Object& obj : pack) {
        out += obj.name + ", ";
    }
    out += "},\n";
    return out;
}
} // namespace d21
