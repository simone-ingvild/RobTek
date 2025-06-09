#ifndef COURSE_LOTTERY_H
#define COURSE_LOTTERY_H

#include "student.h"
#include "bin.h"
#include <vector>
#include <string>

// Manages the course lottery process for students
class CourseLottery {
private:
    std::vector<Student> students;  // List of students
    Bin bin1;                       // Bin for first exam round
    Bin bin2;                       // Bin for second exam round

public:
    CourseLottery(unsigned int seed = 42);                                  // Constructor with random seed
    void addStudent(const std::string& name, const std::string& username);  // Add a student
    void runLottery(const std::vector<std::string>& subjects1,
                    const std::vector<std::string>& subjects2);             // Assign exams
    void printResults(std::ostream& os) const;                              // Print results
};

#endif
