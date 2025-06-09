#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
using namespace std;

// Represents a student and their assigned exams
class Student{
    private:
        string name;      // Student's name
        string username;  // Student's username
        string exam1;     // Assigned exam 1
        string exam2;     // Assigned exam 2
    
    public:
        Student(const string& name, const string& username);    // Constructor
        void setExam1(const string& exam);                      // Set exam 1
        void setExam2(const string& exam);                      // Set exam 2
        void print(ostream& os) const;                          // Print student info

};

#endif