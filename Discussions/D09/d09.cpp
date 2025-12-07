/******************************************************************************
# Author:           Aiden Jungels and Tucker Creek
# Lab:              Discussion #9
# Date:             November 30, 20205
# Description:      This program prompts for three integers, reversing the first one
#                   and the reversing the last two as a pair, using function overloading
# Input:            inValOne, inValTwo, inValThree as ints
# Output:           reversedInt as int
# Sources:          Zybooks chapter 9
#******************************************************************************/
#include <iostream>
using namespace std;

// Function prototypes
int reverseDigit(int num1);
void reverseDigit(int &num2, int &num3);

int main() {
    // Declare variables
    int inValOne = 0;
    int inValTwo = 0;
    int inValThree = 0;
    int reversedIntOne = 0;

    // Welcome message
    cout << "Welcome to the integer reverser!" << endl;

    // Get all user input
    cout << endl << "Enter a positive integer: ";
    cin >> inValOne;
    cout << "Enter two positive integers: ";
    cin >> inValTwo;
    cin >> inValThree;

    // Reverse input
    reversedIntOne = reverseDigit(inValOne);
    reverseDigit(inValTwo, inValThree);

    // Display results
    cout << endl << "The first integer reversed is: " << reversedIntOne << endl;
    cout << "The second two integers reversed is: " << inValTwo << ", " << inValThree << endl;

    // Goodbye message
    cout << endl << "Thank you for using!" << endl;

    return 0;
}

// Name: reverseDigit()
// Desc: Reverses a single integer and returns the result
// Input: int num1
// Output: none
// Return: int reversedInt
int reverseDigit(int num1) {
    int nextDigit = 0;
    int reversedInt = 0;
    
    // Loop while num1 has digits left
    while (num1 > 0) {
        // Extract last digit
        nextDigit = num1 % 10;
        // Add last digit to reversed int
        reversedInt = (reversedInt * 10) + nextDigit;
        // Remove last digit from num
        num1 /= 10;
    }

    return reversedInt;
}

// Name: reverseDigit()
// Desc: Reversed two digits and updates them with reference parameters
// Input: int &num2, int& num3
// Output: none
// Return: none
void reverseDigit(int &num2, int &num3) {
    int nextDigit = 0;
    int reversedInt = 0;
    
    // Loop while num1 has digits left
    while (num2 > 0) {
        // Extract last digit
        nextDigit = num2 % 10;
        // Add last digit to reversed int
        reversedInt = (reversedInt * 10) + nextDigit;
        // Remove last digit from num
        num2 /= 10;
    }
    num2 = reversedInt;

    // Reset reversedInt for new number
    reversedInt = 0;
    // Loop while num1 has digits left
    while (num3 > 0) {
        // Extract last digit
        nextDigit = num3 % 10;
        // Add last digit to reversed int
        reversedInt = (reversedInt * 10) + nextDigit;
        // Remove last digit from num
        num3 /= 10;
    }
    num3 = reversedInt;
}