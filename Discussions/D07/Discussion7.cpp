/******************************************************************************
# Author:           Aiden Jungels and Tucker Creek
# Lab:              Discussion #7
# Date:             11/14/25
# Description:      This program displays a menu and asks the user to make a
#                   selection. A do-while loop repeats the program until the
#                   user selects item 4 from the menu.
# Input:            int choice, int months
# Output:           double charges
# Sources:          None
#******************************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

// Constants for menu choices
const int ADULT_CHOICE = 1,
            CHILD_CHOICE = 2,
            SENIOR_CHOICE = 3,
            QUIT_CHOICE = 4;

// Constants for membership rates
const double ADULT = 40.0,
            CHILD = 20.0,
            SENIOR = 30.0;

// Add function prototypes here
void displayMenu();
int getInput(string prompt);
double getCost(int choice, int months);

int main()
{  
   // Variables
   int choice = 0;         // Menu choice
   int months = 0;         // Number of months
   double charges = 0.0;   // Monthly charges

   cout << fixed << showpoint << setprecision(2);

   do
   {
      // Display the menu.
      displayMenu();
      choice = getInput("Enter your choice: ");

      // Validate the menu selection.
      while (choice < ADULT_CHOICE || choice > QUIT_CHOICE)
      {
         choice = getInput("Please enter a valid menu choice: ");
      }

      // Validate and process the user's choice.
      if (choice != QUIT_CHOICE)
      {
         // Get the number of months.
         months = getInput("For how many months? ");

         // Validate the number of months.
         while (months < 0 || months > 60)
         {
            months = getInput("Please enter months between 0 and 60: ");
         }

         // update cost of health care
         charges = getCost(choice, months);

         // Display the monthly charges.
         cout << "The total charges are $"
              << charges << endl;
      }
   } while (choice != QUIT_CHOICE);

   return 0;
}

// Name: displayMenu()
// Desc: Displays the options for health care
// Input: none
// Output: options menu
// Return: none
void displayMenu() {
   // Display the menu
   cout << "\n\t\tHealth Club Membership Menu\n\n"
        << "1. Standard Adult Membership\n"
        << "2. Child Membership\n"
        << "3. Senior Citizen Membership\n"
        << "4. Quit the Program\n\n";
}

// Name: getInput()
// Desc: outputs prompt and gets user input
// Input: string prompt
// Output: prompt
// Return: int input
int getInput(string prompt) {
   int input;
   // Display prompt and get input
   cout << prompt;
   cin >> input; 
   return input;
}

// Name: getCost()
// Desc: updates healthcare cost based on choice and months
// Input: int choice, int months
// Output:none
// Return: double charges
double getCost(int choice, int months) {
   double charges;
   // Respond to the user's menu selection.
   switch (choice)
   {
      case ADULT_CHOICE:
            charges = months * ADULT;
            break;
      case CHILD_CHOICE:
            charges = months * CHILD;
            break;
      case SENIOR_CHOICE:
            charges = months * SENIOR;
   }
   return charges;
}