#include "Person.h"
using namespace std;						// Using namespace std to use library functions
Person::Person() {}							// Default constructor 

Person::Person(string n, string m, Dato f)
{
	navn = n;
	mail = m;
	fDag = f;
}

string Person::getNavn()
{
	return navn;
}

string Person::getMail()
{
	return mail;
}

Dato Person::getFDato()
{
	return fDag;
}

Bil Person::getBil()
{
	return bil;
}

void Person::addBil(Bil b)		// Void means no return value
{
	bil = b;
}

Person::~Person(){}
