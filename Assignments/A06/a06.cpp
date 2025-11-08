#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Main Function
int main() {
    // Input variables
    int coinInput = 0;
    char itemAmount = ' ';
    char itemOrder = ' ';
    // Output variables
    int userChange = 0;
    int itemCost = 0;
    int endBalance = 0;
    // Calculation variables
    bool insufficientFunds = true;
    bool validChoice = false;

    cout << "Welcome to the Coffee/Tea Vending Machine!" << endl;

    // Main program loop
    do {
        // Get coin inputs until done, display balance
        cout << endl << "Enter coins - 5, 10, or 25 only, one at a time. Enter 0 to stop." << endl;
        do {
            cout << "Enter coin: ";
            cin >> coinInput;
            userChange += coinInput;
        } while (coinInput != 0);
        cout << "Your balance is $0." << userChange << endl;

        // Display menu
        cout << "Please pick an option ($0.25 each):" << endl;
        cout << "\tC/c: Coffee" << endl;
        cout << "\tT/t: Tea" << endl;
        cout << "\tQ/q: Quit" << endl;
        cout << ">> ";
        
        // Get user input, confirm valid choice
        do {
            validChoice = false;
            cin >> itemOrder;
            itemOrder = tolower(itemOrder);
            if ((itemOrder == 'c') || (itemOrder == 't') || (itemOrder == 'q')) {
                validChoice = true;
            }
            else {
                cout << "Invalid option! Please choose a valid option." << endl;
                cout << ">> ";
            }
        } while (!validChoice);

        // End program if user chooses
        if (itemOrder == 'q') {
            insufficientFunds = false;
            continue;
        }

        // Ask for number of items
        cout << "How many would you like?" << endl;
        cout << ">> ";
        do {
            cin >> itemAmount;
            if (isdigit(itemAmount)) {

            }
            else {
                cout << "Invalid option! Please choose a valid option." << endl;
                cout << ">> ";
            }
        } while (condition);
        

        // End program
        //insufficientFunds = false;
    } while (insufficientFunds);

    cout << endl << "Thank you for using my Vending Machine Program!" << endl;
    

    return 0;
}