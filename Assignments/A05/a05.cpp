/**********************************************************************
# Author:       Aiden Jungels
# Assignment:   A05 (CS161A)
# Date:         11/1/2025
# Description:  This program will ask the user for the number of 
#               people attending a party, average number of slices per 
#               person, and the cost of a pizza, then calculate the 
#               total cost of the pizza with tax and delivery included, 
#               in a do while loop, allowing the user to enter data for 
#               as many parties as they choose. Once done entering data, 
#               the program will display the number of entries, total 
#               number of pizzas, average number of pizzas between all 
#               parties, and maximum number of people and pizza cost 
#               of a party.
# Input:        int numPeople, float avgSlices, float perPizzaCost,
#               char userTermination
# Output:       In each while iteration: outputs the number of pizzas
#               needed, cost of pizzas, cost of tax, cost of delivery
#               and total cost
#               Once while loop is exited: outputs the number of
#               parties, total number of pizzas from all parties,
#               average number of pizzas for all parties, max number
#               of people of all parties, and max cost of pizza of 
#               all parties
# Sources:      CS Assigment 5 Doc, CS1 Algorithmic Design Doc,
#               Zybooks Chapter 5
**********************************************************************/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Static variables
static int SLICES_PER_PIZZA = 8;
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
    float partyPizzaCost = 0.0;
    float taxCost = 0.0;
    float deliveryCost = 0.0;
    float singlePartyCost = 0.0;
    // Accumulator vars
    int numParties = 0;
    // Totals output vars
    int totalPizzas = 0;
    float avgNumPizzas = 0.0;
    int maxNumPeople = 0;
    float maxPizzaCost = 0.0;

    // Welcome message
    cout << "Welcome to the Pizza Party Statistics Calculator!" << endl;

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
        numPizzasPerParty = ceil((numPeople * avgSlices) / SLICES_PER_PIZZA);
        // Calculate cost of pizzas
        partyPizzaCost = numPizzasPerParty * perPizzaCost;
        // Calculate tax
        taxCost = partyPizzaCost * SALES_TAX;
        // Calculate delivery
        deliveryCost = (partyPizzaCost + taxCost) * DELIVERY_FEE;
        // Calculate total cost
        singlePartyCost = partyPizzaCost + taxCost + deliveryCost;
        
        // Determine if any maximums
        if (numPeople > maxNumPeople) {
            maxNumPeople = numPeople;
        }
        if (singlePartyCost > maxPizzaCost) {
            maxPizzaCost = singlePartyCost;
        }
        
        // Display results for a single party
        cout << fixed << setprecision(2);
        cout << setw(17) << left << endl << "Number of pizzas:" << " ";
        cout << numPizzasPerParty << endl;
        cout << setw(17) << left << "Cost of pizzas:" << "$";
        cout << partyPizzaCost << endl;
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

    // Calculate averages
    avgNumPizzas = static_cast<float>(totalPizzas) / numParties;
    
    // Display totals
    cout << endl << "Number of parties: " << numParties << endl;
    cout << "Total number of pizzas: " << totalPizzas << endl;
    cout << fixed << setprecision(1);
    cout << "Average number of pizzas: " << avgNumPizzas << endl;
    cout << "Maximum number of people: " << maxNumPeople << endl;
    cout << fixed << setprecision(2);
    cout << "Maximum cost of pizzas: $" << maxPizzaCost << endl;

    // Goobye message
    cout << endl << "Thank you for using the Pizza Party Statistics Calculator!" << endl;

    return 0;
}