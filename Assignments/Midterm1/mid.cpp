/**********************************************************************
# Author:       Aiden Jungels
# Assignment:   Midterm
# Date:         10/25/2025
# Description:  This program will get the names and number of rocks 
#               collected from 3 competitors, then compare them to 
#               find out who collected the most, middle, and least 
#               amount of rocks. If there is a tie, then the 
#               corresponding players will be displayed as tied. It 
#               will then print out the average amount of rocks 
#               collected between all players.
# Input:        string p1Name, string p2Name, string p3Name,
#               int score1, int score2, int score3
# Output:       Outputs who came in first, second and last place
#               based on the number of rocks gathered. 2 and 3 way
#               ties are accounted for.
# Sources:      None
**********************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

// Declare constant variables
const int NUM_PLAYERS = 3;

// Main function
int main() {
    // Variable setup
    string p1Name = " ";
    string p2Name = " ";
    string p3Name = " ";
    int score1 = 0;
    int score2 = 0;
    int score3 = 0;
    float avgRocksCollected = 0.0;

    // Welcome message
    cout << "Welcome to the Rock Collector Championships!" << endl;

    // Get player 1 data
    cout << endl << "Enter player 1 name: ";
    getline(cin, p1Name);
    cout << "How many rocks did " << p1Name << " collect?: ";
    cin >> score1;
    cin.get();
    if (score1 < 0) {
        cout << "Invalid amount. 0 will be entered." << endl;
        score1 = 0;
    }

    // Get player 2 data
    cout << endl << "Enter player 2 name: ";
    getline(cin, p2Name);
    cout << "How many rocks did " << p2Name << " collect?: ";
    cin >> score2;
    cin.get();
    if (score2 < 0) {
        cout << "Invalid amount. 0 will be entered." << endl;
        score2 = 0;
    }

    // Get player 3 data
    cout << endl << "Enter player 3 name: ";
    getline(cin, p3Name);
    cout << "How many rocks did " << p3Name << " collect?: ";
    cin >> score3;
    cin.get();
    if (score3 < 0) {
        cout << "Invalid amount. 0 will be entered." << endl;
        score3 = 0;
    }
    cout << endl;
    
    // Check if all scores are tried
    if ((score1 == score2) && (score1 == score3)) {
        cout << "It's a three way tie!" << endl;
    }
    // otherwise sheck if any 2 scores are tied
    else if (score1 == score2) {
        if (score1 > score3) {
            // 1 and 2 first, 3 second
            cout << p1Name << " and " << p2Name << " are tied for first!" << endl;
            cout << p3Name << " is in second place!" << endl;
        }
        else {
            // 3 first, 1 and 2 second
            cout << p3Name << " is in first place!" << endl;
            cout << p1Name << " and " << p2Name << " are tied for second!" << endl;
        }
    }
    else if (score1 == score3) {
        if (score1 > score2) {
            // 1 and 3 first, 2 second
            cout << p1Name << " and " << p3Name << " are tied for first!" << endl;
            cout << p2Name << " is in second place!" << endl;
        }
        else {
            // 2 first, 1 and 3 second
            cout << p2Name << " is in first place!" << endl;
            cout << p1Name << " and " << p3Name << " are tied for second!" << endl;
        }
    }
    else if (score2 == score3) {
        if (score2 > score1) {
            // 2 and 3 first, 1 second
            cout << p2Name << " and " << p3Name << " are tied for first!" << endl;
            cout << p1Name << " is in second place!" << endl;
        }
        else {
            // 1 first, 2 and 3 second
            cout << p1Name << " is in first place!" << endl;
            cout << p2Name << " and " << p3Name << " are tied for second!" << endl;
        }
    }
    // If no scores are tied, find first place, then second and last
    else if ((score1 > score2) && (score1 > score3)) {
        cout << p1Name << " is in first place!" << endl;
        // check placement of players 2 and 3
        if (score2 > score3) {
            cout << p2Name << " is in second place!" << endl;
            cout << p3Name << " is in third place!" << endl;
        }
        else {
            cout << p3Name << " is in second place!" << endl;
            cout << p2Name << " is in third place!" << endl;
        }
    }
    else if ((score2 > score1) && (score2 > score3)) {
        cout << p2Name << " is in first place!" << endl;
        // check placement of players 1 and 3
        if (score1 > score3) {
            cout << p1Name << " is in second place!" << endl;
            cout << p3Name << " is in third place!" << endl;
        }
        else {
            cout << p3Name << " is in second place!" << endl;
            cout << p1Name << " is in third place!" << endl;
        }
    }
    else if ((score3 > score1) && (score3 > score2)) {
        cout << p3Name << " is in first place!" << endl;
        // check placement of players 1 and 2
        if (score1 > score2) {
            cout << p1Name << " is in second place!" << endl;
            cout << p2Name << " is in third place!" << endl;
        }
        else {
            cout << p2Name << " is in second place!" << endl;
            cout << p1Name << " is in third place!" << endl;
        }
    }

    // Calculate and display the average number of rocks collected
    avgRocksCollected = static_cast<double>((score1 + score2 + score3)) / NUM_PLAYERS;
    cout << fixed << setprecision(2);
    cout << endl << "The average number of rocks collected by everyone is ";
    cout << avgRocksCollected << " rocks!" << endl;

    // Display goodbye message
    cout << endl << "Congratulations Rock Collectors!" << endl;

    return 0;
}