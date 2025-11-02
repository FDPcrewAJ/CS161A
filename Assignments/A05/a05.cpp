#include <iostream>
#include <iomanip>
using namespace std;

// Static variables
static int NUM_SLICES = 8;
static float SALES_TAX = 0.07;
static float DELIVERY_FEE = 0.20;

// Main function
int main() {

    // Delcare Variables
    // User input vars
    int numPeople = 0;
    float avgSlices = 0.0;
    float perPizzaCost = 0.0;
    char userTermination = ' ';
    // In loop output vars
    int numPizzasPerParty = 0;
    float pizzaCost = 0.0;
    float taxCost = 0.0;
    float deliveryCost = 0.0;
    float singlePartyCost = 0.0;
    // Accumulator vars
    int numParties = 0;
    int totalPizzas = 0;
    // Totals output vars
    float avgNumPizzas = 0.0;
    int maxNumPeople = 0;
    float avgPizzaCost = 0.0;

    // Welcome message
    cout << "Welcome to the Pizza Part Statistics Calculator!" << endl;

    // Do while loop to get user party input
    do {
        // Get user input
        cout << endl << "Enter the number of people, ";
        cout << "average number of slices per person, "; 
        cout << "and the cost of a pizza separated by a space: ";
        cin >> numPeople;
        cin >> avgSlices;
        cin >> perPizzaCost;
        
        // Calulate pizzas and prices
        // Calculate number of pizzas needed

        // Calculate cost of pizzas

        // Calculate tax

        // Calculate delivery

        // Calculate total cost

        // Determine if any maximums

        // Display results for a single party
        cout << setw(17) << left << endl << "Number of pizzas:" << " ";
        cout << numPizzasPerParty << endl;
        cout << setw(17) << left << "Cost of pizzas:" << "$";
        cout << pizzaCost << endl;
        cout << setw(17) << left << "Tax:" << "$";
        cout << taxCost << endl;
        cout << setw(17) << left << "Delivery:" << "$";
        cout << deliveryCost << endl;
        cout << setw(17) << left << "Total cost:" << "$";
        cout << singlePartyCost << endl;

        // Increase accumulators
        totalPizzas += numPizzasPerParty;
        numParties++;

        // Ask for more inputs
        cout << endl << "Do you want to enter more? (y/n): ";
        cin >> userTermination;

    } 
    while (userTermination == 'y');

    cout << numParties;

    return 0;
}