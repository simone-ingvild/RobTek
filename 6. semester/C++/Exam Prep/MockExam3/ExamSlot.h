#ifndef EXAMSLOT_H
#define EXAMSLOT_H

#include <string>
#include <vector>

//Represents a time slot for an exam. Each slot has a name (e.g., "Math") and a limited capacity for students.
class ExamSlot {
    private:
        std::string name;                      // Name of the exam slot
        int capacity;                          // Maximum number of students allowed
        std::vector<std::string> assignedStudents; // Names of students assigned to this slot

    public:
        // Constructor: initializes name and capacity
        ExamSlot(std::string name, int cap);

        // Getter for exam slot name
        std::string getName() const;

        // Checks if the slot still has space for more students
        bool hasSpace() const;

        // Tries to assign a student by name; returns true if successful
        bool assignStudent(const std::string &studentName);

        // Prints the list of students assigned to this slot
        void printAssignments() const;
};

#endif // EXAMSLOT_H
