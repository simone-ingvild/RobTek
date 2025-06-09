#include "QuizResult.h"
#include <sstream>
#include <iomanip>

//Constructor to initialize points and weight
QuizResult::QuizResult(int p, double w) : points(p), weight(w) {}

//Returns the raw points
int QuizResult::getPoints() const {
    return points;
}

//Returns the weight of the quiz
double QuizResult::getWeight() const {
    return weight;
}

//Calculates and returns the weighted score
double QuizResult::weightedScore() const {
    return points * (weight / 100.0);
}

//Formats the quiz result as "points (weight)"
std::string QuizResult::toString() const {
    std::ostringstream out;
    out << points << " (" << std::fixed << std::setprecision(1) << weight << ")";
    return out.str();
}
