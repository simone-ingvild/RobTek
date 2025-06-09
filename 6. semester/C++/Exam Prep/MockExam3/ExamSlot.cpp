#include "ExamSlot.h"
#include <iostream>

//Constructor for ExamSlot, Initializes the exam name and the max number of students it can hold.
ExamSlot::ExamSlot(std::string name, int cap) : name(name), capacity(cap) {}

//Returns the name of the exam slot.
std::string ExamSlot::getName() const {
    return name;
}

//Returns true if the number of assigned students is less than capacity.
bool ExamSlot::hasSpace() const {
    return assignedStudents.size() < capacity;
}


//Tries to assign a student to this slot. Returns true if successful, false if the slot is already full.
bool ExamSlot::assignStudent(const std::string &studentName) {
    if (hasSpace()) {
        assignedStudents.push_back(studentName); // Add student to the slot
        return true;
    }
    return false; // No space left
}

//Prints the list of students assigned to this slot.
void ExamSlot::printAssignments() const {
    std::cout << "ExamSlot: " << name << "\n";
    for (const auto &s : assignedStudents) {
        std::cout << " - " << s << "\n";
    }
}
