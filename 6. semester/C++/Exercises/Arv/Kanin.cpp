#include "Kanin.h"
using namespace std;

Kanin::Kanin(){}

Kanin::Kanin(const string n, const string t, const string f, int v): Husdyr(n, t){
    farve = f;
    vaegt = v;
}

Kanin::~Kanin(){}
