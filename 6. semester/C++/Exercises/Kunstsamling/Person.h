#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
private:
    std::string navn;
    std::string nationalitet;
    int foedeaar;
    int doedsaar;

public:
    Person() : navn(""), nationalitet(""), foedeaar(0), doedsaar(0) {}
    Person(std::string n, std::string nat, int fAar, int dAar);
    std::string getNavn() const;
};

#endif