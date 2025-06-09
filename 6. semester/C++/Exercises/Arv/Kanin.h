#pragma once
#include "Husdyr.h"
#include <string>

class Kanin: public Husdyr{
    public:
        Kanin();
        Kanin(const string, const string, const string, int);
        ~Kanin();

    protected:
        string farve;
        int vaegt;
};