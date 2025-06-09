#ifndef QUIZRESULT_H
#define QUIZRESULT_H

#include <string>

// Represents a single quiz result with points and weight
class QuizResult {
private:
    int points;
    double weight;

public:
    // Constructor to initialize a quiz result
    QuizResult(int p, double w);

    // Returns the raw score
    int getPoints() const;

    // Returns the weight of the quiz
    double getWeight() const;

    // Returns the weighted score (points * weight / 100)
    double weightedScore() const;

    // Returns a string like "88 (20.0)"
    std::string toString() const;
};

#endif
