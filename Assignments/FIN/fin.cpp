/**********************************************************************
# Author:       Aiden Jungels
# Assignment:   Fin (CS161A)
# Date:         12/7/2025
# Description:  This program will ask the user how many hours they 
#               want to ride their bike for this week. Then it will 
#               loop prompting for the number of hours ridden each 
#               day before displaying if they met their riding goal 
#               for the week or not.
# Input:        int userGoal, int nextInput
# Output:       int userTotal, int mileDiff
# Sources:      CS Final Exam Doc, CS1 Algorithmic Design Doc
**********************************************************************/
#include <iostream>
#include <cmath>
using namespace std;

void getInput(int &goal);
int calcTotal();

int main() {
    // Declare variables
    int userGoal = 0;
    int userTotal = 0;
    int mileDiff = 0;

    // Welcome message
    cout << "Welcome to the Bike Riding goal tracker!" << endl;
    
    // Get user goal
    cout << endl << "How many miles would you like to ride this week?: ";
    getInput(userGoal);
    
    // Confirm valid goal
    if (userGoal > 0) {
        // Get user total
        cout << endl;
        userTotal = calcTotal();
        
        // Get user to goal difference
        mileDiff = userTotal - userGoal;
        
        // Display miles ridden
        cout << endl << "You rode " << userTotal;
        cout << " miles this week." << endl;
        
        // Check if goal met
        if (mileDiff < 0) {
            // Display goal missed and by how much
            cout << "Oh No! You were under your goal by ";
            cout << fabs(mileDiff) << " miles!" << endl;
        }
        else if (mileDiff == 0) {
            // Display goal met
            cout << "Good Job! You met your goal!" << endl;
        }
        else {
            // Display goal met and by how much
            cout << "Great Job! You exceeded your goal by ";
            cout << fabs(mileDiff) << " miles!" << endl;
        }
    }
    else {
        // End program
        cout << endl << "No miles were tracked this week." << endl;
    }

    // Goodbye message
    cout << endl << "Thank you for using! Keep Riding!" << endl;

    return 0;
}

void getInput(int &goal) {
    cin >> goal;
}

int calcTotal() {
    // Declare variables
    int totalMiles = 0;
    int nextInput = 0;
    string curDay = " ";

    // Loop for each day of the week
    for(int i = 0; i < 7; i++) {
        // Match day of the week to i
        switch (i) {
            case 0:
                curDay = "Sunday";
                break;
            case 1:
                curDay = "Monday";
                break;
            case 2:
                curDay = "Tuesday";
                break;
            case 3:
                curDay = "Wednesday";
                break;
            case 4:
                curDay = "Thursday";
                break;
            case 5:
                curDay = "Friday";
                break;
            case 6:
                curDay = "Saturday";
                break;
            default:
                curDay = "Unknown";
                break;
        }

        // Display prompt and get primer input
        cout << "How many miles did you ride on " << curDay << "?: ";
        cin >> nextInput;
        
        // Validate input
        while (nextInput < 0) {
            cout << "Miles must be 0 or greater!" << endl;
            cout << "How many miles did you ride on " << curDay << "?: ";
            cin.clear();
            cin.ignore(100 ,'\n');
            cin >> nextInput;
        }

        // Add next day to accumulator
        totalMiles += nextInput;
    }

    return totalMiles;
}