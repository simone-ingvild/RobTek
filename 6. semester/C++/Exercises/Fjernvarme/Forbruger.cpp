#include <iostream>
#include <string>
#include "Forbruger.h"

// Constructor
Forbruger::Forbruger(std::string navn, int maalerNr, int maalerMax)
    : navn(navn), maalerNr(maalerNr), maalerMax(maalerMax), nyAflaesning(0), glAflaesning(0) {}


// Get-metode til maalerNr
int Forbruger::getMaalerNr() const {
    return maalerNr;
}

// Get-metode til navn
std::string Forbruger::getNavn() const {
    return navn;
}

// Set-metode til navn
void Forbruger::setNavn(std::string nytNavn) {
    navn = nytNavn;
}

// Metode til at aflæse måler
void Forbruger::aflaesMaaler(int aflaesning) {

    // Check om det er første aflaesning
    if (glAflaesning == 0) {
        glAflaesning = aflaesning;
    } else {
        glAflaesning = nyAflaesning;
    }
    nyAflaesning = aflaesning;

    // Check for maaler overflow
    if (nyAflaesning < glAflaesning) {
        nyAflaesning += maalerMax;
    }
}

// Metode til at beregne forbrug
int Forbruger::beregnForbrug() const {

    // Ingen tidligere aflaesning
    if (glAflaesning == 0) {
        return 0;
    }

    // Intet overflow
    if (nyAflaesning >= glAflaesning) {
        return nyAflaesning - glAflaesning;
    } 
    // Overflow
    else {
        return nyAflaesning + maalerMax - glAflaesning;
    }
}