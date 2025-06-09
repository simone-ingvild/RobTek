#ifndef BIL_H
#define BIL_H

#include <string>

class Bil {
public:
    Bil(std::string regNr, std::string ejer);
    std::string getRegNr();
    std::string getEjer();

private:
    std::string regNr;
    std::string ejer;
};

#endif