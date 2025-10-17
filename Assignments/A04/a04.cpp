#include <iostream>
#include <string>
using namespace std;

// Main function
int main() {
    // Variable setup
    string phrase1;
    string phrase2;
    string subPhrase;

    // Display welcome message and get user input phrases
    cout << "Welcome to the phrases and subphrases program!" << endl;
    cout << "Enter phrase 1: ";
    cin >> phrase1;
    cout << "Enter phrase 2: ";
    cin >> phrase2;

    // Compare strings for any matches
    if (phrase1 == phrase2) {
        cout << endl << "Both phrases match!" << endl;
        cout << phrase1 << endl;
        cout << phrase2 << endl;
    }
    else {
        return 0;
    }

    // Display goodbye message
    cout << endl << "Thank you for using!" << endl;


    return 0;
}