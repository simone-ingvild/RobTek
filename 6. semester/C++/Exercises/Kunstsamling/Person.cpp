#include "Person.h"

Person::Person(std::string n, std::string nat, int fAar, int dAar) : navn(n), nationalitet(nat), foedeaar(fAar), doedsaar(dAar) {}

std::string Person::getNavn() const { return navn; }