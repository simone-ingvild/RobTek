#include "Distrikt.h"
#include "Forbruger.h"
#include <iostream>

// Constructor
Distrikt::Distrikt(double pris) : prisM3(pris) {}


// Metode til at tilføje forbruger
void Distrikt::addForbruger(Forbruger& forbruger) {
    this->forbrugere.push_back(&forbruger);
}

// Metode til at beregne forbrugers forbrug
double Distrikt::afregnForbruger(int maalerNr) {
    for (Forbruger* forbruger : forbrugere) {
        if (forbruger->getMaalerNr() == maalerNr) {
            return forbruger->beregnForbrug() * prisM3;
        }
    }
    return -1;
}