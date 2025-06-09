#include <string>
#include "Dato.h"
#pragma once
using namespace std;
class CprNr
{
public:
	CprNr();
	CprNr(string etC);

	string getCprNr();
	void setCprNr(string etC);
	int getDag();
	int getMaaned();
	int getAar();
	int getDato();
	int getAlder();
	bool erMand();
	bool erKvinde();
	bool isValid();
	Dato tilDato();

	~CprNr();
private:
	bool isNumeric(char);

	string nummeret;
};

