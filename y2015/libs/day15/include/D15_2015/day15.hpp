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
int getCapacity(const Ingredient* ingredients, int n, int weights[]);
int getDurability(const Ingredient* ingredients, int n, int weights[]);
int getFlavor(const Ingredient* ingredients, int n, int weights[]);
int getTexture(const Ingredient* ingredients, int n, int weights[]);
int getCalories(const Ingredient* ingredients, int n, int weights[]);
int getTotalScore(const Ingredient* ingredients, int n, int weights[]);
int bestScore(const Ingredient* ingredients, int n, int weights[], int k);
void printWeights(const int weights[], int n);
}

#endif // !DAY15_2015
