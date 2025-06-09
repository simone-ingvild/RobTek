#include "course_lottery.h"
#include <iostream>
#include <iomanip>

// Constructor: initializes bins with different seeds
CourseLottery::CourseLottery(unsigned int seed)
    : bin1(seed), bin2(seed + 1) {}

// Add a student to the lottery
void CourseLottery::addStudent(const std::string& name, const std::string& username) {
    students.emplace_back(name, username);
}

// Run the lottery: fill bins and assign exams to students
void CourseLottery::runLottery(const std::vector<std::string>& subjects1,
                               const std::vector<std::string>& subjects2) {
    int n = students.size();
    bin1.fillEvenly(subjects1, n);
    bin2.fillEvenly(subjects2, n);

    for (auto& student : students) {
        student.setExam1(bin1.draw());
        student.setExam2(bin2.draw());
    }
}

// Print the results for all students
void CourseLottery::printResults(std::ostream& os) const {
    os << std::left << std::setw(18) << "Name"
       << std::setw(12) << "Username"
       << std::setw(8) << "Exam1"
       << "Exam2\n";
    for (const auto& student : students) {
        student.print(os);
    }
}
