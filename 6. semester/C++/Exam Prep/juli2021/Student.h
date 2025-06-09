#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include <iostream>
#include "Bin.h"

// Represents a student who draws one ticket (exam index) from a Bin
class Student {
public:
    Student();                                                      // Default constructor
    Student(const std::string& name, const std::string& username);  // Construct with identity

    // Draws a ticket from the bin and stores the result
    void draw(Bin& bin);

    // Maps the stored ticket value to an exam name
    std::string getExam(const std::vector<std::string>& exams) const;

    // Accessors / mutators
    std::string getName() const;
    void        setName(const std::string& name);

    std::string getUsername() const;
    void        setUsername(const std::string& username);

    // Stream insertion: "Name (username)"
    friend std::ostream& operator<<(std::ostream& os, const Student& student);

private:
    std::string mName;
    std::string mUsername;
    int         mExam = -1;  // -1 indicates no draw yet
};

#endif // STUDENT_H
