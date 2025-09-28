/**********************************************************************
# Author:       Aiden Jungels
# Assignment:   A01 (CS161A)
# Date:         9/27/25
# Description:  This program will read the employee’s ID, number of 
#               hours worked, hourly wage, and federal withholding 
#               rate. Then it will calculate the total gross pay, 
#               Income tax withholding, and net pay, then print that 
#               out to the console for the user to see.
# Input:        int: employeeId
#               int: hoursWorked
#               int: hourlyRate
#               int: withholdRate
# Output:       Displays the total gross pay, federal tax withholding,
#               and net pay each on individual lines folowed by a
#               goodbye message
# Sources:      CS Assigment 1 Doc, CS1 Algorithmic Design Document
**********************************************************************/

#include <iostream>
using namespace std;

// Main Function
int main() {
    
    // Initialize variables needed for input and calculations
    int employeeId = 0;
    int hoursWorked = 0;
    int hourlyRate = 0;
    int withholdRate = 0;
    int grossPay = 0;
    int taxWithheld = 0;
    int netPay = 0;

    // Display welcome messsage
    cout << "Weekly Payroll Calculator (Input whole numbers only)" << endl;
    
    // Get user input data
    cout << "Enter your employee ID number: ";
    cin >> employeeId;
    cout << "Enter number of hours worked: ";
    cin >> hoursWorked;
    cout << "Enter your hourly rate: ";
    cin >> hourlyRate;
    cout << "Enter the federal withholding rate: ";
    cin >> withholdRate;

    // Calculate gross pay, tax withheld, and net pay
    grossPay = hoursWorked * hourlyRate;
    taxWithheld = withholdRate / 100.0 * grossPay;
    netPay = grossPay - taxWithheld;

    // Display calculated pay results
    cout << endl << "Payroll Summary" << endl;
    cout << "Total Gross Pay: $" << grossPay << endl;
    cout << "Federal Tax Withholding: $" << taxWithheld << endl;
    cout << "Net Pay: $" << netPay << endl;

    // Display goodbye message
    cout << endl << "Thank you for using the Weekly Payroll Calculator!" << endl;
    
    return 0;
}