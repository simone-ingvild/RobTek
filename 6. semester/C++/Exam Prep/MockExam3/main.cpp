#include <iostream>
#include "ExamScheduler.h"

int main() {
    ExamScheduler scheduler;

    //Add exam slots with capacities
    scheduler.addSlot(ExamSlot("Math", 2));
    scheduler.addSlot(ExamSlot("Physics", 1));
    scheduler.addSlot(ExamSlot("Chemistry", 1));

    //Add students with name, username, and exam preferences
    scheduler.addStudent(Student("Alice", "alice01", {"Math", "Physics"}));
    scheduler.addStudent(Student("Bob", "bob77", {"Physics", "Math"}));
    scheduler.addStudent(Student("Charlie", "charlieC", {"Chemistry", "Math"}));
    scheduler.addStudent(Student("Diana", "didi", {"Math"}));
    scheduler.addStudent(Student("Ethan", "ethanE", {"Math"}));  // This one should fail

    //Assign all students to their preferred slots
    scheduler.assignAll();

    //Display final results
    scheduler.printResults();

    return 0;
}
