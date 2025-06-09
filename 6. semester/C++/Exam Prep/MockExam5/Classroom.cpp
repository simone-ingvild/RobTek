#include "Classroom.h"
#include <sstream>
#include <iostream>
#include <iomanip>
#include <algorithm>

//Adds a student object to the classroom
void Classroom::addStudent(const Student& s) {
    students.push_back(s);
}

//Reads student quiz data from an input stream
void Classroom::loadFromStream(std::istream& input) {
    std::string line;

    while (std::getline(input, line)) {
        std::stringstream ss(line);
        std::string name, username;
        ss >> std::quoted(name) >> username;

        Student student(name, username);

        int points;
        double weight;
        while (ss >> points >> weight) {
            student.addQuizResult(QuizResult(points, weight));
        }

        addStudent(student);
    }
}

//Prints a sorted report of students and their scores
void Classroom::printReport() const {
    //Copy students for sorting
    std::vector<Student> sorted = students;

    //Sort descending by total score
    std::sort(sorted.begin(), sorted.end(), [](const Student& a, const Student& b) {
        return a.totalScore() > b.totalScore();
    });

    //Print header
    std::cout << std::left << std::setw(18) << "Name"
              << std::setw(12) << "Username"
              << std::setw(40) << "Results"
              << "Total\n";

    //Print each student
    for (const Student& s : sorted) {
        std::cout << std::left << std::setw(18) << s.getName()
                  << std::setw(12) << s.getUsername();

        std::ostringstream resultStream;
        for (const QuizResult& q : s.getResults()) {
            resultStream << q.toString() << "  ";
        }

        std::cout << std::setw(40) << resultStream.str()
                  << std::fixed << std::setprecision(1)
                  << s.totalScore() << "\n";
    }
}
