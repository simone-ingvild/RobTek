#include "Hund.h"
#include <iostream>
#include <string>

Hund::Hund(){}

Hund::Hund(const string n, const string t, const string r, int v):Husdyr(n,t){
    race = r;
    vaegt = v;
}

string Hund::givLyd(){
    return "Vov vov";
}

Hund::~Hund(){}


