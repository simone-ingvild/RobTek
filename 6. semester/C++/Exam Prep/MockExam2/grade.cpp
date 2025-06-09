// Grade.cpp
#include "grade.h"
#include <sstream>
#include <iomanip>

// Constructor definition
Grade::Grade(int p, double w) : points(p), weight(w) {}

int Grade::getPoints() const {
    return points;
}

double Grade::getWeight() const {
    return weight;
}

double Grade::weightedValue() const {
    return points * (weight / 100);
}

std::string Grade::toString() const {
    std::ostringstream ss;
    ss << points << " (" << std::fixed << std::setprecision(1) << weight << ")";
    return ss.str();
}