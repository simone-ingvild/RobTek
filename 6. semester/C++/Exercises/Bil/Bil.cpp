#include "Bil.h"
using namespace std;
Bil::Bil() {}

Bil::Bil(string r, int a)
{
    regNr = r;
    aargang = a;
}

Bil::~Bil() {}

string Bil::getRegNr()
{
    return regNr;
}

int Bil::getAargang()
{
    return aargang;
}
