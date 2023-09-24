#ifndef DAY15_2015
#define DAY15_2015

#include <string>

namespace d15 {
struct Ingredient {
    std::string name;
    int capacity;
    int durability;
    int flavor;
    int texture;
    int calories;

    Ingredient();
    Ingredient(const std::string* info);
};

Ingredient getIngredient(const std::string& line);
int readFile(const std::string& file_name, Ingredient* ingredients);
}

#endif // !DAY15_2015
