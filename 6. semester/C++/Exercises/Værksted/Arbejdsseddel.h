#ifndef ARBEJDSSeddel_H
#define ARBEJDSSeddel_H

#include "Bil.h"
#include "Mekaniker.h"

class Arbejdsseddel {
public:
    Arbejdsseddel(Bil& bil, Mekaniker& mekaniker, int timer, int dato);
    Bil& getBil();
    Mekaniker& getMekaniker();
    int getTimer();
    int getDato();

private:
    Bil& bil;
    Mekaniker& mekaniker;
    int timer;
    int dato;
};

#endif