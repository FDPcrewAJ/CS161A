/******************************************************************************
# Author:           Aiden Jungels and Tucker Creek
# Lab:              Discussion #2
# Date:             October 12th, 2025
# Description:      This program prompts for a change amount and then delivers 
#                   the total change amount in dollars, quarters, dimes, nickels
#                   and pennies
# Input:            int totalChange
# Output:           int numDollars, numQuarters, numDimes, numNickels, numPennies
# Sources:          zybooks
#******************************************************************************/
#include <iostream>
#include <stdio.h>
using namespace std;


// Declare constant variables
const int DOLLAR = 100;
const int QUARTER = 25;
const int DIME = 10;
const int NICKEL = 5;
const int PENNY = 1;


int main()
{
    
    // Declare change variable 
    int totalChange;
    int numDollars;
    int numQuarters;
    int numDimes;
    int numNickels;
    int numPennies;
    
    // Welcome message and input prompt
    cout << "Welcome to the change calculator!" << endl;
    cout << "Enter the amount of change you have: ";
    cin >> totalChange;
    
    // Check if user enter a change amount greater than zero
    if (totalChange > 0) {
        cout << endl << "The change you need is: " << endl;
        // Calculate and subtract dollar amount
        numDollars = totalChange / DOLLAR;
        totalChange %= DOLLAR;
        // Calculate and subtract quarter amount
        numQuarters = totalChange / QUARTER;
        totalChange %= QUARTER;
        // Calculate and subtract dime amount
        numDimes = totalChange / DIME;
        totalChange %= DIME;
        // Calculate and subtract nickel amount
        numNickels = totalChange / NICKEL;
        totalChange %= NICKEL;
        // Calculate and subtract penny amount
        numPennies = totalChange / PENNY;
        totalChange %= PENNY;
    
        // Print dollar amount if any
        if (numDollars > 1) {
            cout << numDollars << " Dollars" << endl;
        }
        else if (numDollars == 1) {
            cout << numDollars << " Dollar" << endl;
        }
        // Print quarter amount if any
        if (numQuarters > 1) {
            cout << numQuarters << " Quarters" << endl;
        }
        else if (numQuarters == 1) {
            cout << numQuarters << " Quarter" << endl;
        }
        // Print dime amount if any
        if (numDimes > 1) {
            cout << numDimes << " Dimes" << endl;
        }
        else if (numDimes == 1) {
            cout << numDimes << " Dime" << endl;
        }
        // Print nickel amount if any
        if (numNickels > 1) {
            cout << numNickels << " Nickels" << endl;
        }
        else if (numNickels == 1) {
            cout << numNickels << " Nickel" << endl;
        }
        // Print penny amount if any
        if (numPennies > 1) {
            cout << numPennies << " Pennies" << endl;
        }
        else if (numPennies == 1) {
            cout << numPennies << " Penny" << endl;
        }
    }
    // Display error if user enters negative number
    else if (totalChange < 0) {
    cout << endl << "Please enter a positive number.";
    }
    // Display no change if user enters zero
    else {
        cout << endl << "No Change.";
    }
    
    return 0;
}
