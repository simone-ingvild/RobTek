#include "EMA.h"
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

// Constructor
EMA::EMA() : emailAddress("") {}

// Constructor med email parameter
EMA::EMA(string email) : emailAddress(email) {}

// Destructor
EMA::~EMA() {}

// Getter for emailAddress
string EMA::getEMA() const {
    return emailAddress;
}

// Setter for emailAddress
void EMA::setEMA(string email) {
    emailAddress = email;
}

// Metode til at tjekke om emailadressen er gyldig
bool EMA::isValid() const {
    int snabelAPos = snabelA();
    // Tjekker om der er præcist ét @
    if (snabelAPos == -1) {
        return false;
    }
    // Tjekker om der er præcist ét '.' efter @
    if (!dot()) {
        return false;
    }
    // Tjekker længden og tegnene i emailadressen
    if (!checkLengths()) {
        return false;
    }
    // Tjekker om der er gyldige tegn i emailadressen
    if (!checkChars()) {
        return false;
    }
    return true;
}

// Metode til at finde positionen af '@' i emailadressen
int EMA::snabelA() const {
    // Find første og sidste @ i emailadressen
    size_t firstAt = emailAddress.find('@');
    size_t lastAt = emailAddress.rfind('@');
    // Tjekker om der er præcist ét @
    if (firstAt == string::npos || firstAt != lastAt) {
        return -1;
    }
    // Returnerer positionen af @
    return static_cast<int>(firstAt);
}

// Metode til at kontrollere, om der kun er et punktum efter @
bool EMA::dot() const {
    int snabelAPos = snabelA();
    // Tjekker om der er præcist ét @
    if (snabelAPos == -1) {
        return false;
    }
    // Finder positionen af punktum efter @
    size_t dotPos = emailAddress.find('.', snabelAPos + 1);
    // Tjekker om der er præcist ét punktum efter @
    if (dotPos == string::npos) {
        return false; // Punktum mangler efter @
    }
    // Tjekker om der er mere end ét punktum efter @
    if (emailAddress.find('.', dotPos + 1) != string::npos) {
        return false; // Mere end ét punktum efter @
    }
    // Tjekker nu om der er mindst to karakterer mellem '@' og '.'
    if (static_cast<int>(dotPos) - snabelAPos <= 2) {
        return false;
    }
    return true;
}

// Metode til at kontrollere længden af emailadressen
bool EMA::checkLengths() const {
    int snabelAPos = snabelA();
    // Tjekker om der er præcist ét @
    if (snabelAPos == -1) {
        return false;
    }
    // Tjekker længden af emailadressen
    int localLength = snabelAPos;
    // Tjekker længden af den lokale del (før @)
    int domainLength = emailAddress.length() - snabelAPos - 1;
    // Tjekker længden af domænedelen (efter @)
    return (localLength >= 5 && localLength <= 64 && domainLength >= 5 && domainLength <= 255);
}

// Metode til at tjekke om emailadressen indeholder gyldige tegn
bool EMA::checkChars() const {
    for (char c : emailAddress) {
        // Tjekker at de tegn som indgår er nogle af nedenstående (de gyldige)
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || (c == '@') || (c == '.') || (c == '%') || (c == '&'))) {
            return false;
        }
    }
    return true;
}