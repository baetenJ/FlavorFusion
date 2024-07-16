#ifndef FOODMENU_H
#define FOODMENU_H

#include "Recipe.h"
#include <vector>
#include <ostream>

class Menu {
public:
	void addRecipe(const Recipe& recipe, int mealType);
	/*
		void editRecipe(const Recipe& recipe);
		void removeRecipe(const Recipe& recipe);
		maybe future functionalities? might be out of scope as of rn.
	*/

	void printMenu(ostream& out = cout) const;
	// export to file variable
	vector<Recipe> getAllRecipes() const;


private:

	// function to make print recipes smoother
	void printRecipes(const vector<Recipe>& recipes, const string& mealType, ostream& out) const;
	vector<Recipe> breakfastRecipes;
	vector<Recipe> lunchRecipes;
	vector<Recipe> dinnerRecipes;
	vector<Recipe> snackRecipes;
};

#endif