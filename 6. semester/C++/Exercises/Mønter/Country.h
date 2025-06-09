#ifndef COUNTRY_H
#define COUNTRY_H

#include <string>

class Country {
public:
    Country(); // Tilføjet standardkonstruktør
    Country(std::string name);
    std::string getName() const;
private:
    std::string name;
};

#endif