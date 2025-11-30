/**********************************************************************
# Author:       Aiden Jungels
# Assignment:   A09 (CS161A)
# Date:         11/29/2025
# Description:  This program will ask the user for a positive number 
#               of integers to input. When a valid input is received, 
#               the program will ask for that many numbers, and track 
#               the highest/lowest numbers input, as well as the first 
#               position they show up in when inputting.
# Input:        int inputNum, int nextInput
# Output:       int maxVal, int minval, int maxIndex, int minIndex
# Sources:      CS Assigment 9 Doc, CS1 Algorithmic Design Doc,
#               Zybooks Chapter 9
**********************************************************************/
#include <iostream>
using namespace std;

// Function prototypes
void getInput(int &num);
void doStats(int num);

int main() {
    int inputNum = 0;

    // Welcome message
    cout << "Welcome to the integer processor!" << endl;
    
    // Instructions and first input
    getInput(inputNum);

    // Validate input
    if (inputNum > 0) {
        // Continue main program
        doStats(inputNum);
    }
    else {
        // End program
        cout << "No integers were entered" << endl;
    }

    // Goodbye message
    cout << endl << "Thank you for using the integer processor!" << endl;

    return 0;
}

// Name: getInput()
// Desc: Gets the number of integers to be inputted
// Input: int &num
// Output: input prompt
// Return: none
void getInput(int &num) {
    cout << endl << "How many positive integers do you want to process?: ";
    cin >> num;
    cout << endl;
}

// Name: doStats()
// Desc: Loops num times and gets integer input, validating and tracking min/max
// Input: int num
// Output: input prompt, maybe error message
// Return: none
void doStats(int num) {
    // Data storage variables
    int nextInput = 0;
    int minIndex = 0;
    int maxIndex = 0;
    int minVal = 0;
    int maxVal = 0;
    
    // Loop to get all integer inputs
    for (int i = 1; i <= num; ++i) {
        cout << "Enter integer #" << i << ": ";
        cin >> nextInput;
        
        // Validate input
        while (nextInput <= 0) {
            cout << "Enter a positive integer!" << endl;
            cout << "Enter integer #" << i << ": ";
            cin.clear();
            cin.ignore(100 , '\n');
            cin >> nextInput;
        }

        // Check for low number
        if ((i == 1) || (nextInput < minVal)) {
            minVal = nextInput;
            minIndex = i;
        }

        // Check for high number
        if ((i == 1) || (nextInput > maxVal)) {
            maxVal = nextInput;
            maxIndex = i;
        }
    }
    
    // Display min/max results
    cout << endl << "The minimum number entered was " << minVal;
    cout << " entered in position " << minIndex << endl;
    cout << "The maximum number entered was " << maxVal;
    cout << " entered in position " << maxIndex << endl;
}