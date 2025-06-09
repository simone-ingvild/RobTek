#ifndef HUSDYR_H
#define HUSDYR_H
#pragma once

#include <iostream>
#include <string>
using namespace std;

class Husdyr {
    public:
        Husdyr();
        Husdyr(const string, const string);
        virtual string givLyd();
        ~Husdyr();

    protected:
        string ejersNavn;
        string telefonnr;

};

#endif