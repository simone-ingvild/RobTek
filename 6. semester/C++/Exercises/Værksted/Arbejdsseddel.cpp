#include "Arbejdsseddel.h"

Arbejdsseddel::Arbejdsseddel(Bil& bil, Mekaniker& mekaniker, int timer, int dato)
    : bil(bil), mekaniker(mekaniker), timer(timer), dato(dato) {}

Bil& Arbejdsseddel::getBil() {
    return bil;
}

Mekaniker& Arbejdsseddel::getMekaniker() {
    return mekaniker;
}

int Arbejdsseddel::getTimer() {
    return timer;
}

int Arbejdsseddel::getDato() {
    return dato;
}