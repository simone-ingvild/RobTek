#include "Student.h"

//Constructor to initialize name and username
Student::Student(const std::string& name, const std::string& username)
    : name(name), username(username) {}

//Adds a new quiz result to the list
void Student::addQuizResult(const QuizResult& q) {
    quizzes.push_back(q);
}

//Calculates and returns the total weighted score
double Student::totalScore() const {
    double total = 0;
    for (const QuizResult& q : quizzes) {
        total += q.weightedScore();
    }
    return total;
}

//Returns the student's name
std::string Student::getName() const {
    return name;
}

//Returns the student's username
std::string Student::getUsername() const {
    return username;
}

//Returns the list of quiz results
const std::vector<QuizResult>& Student::getResults() const {
    return quizzes;
}
