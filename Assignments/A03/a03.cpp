/**********************************************************************
# Author:       Aiden Jungels
# Assignment:   A03 (CS161A)
# Date:         10/10/2025
# Description:  This program will first ask the user if they have an 
#               account at the bank. If they answer no, the program 
#               will end with a goodbye message. If they answer yes, 
#               then it will ask for their account balance, and then 
#               give them the option to either deposit money into the 
#               account, withdraw money from the account, or exit the 
#               program. The program will then do whatever of the three 
#               options the user chooses.
# Input:        char accountStatus, int userAction, double 
#               accountBalance, double depositAmt, double withdrawAmt
# Output:       If the user deposits or withdraws money from their
#               account, the final account balance is displayed
#               If the user does not have an account, then a goodbye
#               message is displayed.
#               If the user enters an invalid input at any time,
#               the program notifies the user of this and ends.
# Sources:      CS Assigment 3 Doc, CS1 Algorithmic Design Doc,
#               Zybooks Chapter 3
**********************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

// Main funciton
int main() {

    // Variable Setup
    char accountStatus = ' ';
    int userAction = 0;
    double accountBalance = 0.0;
    double depositAmt = 0.0;
    double withdrawAmt = 0.0;

    // Set output precision
    cout << fixed << setprecision(2);

    // Welcome message and question
    cout << "Welcome to the ATM!" << endl;
    cout << endl << "Do you have an account with the bank? (Y/N): ";
    cin >> accountStatus;

    // Account status conditional
    if ((accountStatus == 'Y') || (accountStatus == 'y')) {
        // Display account options menu
        cout << "Please enter your initial account balance: $";
        cin >> accountBalance;
        cout << endl << "Main Menu:" << endl;
        cout << "1. Deposit Money" << endl;
        cout << "2. Withdraw Money" << endl;
        cout << "3. Exit" << endl;
        // Ask for users action
        cout << endl << "Choose an option (1-3): ";
        cin >> userAction;

        // User action conditional, deposit, withdraw, or exit
        if (userAction == 1) {
            // Get deposit amount
            cout << "Enter the amount to deposit: $";
            cin >> depositAmt;
            
            // Ensure deposit amount is positive
            if (depositAmt >= 0) {
                // If positive, add to account balance and return result
                accountBalance += depositAmt;
                cout << "Your new balance is: $" << accountBalance << "." << endl;
            }
            else {
                cout << "Error: Please enter a positive number" << endl;
            }
        }
        else if (userAction == 2) {
            // Get withdraw amount
            cout << "Enter the amount to withdraw: $";
            cin >> withdrawAmt;

            // Ensure withdraw amount is between 0-500
            if ((withdrawAmt >= 0) && (withdrawAmt <= 500)) {
                accountBalance -= withdrawAmt;
                
                // Make sure user has enough funds in account
                if (accountBalance >= 0) {
                    cout << "Your new balance is: $" << accountBalance << "." << endl;
                }
                else {
                    cout << "Error: Insufficient funds." << endl;
                }
            }
            else {
                cout << "Error: withdrawal amount must be greater than zero or less than the limit of $500" << endl;
            }
        }
        else if (userAction != 3) {
            // notify user of invalid ATM option
            cout << "Please enter a valid option" << endl;
        }
        // Display goodybe message
        cout << endl << "Thank you for using the ATM!" << endl;
    }
    else if (accountStatus == 'N' || accountStatus == 'n') {
        cout << "Thank you for your time. Please visit us when you have an account." << endl;
    }
    else {
        // Notify user of invalid input
        cout << "Please try again with a valid input" << endl;
    }
    
    return 0;
}