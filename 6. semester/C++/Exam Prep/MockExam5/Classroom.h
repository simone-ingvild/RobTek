#ifndef CLASSROOM_H
#define CLASSROOM_H

#include <vector>
#include <string>
#include "Student.h"

// Manages a list of students and generates reports
class Classroom {
private:
    std::vector<Student> students;

public:
    // Adds a student to the classroom
    void addStudent(const Student& s);

    // Parses quiz data from a stream (e.g., std::cin or file)
    void loadFromStream(std::istream& input);

    // Prints a sorted report of all students by total score (descending)
    void printReport() const;
};

#endif
