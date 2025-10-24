/******************************************************************************
# Author:          Aiden Jungels and Tucker Creek
# Lab:               Discussion #4
# Date:             October 24th, 2025
# Description:   This program will take the users first and last name,
#		  and a 4 number integer and create a user name	
# Input:            string firstName and lastName, int num
# Output:           string userName
# Sources:          zybooks chapter 4
#******************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

// Main function
int main() {
    // Declare variables
    string firstName = " ";
    string lastName = " ";
    int num = 0;
    string userName = " ";

    // Get user input and input to variables
    cout << "Enter your name and a 4 digit number: ";
    cin >> firstName;
    cin >> lastName;
    cin >> num;

    // Get last 2 digits of number provided
    num %= 100;

    // Get the first 5 char of the users last name
    if (lastName.length() >= 5) {
        userName = lastName.substr(0,5);
    }
    // Get all of the users last name if it is 5 or less char
    else {
        userName = lastName;
    }

    // Add the first letter of first name to userName
    userName += firstName.substr(0,1);
    // Add last 2 digits of num to userName
    userName += to_string(num);

    // Display userName
    cout << endl << "Your username: " << userName << endl;
    
    return 0;
}