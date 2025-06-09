#ifndef MEKANIKER_H
#define MEKANIKER_H

#include <string>

class Mekaniker {
public:
    Mekaniker(std::string navn);
    std::string getNavn();

private:
    std::string navn;
};

#endif