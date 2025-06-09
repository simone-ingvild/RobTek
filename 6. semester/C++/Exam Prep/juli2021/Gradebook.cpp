#include "Gradebook.h"
#include <sstream>
#include <iomanip>
#include <stdexcept>

// Læs et helt sæt (første linje = vægt, derefter "user point")
void Gradebook::readResults(std::istream& in)
{
    std::string line;

    // spring blanke linjer før vægten
    while (std::getline(in, line) && line.empty()) {}

    if (!in) return;                    // tom stream

    const float weight = std::stof(line);   // første ikke-blanke linje = vægten

    // læs resten
    while (std::getline(in, line)) {
        if (line.empty()) continue;         // ignorér blanke linjer

        std::istringstream ls(line);
        std::string user;
        int         point;

        if (!(ls >> user >> point))
            throw std::runtime_error("Ugyldig linje: " + line);

        mGrades[user].emplace_back(point, weight);
    }
}

// Print one summary line per student in the required layout
void Gradebook::printResults(std::ostream& out) const
{
    out << std::fixed << std::setprecision(1);

    for (const auto& [user, grades] : mGrades)
    {
        double total = 0.0;

        // Username: 8-char left-aligned field
        out << std::left << std::setw(8) << user << std::right;

        // Each grade: " xxx ( yy.y)"
        for (const Grade& g : grades)
        {
            total += g.weightedGrade();

            out << ' '
                << std::setw(3) << g.getPoint()           // points field, width 3
                << " (" << std::setw(5) << g.getWeight()  // weight field, width 5
                << ')';
        }

        // Final weighted sum: width 6
        out << ' ' << std::setw(6) << total << '\n';
    }
}

