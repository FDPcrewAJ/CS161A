#include <iostream>
using namespace std;

// Main Function
int main() {
    
    // Initialize variables needed for input
    int employeeId = 0;
    int hoursWorked = 0;
    int hourlyRate = 0;
    int withholdRate = 0;
    // Initialize variables needed for calculations
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
    cout << "Payroll Summary" << endl;
    cout << "Total Gross Pay: $" << grossPay << endl;
    cout << "Federal Tax Withholding: $" << taxWithheld << endl;
    cout << "Net Pay: $" << netPay << endl;
    cout << "Thank you for using the Weekly Payroll Calculator!" << endl;
    
    return 0;
}