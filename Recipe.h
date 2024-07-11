#ifndef RECIPE_H
#define RECIPE_H

#include <string>

using namespace std;


class Recipe {
public:
	Recipe(const string& name, const string& mealType); /* maybe we can use an int for meal type to just have a structure for
								collecting meal type more modularly later? */ 

	void addIngredient(const string& ingredient);
	void addStep(const string& step);
	void setServingSize(double servingSize); // using a double here is up for debate, trying to consider .25, .5, etc.

	string getRecipeName() const;
	string getMealType() const; // maybe int?
	vector<string> getIngredients() const;
	vector<string> getSteps() const;
	int getServingSize() const;

private:
	string name;
	string mealType; // maybe int?
	vector<string> ingredients;
	vector<string> steps;
	int servingSize;

 // protected:
};

#endif
