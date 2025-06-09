#include <iostream>
#include <cmath>
#include "Broek.h"

using namespace std;

// Hjælpefunktion til at finde den største fælles divisor (GCD)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Konstruktør uden argumenter
Broek::Broek() : taeller(0), naevner(1) {}

// Konstruktør med tæller og nævner
Broek::Broek(int aN, int aD) {
    if (aD == 0) {
        // Håndter division med nul (f.eks. ved at sætte nævner til 1)
        naevner = 1;
        taeller = 0;
    } else {
        naevner = aD;
        taeller = aN;
    }
    forkort();
}

// Hent tæller
int Broek::getTaeller() {
    return taeller;
}

// Hent nævner
int Broek::getNaevner() {
    return naevner;
}

// Adder to brøker
Broek Broek::adder(Broek aF) {
    int nyTaeller = taeller * aF.naevner + aF.taeller * naevner;
    int nyNaevner = naevner * aF.naevner;
    return Broek(nyTaeller, nyNaevner);
}

// Subtraher to brøker
Broek Broek::subtraher(Broek aF) {
    int nyTaeller = taeller * aF.naevner - aF.taeller * naevner;
    int nyNaevner = naevner * aF.naevner;
    return Broek(nyTaeller, nyNaevner);
}

// Multiplicer to brøker
Broek Broek::multiplicer(Broek aF) {
    int nyTaeller = taeller * aF.taeller;
    int nyNaevner = naevner * aF.naevner;
    return Broek(nyTaeller, nyNaevner);
}

// Divider to brøker
Broek Broek::divider(Broek aF) {
    int nyTaeller = taeller * aF.naevner;
    int nyNaevner = naevner * aF.taeller;
    return Broek(nyTaeller, nyNaevner);
}

// Overload af + operator
Broek Broek::operator+(Broek b) {
    return adder(b);
}

// Overload af - operator
Broek Broek::operator-(Broek b) {
    return subtraher(b);
}

// Overload af * operator
Broek Broek::operator*(Broek b) {
    return multiplicer(b);
}

// Overload af / operator
Broek Broek::operator/(Broek b) {
    return divider(b);
}

// Destruktor
Broek::~Broek() {}

// Hjælpefunktion til at forkorte brøken
void Broek::forkort() {
    int divisor = gcd(taeller, naevner);
    taeller /= divisor;
    naevner /= divisor;
}