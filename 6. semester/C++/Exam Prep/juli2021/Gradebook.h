#ifndef GRADEBOOK_H
#define GRADEBOOK_H

#include <map>
#include <vector>
#include <string>
#include <iosfwd>
#include "Grade.h"

// Samler alle karakterer pr. studerende
class Gradebook {
public:
    Gradebook() = default;

    void readResults (std::istream& in);   // læs ét datasæt (vægt + linjer)
    void printResults(std::ostream& out) const;

private:
    std::map<std::string, std::vector<Grade>> mGrades;   // key = brugernavn
};

#endif // GRADEBOOK_H
