#include "Country.h"

Country::Country() : name("") {} // Implementer standardkonstruktør

Country::Country(std::string name) : name(name) {}

std::string Country::getName() const {
    return name;
}