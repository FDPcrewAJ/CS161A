/**********************************************************************
# Author:       Aiden Jungels
# Assignment:   A07 (CS161A)
# Date:         11/11/2025
# Description:  This program will read the number of assignments and 
#               scores on each one from the user, followed by the 
#               midterm and final exam grade. It will then calculate 
#               the users final numeric score as well as letter grade, 
#               and display that information to the user.
# Input:        int numAssignments, double assignmentAvg,
#               double midtermExam, double finalExam
# Output:       double finalGrade, double finalExam
# Sources:      CS Assigment 7 Doc, CS1 Algorithmic Design Doc,
#               Zybooks Chapter 7, Assignment 7 sample code
**********************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const double ASSIGNMENT_WEIGHT = 0.6;
const double EXAM_WEIGHT = 0.2;

// Function prototypes
void welcome();
int readInt(string prompt);
double readScore(string prompt);
double assignAverage(int numAssigns);
double calcFinalScore(double assignAvg, double midterm, double final);
char calcLetterGrade(double finalScore);

// Main Function
int main() {
    // Delcare input variables
    int numAssignments = 0;
    double assignmentAvg = 0.0;
    double midtermExam = 0.0;
    double finalExam = 0.0;
    // Declare output variables
    double finalGrade = 0.0;
    char gradeLetter = ' ';
    
    // Call welcome function
    welcome();

    // Get number of assignments
    numAssignments = readInt("Enter the number of assignments (0 to 10): ");
    
    // Read assignment, midterm, and final exam Scores
    assignmentAvg = assignAverage(numAssignments);
    cout << endl;
    midtermExam = readScore("Enter your midterm exam score: ");
    finalExam = readScore("Enter your final exam score: ");

    // Calculate number grade
    finalGrade = calcFinalScore(assignmentAvg, midtermExam, finalExam);

    // Calculate letter grade
    gradeLetter = calcLetterGrade(finalGrade);

    // Display grade results
    cout << endl << "Your final score is: " << finalGrade << endl;
    cout << "Your final grade is: " << gradeLetter << endl;

    // Goodybe messsage
    cout << endl << "Thank you for using the grade calculator!" << endl;

    return 0;
}

// Name: welcome()
// Desc: Displays welcome message and program info
// Input: none
// Output: welcome message/program info
// Return: none
void welcome() {
    cout << fixed << setprecision(1);
    cout << "Welcome to the Grade Calculator!" << endl;
    cout << "Enter the following information to find out what your grade is!" << endl;
    cout << "The number of assignments must be between 0 and 10." << endl;
    cout << "All scores must be between 0 and 4." << endl;
    cout << endl;
}

// Name: readInt()
// Desc: Reads input with prompt, validates integer between 0-10
// Input: string prompt
// Output: Input prompt, Maybe error message
// Return: int input
int readInt(string prompt) {
    int input;
    cout << prompt;
    cin >> input;
    
    // Validate input, request new if not valid
    while ((!cin) || (input < 0) || (input > 10)) {
        cout << "Invalid Input! Please try again" << endl;
        cout << prompt;
        cin.clear();
        cin.ignore(100, '\n');
        cin >> input;
    }
    return input;
}

// Name: readScore()
// Desc: Reads assignment score and confirms its within range
// Input: string prompt
// Output: input prompt, maybe error message
// Return: double input
double readScore(string prompt) {
    double input;
    cout << prompt;
    cin >> input;
    
    // Validate input, request new if not valid
    while ((!cin) || (input < 0) || (input > 4)) {
        cout << "Invalid Input! Please try again" << endl;
        cout << prompt;
        cin.clear();
        cin.ignore(100, '\n');
        cin >> input;
    }
    return input;
}

// Name: assignAverage()
// Desc: gets the total score of all assignments and calculate average
// Input: int numAssigns
// Output: input prompt, outputs from readScore() function
// Return: double average
double assignAverage(int numAssigns) {
    double totalPoints = 0.0;
    double average = 0.0;
    string prompt;
    
    // ask for assignment score numAssignments times
    for (int i = 1; i <= numAssigns; ++i) {
        prompt = "Enter Score " + to_string(i) + ": ";
        totalPoints += readScore(prompt);
    }
    // Calculate and return grade average
    average = totalPoints / numAssigns;
    return average;
}

// Name: calcFinalScore()
// Desc: Finds final number score with given scores
// Input: double assignAvg, double midterm, double final
// Output: None
// Return: double finalScore
double calcFinalScore(double assignAvg, double midterm, double final) {
    double finalScore = 0.0;

    // Calculate individual grades with percentage weight applied
    assignAvg *= ASSIGNMENT_WEIGHT;
    midterm *= EXAM_WEIGHT;
    final *= EXAM_WEIGHT;

    // Calculate total final score
    finalScore = assignAvg + midterm + final;
    
    return finalScore;
}

// Name: calcLetterGrade()
// Desc: Converts number grade to letter grade
// Input: double finalScore
// Output: None
// Return: char letterGrade
char calcLetterGrade(double finalScore) {
    char letterGrade = 'F';

    // Compare final score to grade bounds to determine grade
    if (finalScore >= 3.3) {
        letterGrade = 'A';
    }
    else if (finalScore >= 2.8) {
        letterGrade = 'B';
    }
    else if (finalScore >= 2.0) {
        letterGrade = 'C';
    }
    else if (finalScore >= 1.2) {
        letterGrade = 'D';
    }
    
    return letterGrade;
}