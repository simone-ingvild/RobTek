#include <iostream>
using namespace std;

/* Group 1: Conditional Logic (if, else if) 
Get an exam score and print a basic grade (if-else).
Extend to use else-if for finer grading (A-, B+, etc.). */

int main(){
    int score;

    // Ask user for their score
    cout << "Enter exxam score (0-100): ";
    cin >> score;

    // Check if the score is valid
    if (score < 0 || score > 100) {
        cout << "Invalid score. Please enter a score between 0 and 100." << endl;
    } else {
         // Use if-else if to assign a grade
        if (score >= 97) {
            cout << "Grade: A+" << endl;
        } else if (score >= 93) {
            cout << "Grade: A" << endl;
        } else if (score >= 90) {
            cout << "Grade: A-" << endl;
        } else if (score >= 87) {
            cout << "Grade: B+" << endl;
        } else if (score >= 83) {
            cout << "Grade: B" << endl;
        } else if (score >= 80) {
            cout << "Grade: B-" << endl;
        } else if (score >= 77) {
            cout << "Grade: C+" << endl;
        } else if (score >= 73) {
            cout << "Grade: C" << endl;
        } else if (score >= 70) {
            cout << "Grade: C-" << endl;
        } else if (score >= 60) {
            cout << "Grade: D" << endl;
        } else {
            cout << "Grade: F" << endl;
        }
    }

    return 0;
}