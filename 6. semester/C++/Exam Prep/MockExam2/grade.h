// Grade.h
#pragma once
#include <string>

class Grade {
private:
    int points;       // Score from 0 to 100
    double weight;    // Weight in percentage

public:
    Grade(int p, double w); // Constructor

    // Accessor methods
    int getPoints() const;
    double getWeight() const;

    // Return weighted score
    double weightedValue() const;

    // Return string representation like "95 (45.0)"
    std::string toString() const;
};