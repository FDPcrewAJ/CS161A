/**********************************************************************
# Author:       Aiden Jungels
# Assignment:   Midterm Practice
# Date:         10/21/2025
# Description:  This program will simulate a game of rock, paper, 
#               scissors between the user and computer. After asking 
#               for the user's name and their play, the program will 
#               generate a play for the computer, and then return who 
#               won the game to the user.
# Input:        string userName, char userPlay
# Output:       Will determine who won the game of rock paper scissors
#               by comparing plays, and then display either Its a
#               tie!, user wins!, or computer wins! depending on who
#               won the game. If the user enters an invalid play, then
#               they are asked to try again with a valid play.
# Sources:      None
**********************************************************************/
#include <iostream>
#include <cstdlib>
using namespace std;

// Main function
int main() {
    // Declare variables
    string userName = " ";
    char userPlay = ' ';
    char computerPlay = ' ';
    int randNum = 0;

    // Welcome message and get user name
    cout << "Play Rock Paper Scissors!" << endl;
    cout << endl << "Enter your name: ";
    getline(cin, userName);
    // Get and convert user play to lower case
    cout << endl << "What is your play " << userName << "?" << endl;
    cout << "Enter r, p, or s: ";
    cin >> userPlay;
    userPlay = tolower(userPlay);

    // Confirm valid user input and continue or end program
    if ((userPlay == 'r') || (userPlay == 'p') || (userPlay == 's')) {
        // Generate random computer play number
        srand(time(0));
        randNum = rand() % 3;
        // Assign computerPlay character based on generated number
        switch (randNum) {
            case 0:
                computerPlay = 'r';
                break;
            case 1:
                computerPlay = 'p';
                break;
            case 2:
                computerPlay = 's';
                break;
            default:
                cout << endl << "Computer play generation error. Please try again" << endl;
                return 0;
        }
        // Display computer play
        cout << "Computer plays: " << computerPlay << endl;
        // Compare computer and user plays and display tie or winner
        if (userPlay == computerPlay) {
            cout << endl << "Its a tie!" << endl;
        }
        else {
            // If not a tie, compare computers play with users play
            switch (computerPlay) {
                // rock looses to paper, wins to scissors
                case 'r':
                    if (userPlay == 'p') {
                        cout << endl << userName << " wins!" << endl;
                    }
                    else {
                        cout << endl << "Computer wins!" << endl;
                    }
                    break;
                // Paper loses to scissors, wins to rock
                case 'p':
                    if (userPlay == 's') {
                        cout << endl << userName << " wins!" << endl;
                    }
                    else {
                        cout << endl << "Computer wins!" << endl;
                    }
                    break;
                // Scissors loses to rock, wins to paper
                case 's':
                    if (userPlay == 'r') {
                        cout << endl << userName << " wins!" << endl;
                    }
                    else {
                        cout << endl << "Computer wins!" << endl;
                    }
                    break;
                // In case of error with comparison, print error message
                default:
                    cout << "Play comparison error. Please try again" << endl;
                    return 0;
            }
        }
        // Goodbye message
        cout << endl << "Thank you for playing!" << endl;
    }
    else {
        // Notify user of invalid input
        cout << endl << "Please try again with a valid play" << endl;
    }

    return 0;
}