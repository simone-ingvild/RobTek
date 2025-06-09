#pragma once
#include "Husdyr.h"
#include <string>

class Kat: public Husdyr {
    public:
        Kat();
        Kat(const string, const string, const string, bool);
        string givLyd() override; //Overskriver metoden som ligger i Husdyr
        ~Kat();

    protected:
        string koen;
        bool steriliseret;
};