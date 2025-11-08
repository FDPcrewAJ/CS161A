/******************************************************************************
# Author:           Aiden Jungels and Tucker Creek
# Lab:              Discussion #6
# Date:             November 7, 2025
# Description:      This program prompts for a word or phrase and then 
#		            outputs whether it is a palindrome or not
# Input:            inputString
# Output:           Whether or not inputString is a palindrome
# Sources:          zybooks chapter 6
#******************************************************************************/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Main function
int main() { 

    // Declare variables
    string inputString = " ";
    string reversedString;
    string lowerInput;
    char nextChar = ' ';

    // Welcome message and user input
    cout << "Welcome to the palindrome checker!" << endl;
    cout << "Enter a phrase: ";
    getline(cin, inputString);

    // Create new string from input without spaces
    for (int i = 0; i < inputString.length(); i++)
    {
        nextChar = inputString[i];
        if (nextChar != ' ') {
            nextChar = tolower(nextChar);
            lowerInput += nextChar;
        }        
    }

    // Create a reversed string of the input string
    for (int i = (lowerInput.length() - 1); i >= 0; i--) {
        nextChar = lowerInput[i];
        reversedString += nextChar;
    }

    // Check if the reversed string is equal to input, and output results
    if (lowerInput == reversedString) {
        cout << "\"" << inputString << "\"" << " is a palindrome!" << endl;
    }
    else {
        cout << "\"" << inputString << "\"" << " is not a palindrome!" << endl;
    }

    // Goodbye message
    cout << endl << "Thank you for using!" << endl;
    
    return 0;
}