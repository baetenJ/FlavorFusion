// add ability to determine the day for each menu listing
// 

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "foodMenu.h"

using namespace std;

int main()
{
    int menuSelection;  // Initialize variables
    int mealSelection;
    string fileName;

    cout << endl;
    cout << "Welcome to FlavorFusion! Your one stop shop for recipe entry" << endl;


    while (menuSelection != 3 && mealSelection != 0)  // Use && instead of ||
    {
        cout << "Choose one of the following options (Press 1 or 2): " << endl << endl;
        cout << "\n1) Add Food Entry" << endl;
        cout << "\n2) View your FlavorFusion Menu" << endl;
        cout << "\n3) Exit Program" << endl;
        cin >> menuSelection;

        switch (menuSelection)
        {
            case 1: 
                // Will change to food entry function later
                cout << "Select Breakfast, Lunch, Dinner, or Snack (0 to exit): " << endl;
                cout << "\n1) Breakfast " << endl;
                cout << "\n2) Lunch " << endl;
                cout << "\n3) Dinner " << endl;
                cout << "\n4) Snack " << endl;
                cout << "\n0) Exit Program" << endl; // may want to exit to main menu instead
                cin >> mealSelection;

                switch (mealSelection)
                {
                    case 1:
                        // addBreakfastItem();
                        break;

                    case 2:
                        // addLunchItem();
                        break;

                    case 3:
                        // addDinnerItem();
                        break;

                    case 4:
                        // addSnackItem();
                        break;

                    case 0:
                        // exitProgram();
                        break;

                    default:
                        cout << "Invalid meal selection. Please try again." << endl;
                }
                break;  // exit the inner switch

            case 2:
                // View Menu
                cout << "This will be an updated textfile of the completed menu" << endl;
                break;

            case 3:
                // Exit Program
                cout << "Exiting Program..." << endl;
                break;

            default:
                cout << "Invalid menu selection. Please try again." << endl;
        }
    }

    return 0;
}