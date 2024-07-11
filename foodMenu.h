#ifndef FOODMENU_H
#define FOODMENU_H

#include "Recipe.h"
#include <vector>

class Menu {
public:
	void addRecipe(const Recipe& recipe);
	/*
		void editRecipe(const Recipe& recipe);
		void removeRecipe(const Recipe& recipe);
		maybe future functionalities? might be out of scope as of rn.
	*/

	void printMenu() const;

private:
	vector<Recipe> breakfastRecipes;
	vector<Recipe> lunchRecipes;
	vector<Recipe> dinnerRecipes;
	vector<Recipe> snackRecipes;
};

#endif