#include <iostream>
#include <string>

bool ordITekst(std::string tekst, std::string ord) {
    // Brug string::find til at søge efter ordet i teksten
    if (tekst.find(ord) != std::string::npos) {
        return true; // Ordet blev fundet
    } else {
        return false; // Ordet blev ikke fundet
    }
}

int main() {
    std::string tekst = "Dette er en test tekst med nogle ord.";
    std::string ord1 = "test";
    std::string ord2 = "ikke";

    std::cout << "Er '" << ord1 << "' i teksten? " << std::boolalpha << ordITekst(tekst, ord1) << std::endl;
    std::cout << "Er '" << ord2 << "' i teksten? " << std::boolalpha << ordITekst(tekst, ord2) << std::endl;

    return 0;
}