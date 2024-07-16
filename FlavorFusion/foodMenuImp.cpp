#include <iostream>
#include <string>
#include "foodMenu.h"
#include "Recipe.h"

using namespace std;

void Menu::addRecipe(const Recipe& recipe, int mealType) {
	// declare switch for mealType based of integer

	switch (mealType) {
	case 1:
		breakfastRecipes.push_back(recipe);
		break;
	case 2:
		lunchRecipes.push_back(recipe);
		break;
	case 3:
		dinnerRecipes.push_back(recipe);
		break;
	case 4:
		snackRecipes.push_back(recipe);
		break;
	default:
		cout << "Invalid meal type, please enter: 1 for Breakfast, 2 for Lunch, 3 for Dinner, 4 for Snack OR 'done' to exit: " << endl;
		break;
	}
}


void Menu::printRecipes(const vector<Recipe>& recipes, const string& mealType, ostream& out) const {
	out << "\n" << mealType << " Recipes:" << endl;
	for (const auto& recipe : recipes) {
		out << "Recipe: " << recipe.getRecipeName() << endl;
		out << "Ingredients:" << endl;
		for (const auto& ingredient : recipe.getIngredients()) {
			out << "- " << ingredient << endl;
		}
		out << "Steps:" << endl;
		int stepCounter = 1;
		for (const auto& step : recipe.getSteps()) {
			out << stepCounter++ << ". " << step << endl;
		}
		out << "Serving Size: " << recipe.getServingSize() << endl;
		out << endl;
	}
}

// print menu function for foodMenu.h
void Menu::printMenu(ostream& out) const {
	cout << "FlavorFusion Menu: " << endl;
	cout << "-------------------" << endl;

	// call printRecipes for formatting
	printRecipes(breakfastRecipes, "Breakfast", out);
	printRecipes(lunchRecipes, "Lunch", out);
	printRecipes(dinnerRecipes, "Dinner", out);
	printRecipes(snackRecipes, "Snack", out);
}



// get all recipes to print to terminal

vector<Recipe> Menu::getAllRecipes() const {
	vector<Recipe> allRecipes;
	allRecipes.insert(allRecipes.end(), breakfastRecipes.begin(), breakfastRecipes.end());
	allRecipes.insert(allRecipes.end(), lunchRecipes.begin(), lunchRecipes.end());
	allRecipes.insert(allRecipes.end(), dinnerRecipes.begin(), dinnerRecipes.end());
	allRecipes.insert(allRecipes.end(), snackRecipes.begin(), snackRecipes.end());
	return allRecipes;
}