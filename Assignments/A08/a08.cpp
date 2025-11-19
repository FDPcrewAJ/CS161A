/**********************************************************************
# Author:       Aiden Jungels
# Assignment:   A08 (CS161A)
# Date:         11/19/2025
# Description:  This program will read the number of assignments and 
#               scores on each one from the user, followed by the 
#               midterm and final exam grade. It will then calculate 
#               the user's final numeric score as well as letter grade, 
#               and display that information to the user.
# Input:        int numAssignments, double num,
# Output:       double finalGrade, double letter
# Sources:      CS Assigment 8 Doc, CS1 Algorithmic Design Doc,
#               Zybooks Chapter 8, Assignment 8 sample code
**********************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

const double ASSIGNMENT_WEIGHT = 0.6;
const double EXAM_WEIGHT = 0.2;

// Function prototypes
void welcome();
int readInt(string prompt);
void readScore(string prompt, double &num);
double assignAverage(int numAssigns);
void getInput(double &midtermScore, double &finalExamScore);
double calcFinalScore(double assignAvg, double midterm, double final);
void calcLetterGrade(double finalScore, char &letter);

// Main Function
int main() {
    // Reference variables
    double num = 0.0;
    double midtermScore = 0.0;
    double finalExamScore = 0.0;
    char letter = ' ';
    // Input variables
    int numAssignments = 0;
    // Output variables
    double assignAvg = 0.0;
    double finalGrade = 0.0;

    // Display welcome message
    welcome();

    // Get the number of assignments
    numAssignments = readInt("Enter the number of assignments (0 to 10): ");

    // Get assignment average
    assignAvg = assignAverage(numAssignments);

    // Get midterm and final exam scores
    getInput(midtermScore, finalExamScore);

    // Calculate number grade and letter grade
    finalGrade = calcFinalScore(assignAvg, midtermScore, finalExamScore);
    calcLetterGrade(finalGrade, letter);

    // Display grade results
    cout << endl << "Your final score is: " << finalGrade << endl;
    cout << "Your final grade is: " << letter << endl;

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
// Desc: Reads and assigns assignment score and confirms its within range
// Input: string prompt, double &num
// Output: input prompt, maybe error message
// Return: none
void readScore(string prompt, double &num) {
    cout << prompt;
    cin >> num;

    // Validate correct input
    while ((!cin) || (num < 0) || (num > 4)) {
        cout << "Invalid Input! Please try again" << endl;
        cout << prompt;
        cin.clear();
        cin.ignore(100, '\n');
        cin >> num;
    }
}

// Name: assignAverage()
// Desc: gets the total score of all assignments and calculate average
// Input: int numAssigns
// Output: input prompt
// Return: double average
double assignAverage(int numAssigns) {
    double totalPoints = 0.0;
    double average = 0.0;
    double currentScore = 0.0;
    string prompt;
    
    // ask for assignment score numAssignments times
    for (int i = 1; i <= numAssigns; ++i) {
        prompt = "Enter Score " + to_string(i) + ": ";
        readScore(prompt, currentScore);
        totalPoints += currentScore;
    }
    // Calculate and return grade average
    average = totalPoints / numAssigns;
    return average;
}

// Name: getInput
// Desc: gets the scores of the midterm and final exam
// Input: double &midtermScore, double &finalExamScore
// Output: Midterm/final exam prompts
// Return: none
void getInput(double &midtermScore, double &finalExamScore) {
    cout << endl;
    readScore("Enter your midterm exam score: ", midtermScore);
    readScore("Enter your final exam score: ", finalExamScore);
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
// Input: double finalScore, char &letter
// Output: None
// Return: none
void calcLetterGrade(double finalScore, char &letter) {
    letter = 'F';

    // Compare final score to grade bounds to determine grade
    if (finalScore >= 3.3) {
        letter = 'A';
    }
    else if (finalScore >= 2.8) {
        letter = 'B';
    }
    else if (finalScore >= 2.0) {
        letter = 'C';
    }
    else if (finalScore >= 1.2) {
        letter = 'D';
    }
}