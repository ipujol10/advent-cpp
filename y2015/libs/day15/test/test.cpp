#include "D15_2015/day15.hpp"
#include <gtest/gtest.h>

TEST(FunctionTest, ReadFile) {
    const std::string file_name = "../libs/day15/test/files/test.txt";
    d15::Ingredient ingredients[2];

    EXPECT_EQ(d15::readFile(file_name, ingredients), 2);
    EXPECT_EQ(ingredients[0].name, "Butterscotch");
    EXPECT_EQ(ingredients[0].capacity, -1);
    EXPECT_EQ(ingredients[0].durability, -2);
    EXPECT_EQ(ingredients[0].flavor, 6);
    EXPECT_EQ(ingredients[0].texture, 3);
    EXPECT_EQ(ingredients[0].calories, 8);
    EXPECT_EQ(ingredients[1].name, "Cinnamon");
    EXPECT_EQ(ingredients[1].capacity, 2);
    EXPECT_EQ(ingredients[1].durability, 3);
    EXPECT_EQ(ingredients[1].flavor,-2);
    EXPECT_EQ(ingredients[1].texture, -1);
    EXPECT_EQ(ingredients[1].calories, 3);
}

TEST(FunctionTest, GetIngredients) {
    const std::string file_name = "../libs/day15/test/files/test.txt";
    d15::Ingredient ingredients[2];

    d15::readFile(file_name, ingredients);
    int weights[] = {44, 56};

    EXPECT_EQ(d15::getCapacity(ingredients, 2, weights), 68);
    EXPECT_EQ(d15::getDurability(ingredients, 2, weights), 80);
    EXPECT_EQ(d15::getFlavor(ingredients, 2, weights), 152);
    EXPECT_EQ(d15::getTexture(ingredients, 2, weights), 76);
    EXPECT_EQ(d15::getTotalScore(ingredients, 2, weights), 62842880);

    weights[0] = 68, weights[1] = 32;
    EXPECT_EQ(d15::getCapacity(ingredients, 2, weights), 0);
    EXPECT_EQ(d15::getTotalScore(ingredients, 2, weights), 0);

    weights[0] = 40, weights[1] = 60;
    EXPECT_EQ(d15::getTotalScore(ingredients, 2, weights), 57600000);
}

TEST(FunctionTest, Best) {
    const std::string file_name = "../libs/day15/test/files/test.txt";
    d15::Ingredient ingredients[2]; 
    int n = d15::readFile(file_name, ingredients);
    int weights[2];

    EXPECT_EQ(d15::bestScore(ingredients, n, weights, n), 62842880);
}

TEST(FunctionTest, Calories) {
    const std::string file_name = "../libs/day15/test/files/test.txt";
    d15::Ingredient ingredients[2];

    d15::readFile(file_name, ingredients);
    int weights[] = {40, 60};
    EXPECT_EQ(d15::getCalories(ingredients, 2, weights), 500);
}

TEST(FunctionTest, BestCalories) {
    const std::string file_name = "../libs/day15/test/files/test.txt";
    d15::Ingredient ingredients[2];
    int n = d15::readFile(file_name, ingredients);
    int weights[2];

    EXPECT_EQ(d15::bestScoreCalories(ingredients, n, weights, n), 57600000);
}
