#ifndef PERSON_H
#define PERSON_H

#pragma once
using namespace std;
#include <string>
#include "Dato.h"
#include "Bil.h"
class Person
{
public:
	Person();
	Person(string, string, Dato);
	string getNavn();
	string getMail();
	Dato getFDato();
	Bil getBil();
	void addBil(Bil);
	~Person();
private:
	string navn;
	string mail;
	Dato fDag;
	Bil bil;
};

#endif // PERSON_H
