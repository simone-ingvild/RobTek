// Gradebook.h
#pragma once
#include <string>
#include <vector>
#include <map>
#include "grade.h"

class Gradebook {
private:
    std::map<std::string, std::vector<Grade>> data; // Map of user -> grades

public:
    void addGrade(const std::string& user, const Grade& g); // Add grade to user
    void readFromStream(std::istream& input);              // Load data from text stream
    void printReport() const;                              // Print all users' grades and averages
};