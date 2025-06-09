#include "ExamScheduler.h"
#include <iostream>

//Adds a new student to the internal student list.
void ExamScheduler::addStudent(const Student &s) {
    students.push_back(s);
}

//Adds a new exam slot to the internal exam slot list.
void ExamScheduler::addSlot(const ExamSlot &slot) {
    slots.push_back(slot);
}

//Attempts to assign each student to one of their preferred exam slots.
void ExamScheduler::assignAll() {
    for (auto &student : students) {
        student.tryAssign(slots);
    }
}

//Prints all exam slots and the students assigned to each.
//Also lists students who could not be assigned to any slot.
void ExamScheduler::printResults() const {
    for (const auto &slot : slots) {
        slot.printAssignments();
    }

    std::cout << "\nUnassigned Students:\n";
    for (const auto &student : students) {
        if (!student.isAssigned()) {
            std::cout << " - " << student.getName() << "\n";
        }
    }
}
