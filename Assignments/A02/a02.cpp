#include <iostream>
using namespace std;

// Constant variables
const int OREOS_PER_SERVING = 5;
const int CALORIES_PER_SERVING = 160;

// Main funciton
int main() {
    // Variable setup
    int numOreos = 0;
    float numServings = 0.0;
    float numCalroies = 0.0;

    // Welcome Message and oreos eaten input
    cout << "Oreo Calculator" << endl;
    cout << endl << "Enter the number of Oreos eaten: ";
    cin >> numOreos;

    // Calculate number of servings
    numServings = static_cast<double>(numOreos) / OREOS_PER_SERVING;
    // Calculate number of calroies eaten
    numCalroies = numServings * CALORIES_PER_SERVING;

    // Display results
    cout << endl << "Number of servings eaten: " << numServings << endl;
    cout << "Number of calories consumed: " << numCalroies << endl;
    // Goodbye message
    cout << endl << "Thank you for using!" << endl;

    return 0;
}