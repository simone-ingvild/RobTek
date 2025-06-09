#include "Museum.h"

Museum::Museum(std::string n, std::string a) : navn(n), adresse(a) {}

std::string Museum::getNavn() const { return navn; }