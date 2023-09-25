#include <D15_2015/day15.hpp>
#include <iostream>

int main (int argc, char *argv[]) {
    std::string file_name = "../src/files/day15.txt";
    d15::Ingredient ingredients[10];
    int n = d15::readFile(file_name, ingredients);
    int weights[10];

    std::cout << "Best total score: " 
        << d15::bestScore(ingredients, n, weights, n) << std::endl;
    std::cout << "Best total score with 500 calories: "
        << d15::bestScoreCalories(ingredients, n, weights, n) << std::endl;

    return 0;
}
