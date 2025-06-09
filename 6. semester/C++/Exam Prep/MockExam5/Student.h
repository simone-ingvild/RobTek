#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include "QuizResult.h"

// Represents a student with quiz results
class Student {
private:
    std::string name;
    std::string username;
    std::vector<QuizResult> quizzes;

public:
    // Constructor with name and username
    Student(const std::string& name, const std::string& username);

    // Adds a quiz result to the student's record
    void addQuizResult(const QuizResult& q);

    // Returns the total weighted score across all quizzes
    double totalScore() const;

    // Returns student's name
    std::string getName() const;

    // Returns student's username
    std::string getUsername() const;

    // Returns the vector of quiz results
    const std::vector<QuizResult>& getResults() const;
};

#endif
