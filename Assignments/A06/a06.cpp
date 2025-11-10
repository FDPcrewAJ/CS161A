/**********************************************************************
# Author:       Aiden Jungels
# Assignment:   A06 (CS161A)
# Date:         11/9/2025
# Description:  This program will prompt the user to enter coins into 
#               a virtual vending machine. Then present a menu to 
#               purchase either Coffee or Tea, and the quantity. If 
#               they deposited enough money then the items will be 
#               dispensed. If there are insufficient funds, then more 
#               money will be asked for, and once done, will present 
#               the menu for ordering drinks again, looping until 
#               items are dispensed.
# Input:        int coinInput, int itemAmount, char itemOrder
# Output:       double userChange, double itemsCost
#               Tells user how much money they have left over after
#               purchasing items from the store
# Sources:      CS Assigment 6 Doc, CS1 Algorithmic Design Doc,
#               Zybooks Chapter 6, Assignment 6 sample code
**********************************************************************/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <typeinfo>
using namespace std;

static double SINGLE_ITEM_COST = 0.25;

// Main Function
int main() {
    // Input variables
    int coinInput = 0;
    int itemAmount = 0;
    char itemOrder = ' ';
    // Output variables
    double userChange = 0.0;
    double itemsCost = 0.0;
    // Calculation variables
    bool insufficientFunds = true;
    bool validChoice = false;

    // Welcome message
    cout << "Welcome to the Coffee/Tea Vending Machine!" << endl;
    cout << fixed << setprecision(2);

    // Main program loop
    do {
        // Get coin inputs until done
        cout << endl << "Enter coins - 5, 10, or 25 only, one at a time. Enter 0 to stop." << endl;
        do {
            cout << "Enter coin: ";
            cin >> coinInput;
            // Check if user entered valid coin input
            while (!(coinInput == 5) && !(coinInput == 10) && !(coinInput == 25) && !(coinInput == 0)) {
                cout << "Please enter 5, 10, or 25 only" << endl;
                cout << ">>";
                cin >> coinInput;
            }
            userChange += coinInput / 100.0;
        } while (coinInput != 0);
        // Display balance
        cout << endl << "Your balance is $" << userChange << endl;

        // Display menu
        cout << endl << "Please pick an option ($0.25 each):" << endl;
        cout << "    C/c: Coffee" << endl;
        cout << "    T/t: Tea" << endl;
        cout << "    Q/q: Quit" << endl;
        cout << ">> ";
        
        // Get user order input
        do {
            validChoice = false;
            cin >> itemOrder;
            itemOrder = tolower(itemOrder);
            // Confirm user entered valid option
            if ((itemOrder == 'c') || (itemOrder == 't') || (itemOrder == 'q')) {
                validChoice = true;
            }
            else {
                cout << "Invalid option! Please choose a valid option." << endl;
                cout << ">> ";
            }
        } while (!validChoice);

        // End program if user chooses
        if (itemOrder == 'q') {
            cout << endl << "Your total is $" << itemsCost << endl;
            cout << "Your balance is $" << userChange << endl;
            insufficientFunds = false;
        }
        // Otherwise ask for number of items
        else {
            cout << endl << "How many would you like?" << endl;
            cout << ">> ";
            cin >> itemAmount;
            // Validate integer input
            while (!cin) {
                cout << "Invalid option!" << endl;
                cout << "How many would you like?" << endl;
                cout << ">> ";
                cin.clear();
                cin.ignore();
                cin >> itemAmount;
            }

            // Calculate cost of items ordered, then get end cost
            itemsCost = SINGLE_ITEM_COST * itemAmount;
            // Check if affordable, if yes end program
            if ((userChange - itemsCost) >= 0.0) {
                userChange -= itemsCost;
                cout << endl << "Your total is $" << itemsCost << endl;
                cout << "Your balance is $" << userChange << endl;
                insufficientFunds = false;
            }
            // Otherwise get more coins (reset loop)
            else {
                cout << endl << "Your total is $" << itemsCost << endl;
                cout << "Your balance is $" << userChange << endl;
                cout << "Not enough change! Please add more coins." << endl;
                insufficientFunds = true;
            }
        }
    // If enough funds deposited for items purchased, loop exits
    } while (insufficientFunds);

    // Display goodbye message
    cout << endl << "Thank you for using the Vending Machine Program!" << endl;
    
    return 0;
}