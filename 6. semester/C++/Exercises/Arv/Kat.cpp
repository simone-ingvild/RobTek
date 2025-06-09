#include "Kat.h"
using namespace std;

Kat::Kat(){}

Kat::Kat(const string n, const string t, const string k, bool s): Husdyr(n, t){
    koen = k;
    steriliseret = s;
}

string Kat::givLyd(){
    return "Miaaau";
}

Kat::~Kat(){}
