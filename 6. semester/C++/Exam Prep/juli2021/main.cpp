#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "Bin.h"
#include "Student.h"

int main() {
    std::cout << "--------------------" << std::endl;
    std::cout << "-- Opgave 1a test --" << std::endl;
    std::cout << "--------------------" << std::endl << std::endl;

    // Test lodtrækning uden tilbagelægning
    Bin b;
    b.fillBin(1, 2, 10);
    std::cout << "Bin size (before): " << b.size() << std::endl;
    std::cout << "Number of 1's: " << b.count(1) << std::endl;
    std::cout << "Number of 2's: " << b.count(2) << std::endl;

    std::cout << "Draw : ";
    for (unsigned int i = 0; i < 10; ++i) {
        std::cout << b.drawAndRemove() << " ";
    }
    std::cout << std::endl;
    std::cout << "Bin size (after): " << b.size() << std::endl << std::endl;

    b.fillBin(2, 4, 10);
    std::cout << "Bin size (before): " << b.size() << std::endl;
    std::cout << "Number of 2's: " << b.count(2) << std::endl;
    std::cout << "Number of 3's: " << b.count(3) << std::endl;
    std::cout << "Number of 4's: " << b.count(4) << std::endl;

    std::cout << "Draw : ";
    for (unsigned int i = 0; i < 10; ++i) {
        std::cout << b.drawAndRemove() << " ";
    }
    std::cout << std::endl;
    std::cout << "Bin size (after): " << b.size() << std::endl << std::endl;

    std::cout << "--------------------" << std::endl;
    std::cout << "-- Opgave 1b test --" << std::endl;
    std::cout << "--------------------" << std::endl << std::endl;

    std::vector<std::string> exams1 {"PLC", "OOP"};
    std::vector<std::string> exams2 {"IIC", "RSI", "VIS"};

    std::vector<Student> students;
    students.emplace_back("Hans Hansen", "hahan20");
    students.emplace_back("Hanne Hansen", "haha120");
    students.emplace_back("Jens Jensen", "jejen20");
    students.emplace_back("Jesper Jespersen", "jejes20");
    students.emplace_back("Henrik Henriksen", "hehen20");
    students.emplace_back("Søren Sørensen", "sosor20");
    students.emplace_back("Niels Nielsen", "ninie20");
    students.emplace_back("Peder Pedersen", "peped20");
    students.emplace_back("Anders Andersen", "anand20");
    students.emplace_back("Christian Christensen", "chchr20");
    students.emplace_back("Lars Larsen", "lalar20");
    students.emplace_back("Rasmus Rasmussen", "raras20");
    students.emplace_back("Jørgen Jørgensen", "jojor20");

    std::cout << "Studerende og brugernavne" << std::endl;
    for (Student& s : students) {
        std::cout << std::left << std::setw(22) << s.getName() << " " << s.getUsername() << std::endl;
    }
    std::cout << std::endl;

    // Lodtrækning uden tilbagelægning (1st round)
    Bin bCourse;
    bCourse.fillBin(0, exams1.size() - 1, students.size());
    for (Student& s : students) {
        s.draw(bCourse);
    }

    std::cout << "Studerende og brugernavne med lodtrækning" << std::endl;
    for (Student& s : students) {
        std::string examDraw = s.getExam(exams1);
        std::cout << std::left << std::setw(22) << s.getName()
                  << std::setw(10) << s.getUsername() << " " << examDraw << std::endl;
    }

    std::cout << std::endl << "Anden lodtrækning" << std::endl;
    bCourse.fillBin(0, exams2.size() - 1, students.size());
    for (Student& s : students) {
        s.draw(bCourse);
    }
    for (Student& s : students) {
        std::string examDraw = s.getExam(exams2);
        std::cout << std::left << std::setw(22) << s.getName()
                  << std::setw(10) << s.getUsername() << " " << examDraw << std::endl;
    }

    std::cout << std::endl;
    std::cout << "--------------------" << std::endl;
    std::cout << "-- Opgave 1c test --" << std::endl;
    std::cout << "--------------------" << std::endl << std::endl;
    for (Student& s : students) {
        std::string examDraw = s.getExam(exams2);
        std::cout << s << " " << examDraw << std::endl;
    }

    return 0;
}
