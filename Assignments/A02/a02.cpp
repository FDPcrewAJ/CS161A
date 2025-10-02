/**********************************************************************
# Author:       Aiden Jungels
# Assignment:   A01 (CS161A)
# Date:         9/27/25
# Description:  This program will read the number of oreos eaten from
#               the user, then calculate the nunber of servings eaten
#               and the total number of calories eaten, and print
#               the results to the console for the user to see.
# Input:        int: numOreos
# Output:       Displays number of servings eaten, and number of
#               calories eaten, followed by a goodbye message
# Sources:      CS Assigment 2 Doc, CS1 Algorithmic Design Document,
#               Zybooks Chapter 2
**********************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

// Constant variables
const int OREOS_PER_SERVING = 5;
const int CALORIES_PER_SERVING = 160;

// Main funciton
int main() {
    // Number of oreos input variable
    int numOreos = 0;
    // Serving and calorie calculation variables
    double numServings = 0.0;
    double numCalroies = 0.0;

    // Welcome Message and oreos eaten input
    cout << "Oreo Calculator" << endl;
    cout << endl << "Enter the number of Oreos eaten: ";
    cin >> numOreos;

    // Calculate number of servings
    numServings = static_cast<double>(numOreos) / OREOS_PER_SERVING;
    // Calculate number of calroies eaten
    numCalroies = numServings * CALORIES_PER_SERVING;

    // Display results
    cout << endl << "Number of servings eaten: " << fixed << setprecision(1) << numServings << endl;
    cout << "Number of calories consumed: " << fixed << setprecision(1) << numCalroies << endl;
    // Goodbye message
    cout << endl << "Thank you for using!" << endl;

    return 0;
}