#ifndef EXAMSCHEDULER_H
#define EXAMSCHEDULER_H

#include <vector>
#include "Student.h"
#include "ExamSlot.h"

//Manages the scheduling of students into available exam slots.
class ExamScheduler {
private:
    std::vector<Student> students; //List of all registered students
    std::vector<ExamSlot> slots;   //List of all available exam slots

public:
    //Adds a new student to the list.
    void addStudent(const Student &s);

    //Adds a new exam slot to the list.
    void addSlot(const ExamSlot &slot);

    //Attempts to assign all students to their preferred slots.
    void assignAll();

    //Prints which students were assigned to which slots and lists unassigned students.
    void printResults() const;
};

#endif
