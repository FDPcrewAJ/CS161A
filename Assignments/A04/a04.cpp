/**********************************************************************
# Author:       Aiden Jungels
# Assignment:   A04 (CS161A)
# Date:         10/16/2025
# Description:  This program will ask the user for two phrases, then 
#               compare the two to find if: A. The two phrases match, 
#               B. Phrase 1 is found in phrase 2, C, Phrase 2 is found 
#               if phrase 1, D. No matches. Then return the result to 
#               the user with the matching phrases outputted.
# Input:        string phrase1, string phrase2
# Output:       If the phrases match, then a message is displayed 
#               stating so. If phrase1 is in phrase2, then the user
#               is notified, and the starting location of the phrase
#               is output. If phrase2 is in phrase1, then the user
#               is notified, and the starting location of the phrase
#               is output. 
# Sources:      CS Assigment 3 Doc, CS1 Algorithmic Design Doc,
#               Zybooks Chapter 4
**********************************************************************/
#include <iostream>
#include <string>
using namespace std;

// Main function
int main() {
    // Variable setup
    string phrase1;
    string phrase2;
    string subPhrase;
    int matchLocation;

    // Display welcome message
    cout << "Welcome to the phrases and subphrases program!" << endl;
    // Get and echo user input phrases
    cout << endl << "Enter phrase 1: ";
    getline(cin, phrase1);
    cout << "You entered: " << phrase1 << endl;
    cout << "Enter phrase 2: ";
    getline(cin, phrase2);
    cout << "You entered: " << phrase2 << endl;

    // Compare if strings are the same
    if (phrase1 == phrase2) {
        cout << endl << "Both phrases match!" << endl;
        cout << phrase1 << endl;
        cout << phrase2 << endl;
    }
    // If strings are different, check for phrase within
    else {
        matchLocation = phrase1.find(phrase2, 0);
        // Check if phrase2 is in phrase1 (else executes if true)
        if (matchLocation == string::npos) {
            matchLocation = phrase2.find(phrase1, 0);
            // Check if phrase1 is in phrase2
            if (matchLocation == string::npos) {
                // Display no matches if there are none
                cout << endl << "No match in phrases" << endl;
            }
            // When phrase1 is in phrase2, display info to user
            else {
                cout << endl << "'" << phrase1 << "' is found in '" << phrase2 << "'" << endl;
                subPhrase = phrase2.substr(matchLocation);
                cout << subPhrase << endl;
            }
        }
        // When phrase2 is in phrase1, display info to user
        else {
            cout << endl << "'" << phrase2 << "' is found in '" << phrase1 << "'" << endl;
            subPhrase = phrase1.substr(matchLocation);
            cout << subPhrase << endl;
        }
    }
    // Display goodbye message
    cout << endl << "Thank you for using!" << endl;

    return 0;
}