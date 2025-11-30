/**********************************************************************
# Author:       Aiden Jungels
# Assignment:   FP1 (CS161A)
# Date:         11/30/2025
# Description:  This program will ask the user for a positive integer 
#               and then calculate the number of digits, sum of digits, 
#               and number of even and odd digits in the number, then 
#               return that information to the user.
# Input:        int inputNum
# Output:       int mdigitsInNum, int digitsSum, int evenDigits,
#               int oddDigits
# Sources:      CS Final Exam Practice Doc, CS1 Algorithmic Design Doc
**********************************************************************/
#include <iostream>
using namespace std;

// Function prototypes
void getInput(int &num);
int numDigits(int num);
int sumDigits(int num);
int countEven(int num);
void countOdd(int num, int &odd);

int main() {
    // Input Variable
    int inputNum = 0;
    // Statistics variables
    int digitsInNum = 0;
    int digitsSum = 0;
    int evenDigits = 0;
    int oddDigits = 0;

    // Welcome message/input prompt
    cout << "Welcome to the final exam practice" << endl;
    cout << endl << "Please enter a positive integer: ";
    
    // Get and check input
    getInput(inputNum);
    if (inputNum > 0) {
        // Get the number of digits
        digitsInNum = numDigits(inputNum);
        // Get the sum of digits
        digitsSum = sumDigits(inputNum);
        // Get num of even digits
        evenDigits = countEven(inputNum);
        // Get num of odd digits
        countOdd(inputNum, oddDigits);


        // Display results
        cout << endl << "The number of digits in your number is: " << digitsInNum << endl;
        cout << "The sum of the digits in your number is: " << digitsSum << endl;
        cout << "The number of even digits in your number is: " << evenDigits << endl;
        cout << "The number of odd digits in your number is: " << oddDigits << endl;
    }

    // Goodbye message
    cout << endl << "Thank you for using" << endl;
    
    return 0;
}

// Name: getInput()
// Desc: gets integer input from user
// Input: int &num
// Output: none
// Return: none
void getInput(int &num) {
    cin >> num;
}

// Name: numDigits()
// Desc: gets the number of digits in input num
// Input: int num
// Output: none
// Return: int numDigits
int numDigits(int num) {
    int numDigits = 0;
    // incriment numDigits while there are digits left
    while (num > 0) {
        num /= 10;
        ++numDigits;
    }
    return numDigits;
}

// Name: sumDigits()
// Desc: Gets the sum of all digits in input num
// Input: int num
// Output: none
// Return: int sum
int sumDigits(int num) {
    int sum = 0;
    int nextDigit = 0;

    // Loop while there are digits left
    while (num > 0) {
        // Extract and add last digit of num
        nextDigit = num % 10;
        sum += nextDigit;
        // remove last digit from num
        num /= 10;
    }

    return sum;
}

// Name: countEven()
// Desc: Gets the number of even digits in input num
// Input: int num
// Output: none
// Return: int numEven
int countEven(int num) {
    int nextDigit = 0;
    int numEven = 0;

    // Loop while there are digits left
    while (num > 0) {
        // Extract last digit from num
        nextDigit = num % 10;
        // Check if even and add to total
        if (nextDigit % 2 == 0) {
            ++numEven;
        }
        // Remove last digit from num
        num /= 10;
    }

    return numEven;
}

// Name: countOdd()
// Desc: Counts the number of odd digits in input num
// Input: int num, int &odd
// Output: none
// Return: none
void countOdd(int num, int &odd) {
    int nextDigit = 0;

    // Loop while there are digits left
    while (num > 0) {
        // Extract last digit from num
        nextDigit = num % 10;
        // Check if odd and add to total
        if (nextDigit % 2 != 0) {
            ++odd;
        }
        // Remove last digit from num
        num /= 10;
    }

}
