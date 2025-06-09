#include "Mekaniker.h"

Mekaniker::Mekaniker(std::string navn) : navn(navn) {}

std::string Mekaniker::getNavn() {
    return navn;
}