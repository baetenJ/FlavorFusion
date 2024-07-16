#include <iostream>
#include "Recipe.h"

using namespace std;


Recipe::Recipe(const string& name, const string& mealType)
    : name(name), mealType(mealType), servingSize(1.0) {}

void Recipe::addIngredient(const std::string& ingredient) {
    ingredients.push_back(ingredient);
}

void Recipe::addStep(const std::string& step) {
    steps.push_back(step);
}

void Recipe::setServingSize(double servingSize) {
    this->servingSize = servingSize;
}

string Recipe::getRecipeName() const {
    return name;
}

string Recipe::getMealType() const {
    return mealType;
}

vector<string> Recipe::getIngredients() const {
    return ingredients;
}

vector<string> Recipe::getSteps() const {
    return steps;
}

double Recipe::getServingSize() const {
    return servingSize;
}