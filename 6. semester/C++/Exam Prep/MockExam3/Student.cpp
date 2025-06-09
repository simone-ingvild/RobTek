#include "Student.h"

//Constructor to initialize student data: name, username, and preferences.
Student::Student(std::string name, std::string username, std::vector<std::string> prefs)
    : name(name), username(username), preferences(prefs), assigned(false) {}

//Returns the username of the student.
std::string Student::getUsername() const {
    return username;
}

//Returns the full name of the student.
std::string Student::getName() const {
    return name;
}

//Returns true if the student has already been assigned to an exam slot.
bool Student::isAssigned() const {
    return assigned;
}

//Attempts to assign the student to one of their preferred exam slots.
//Tries each preference in order and stops at the first successful assignment.
bool Student::tryAssign(std::vector<ExamSlot> &slots) {
    for (auto &pref : preferences) {
        for (auto &slot : slots) {
            if (slot.getName() == pref && slot.assignStudent(name)) {
                assigned = true;
                return true; // Assignment successful
            }
        }
    }
    return false; // No available preferred slot
}
