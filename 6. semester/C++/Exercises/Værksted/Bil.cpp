#include "Bil.h"

Bil::Bil(std::string regNr, std::string ejer) : regNr(regNr), ejer(ejer) {}

std::string Bil::getRegNr() {
    return regNr;
}

std::string Bil::getEjer() {
    return ejer;
}