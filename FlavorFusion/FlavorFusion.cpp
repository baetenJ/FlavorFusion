#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "foodMenu.h"

using namespace std;

// funcs for later
void enterRecipe(Menu& flavorFusionMenu);
void viewMenu(const Menu& flavorFusionMenu);
void exportRecipes(const Menu& flavorFusionMenu);


int main()
{
    // Initialize variables
    // variable for user input to initial menu
    int menuSelection = 0;
    // Menu Variable (foodMenu.h)
    Menu flavorFusionMenu;



    string fileName;

    cout << endl;
    cout << "Welcome to FlavorFusion! Your one stop shop for recipe entry" << endl;


    while (menuSelection != 4)  // changed just to equate to 1 value since 'mealTypeSelection' is no longer a variable
    {
        cout << "Choose one of the following options: " << endl;
        cout << "-------------------------------------" << endl;
        cout << "\n1) Add Recipe Entry" << endl;
        cout << "\n2) View your FlavorFusion Menu" << endl;
        cout << "\n3) Export Recipes to file" << endl;
        cout << "\n4) Exit Program";
        cin >> menuSelection;

        cin.ignore(); // line to clear newline from user input
        switch (menuSelection)
        {
        case 1:
            enterRecipe(flavorFusionMenu);
            break;
        case 2:
            viewMenu(flavorFusionMenu);
            break;
        case 3:
            exportRecipes(flavorFusionMenu);
            break;
        case 4:
            cout << "Exiting FlavorFusion..." << endl;
            break;
        default:
            cout << "Invalid selection, please choose between 1-4." << endl;
            break;
        }
    }
    return 0;
}

void enterRecipe(Menu& flavorFusionMenu)
{
    string dishTitle;
    int mealType;
    string ingredient;
    string step;
    double servingSize;

    cout << "\n Enter the name of the dish for recipe input (or 'done' to exit): " << endl;
    getline(cin, dishTitle);

    if (dishTitle == "done") {
        return;
    }

    cout << "Enter the meal type (1 for Breakfast, 2 for Lunch, 3 for Dinner, 4 for Snack OR 'done' to exit): ";
    cin >> mealType;

    Recipe testRecipe(dishTitle, to_string(mealType));


    // Add ingredients to recipe
    // Use while loop to collect until 'done' is entered to initiate next step (add steps of recipe)

    cout << "Enter ingredients and their measurements (ex. '1 1/2 Cup Flour'): " << endl;
    while (true) {
        getline(cin, ingredient);
        if (ingredient == "done") {
            break;
        }
        testRecipe.addIngredient(ingredient);
    }

    // Use while loop to enter recipe steps:
    cout << "Enter steps of the recipe in order (or 'done' to exit): " << endl;
    while (true) {
        getline(cin, step);
        if (step == "done") {
            break;
        }
        testRecipe.addStep(step);
    }

    // set serving size
    cout << "Enter serving size of recipe (how many people): " << endl;
    cin >> servingSize;
    cin.ignore(); // ignore \n character on input 
    testRecipe.setServingSize(servingSize);

    // add recipe to menu (foodMenu.h)
    flavorFusionMenu.addRecipe(testRecipe, mealType);
    cout << "\nRecipe saved!" << endl;

}


void viewMenu(const Menu& flavorFusionMenu) {
    cout << endl << "Menu: " << endl;
    flavorFusionMenu.printMenu();
}


void exportRecipes(const Menu& flavorFusionMenu) {
    // initialize output file
    string fileName;

    // accept input for file name
    cout << "Enter file name you would like to export to: " << endl;

    cin.ignore(); // ignore \n character on input

    getline(cin, fileName);

    ofstream outFile(fileName);

    if (outFile.is_open()) {
        flavorFusionMenu.printMenu(outFile);
        outFile.close();
        cout << "Menu exported successfully to file " << fileName << endl;
    }
    else {
        cout << "Error opening file for recipe printing." << endl;
    }
}