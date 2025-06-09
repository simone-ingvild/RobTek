#include "Distrikt.h"
#include "Forbruger.h"
#include <iostream>

using namespace std;

int main() {
    Distrikt svindinge(78); // Opretter distrikt med kubikmeterpris 78 kr.

    Forbruger poul("Poul Thorsen", 1206, 999);
    Forbruger niels("Niels Kragh Hansen", 1227, 999);

    svindinge.addForbruger(poul);
    svindinge.addForbruger(niels);

    poul.aflaesMaaler(924);
    poul.aflaesMaaler(18);

    niels.aflaesMaaler(608);
    niels.aflaesMaaler(724);

    cout << svindinge.afregnForbruger(1206) << endl; // Udskriver 7332
    cout << svindinge.afregnForbruger(1227) << endl; // Udskriver 9048
    cout << svindinge.afregnForbruger(1256) << endl; // Udskriver -1

    return 0;
}