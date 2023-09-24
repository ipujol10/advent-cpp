#include "D15_2015/day15.hpp"
#include <gtest/gtest.h>

TEST(FunctionTest, readFile) {
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
