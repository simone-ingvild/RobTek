#ifndef MUSEUM_H
#define MUSEUM_H

#include <string>

class Museum {
private:
    std::string navn;
    std::string adresse;

public:
    Museum(std::string n, std::string a);
    std::string getNavn() const;
};

#endif