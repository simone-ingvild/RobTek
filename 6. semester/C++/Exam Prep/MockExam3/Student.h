#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include "ExamSlot.h"

//Represents a student with a name, username, and exam preferences.
class Student {
    private:
        std::string name;                       // Full name of the student
        std::string username;                   // Unique username (e.g., for login)
        std::vector<std::string> preferences;   // Ordered list of preferred exam slots
        bool assigned;                          // Tracks if the student has been assigned to a slot

    public:
        //Constructor to initialize student data: name, username, and preference list.
        Student(std::string name, std::string username, std::vector<std::string> prefs);

        //Returns the username of the student.
        std::string getUsername() const;

        //Returns the name of the student.
        std::string getName() const;

        //Returns true if the student has already been assigned to an exam slot.
        bool isAssigned() const;

        //Attempts to assign the student to a preferred slot from the list.
        bool tryAssign(std::vector<ExamSlot> &slots);
};

#endif
