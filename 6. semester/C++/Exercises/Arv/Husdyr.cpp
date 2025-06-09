#include "Husdyr.h"

Husdyr::Husdyr(){}

Husdyr::Husdyr(const string navn, const string nr){
    ejersNavn = navn;
    telefonnr = nr;
}

string Husdyr::givLyd(){
    return "Husdyret laver ingen lyd";
}

Husdyr::~Husdyr(){}