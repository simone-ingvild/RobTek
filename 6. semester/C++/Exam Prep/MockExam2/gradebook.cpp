// Gradebook.cpp
#include "gradebook.h"
#include <iostream>
#include <sstream>
#include <iomanip>

void Gradebook::addGrade(const std::string& user, const Grade& g) {
    data[user].push_back(g);
}

void Gradebook::readFromStream(std::istream& input) {
    std::string line;
    while (std::getline(input, line)) {
        std::stringstream ss(line);
        std::string user;
        ss >> user;

        int points;
        double weight;
        while (ss >> points >> weight) {
            addGrade(user, Grade(points, weight));
        }
    }
}

void Gradebook::printReport() const {
    for (const auto& pair : data) {
        const std::string& user = pair.first;
        const std::vector<Grade>& grades = pair.second;

        double totalWeight = 0;
        double weightedSum = 0;

        std::cout << user << "\t";
        for (const Grade& g : grades) {
            std::cout << g.toString() << "  ";
            weightedSum += g.weightedValue();
            totalWeight += g.getWeight();
        }

        double average = totalWeight > 0 ? weightedSum / (totalWeight / 100) : 0;
        std::cout << std::fixed << std::setprecision(1) << average << std::endl;
    }
}