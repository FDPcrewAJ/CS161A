/******************************************************************************
# Author:           Aiden Jungels and Tucker Creek
# Lab:              Discussion #2
# Date:             October 3, 2025
# Description:      This program gets the miles per gallon and current price of
#                   gas, then calculates the cost it would take to drive 25,
#                   75, and 100 miles.
# Input:            int mpg, double gasPrice
# Output:           double mileCost
# Sources:          Zybooks chapter 2
#******************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

// Main function
int main() {

    // Welcome message
    cout << "Welcome to the mileage calculator!" << endl;

    // Declare input variables
    int mpg = 0;
    double gasPrice = 0.0;
    double mileCost = 0.0;

    // Get input from user
    cout << endl << "Input your cars miles per gallon: ";
    cin >> mpg;
    cout << "Input the current gas price per gallon: ";
    cin >> gasPrice;

    // Set print decimal precision
    cout << fixed << setprecision(2);
    // Calculate 25 mile cost
    mileCost = (gasPrice / mpg) * 20;
    cout << endl << "Gas cost for 20 Miles: " << mileCost << endl;
    mileCost = (gasPrice / mpg) * 75;
    cout << "Gas cost for 75 Miles: " << mileCost << endl;
    mileCost = (gasPrice / mpg) * 100;
    cout << "Gas cost for 100 Miles: " << mileCost << endl;

    // Goodbye message
    cout << endl << "Thank you for using the mileage calculator!" << endl;

    return 0;
}