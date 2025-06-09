#pragma once
#include "Husdyr.h"
#include <string>

class Hund: public Husdyr{
    public:
        Hund();
        Hund(const string, const string, const string, int);
        string givLyd();
        ~Hund();

    protected:
        string race;
        int vaegt;
};