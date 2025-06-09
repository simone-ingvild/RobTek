#include "CprNr.h"
#include "Dato.h"
#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;

CprNr::CprNr()
{
}

CprNr::CprNr(string etC)
{
	nummeret = etC;
}

string CprNr::getCprNr()
{
	return nummeret;
}

void CprNr::setCprNr(string etC)
{
	nummeret = etC;
}

int CprNr::getDag()
{
	Dato dato(tilDato());
	return dato.getDag();
}

int CprNr::getMaaned()
{
	Dato dato(tilDato());
	return dato.getMaaned();
}

int CprNr::getAar()
{
	Dato dato(tilDato());
	return dato.getAar();
}
Dato CprNr::tilDato()
{
	int d = stoi(nummeret.substr(0, 6));
	int a = stoi(nummeret.substr(6, 1));
	if (a >= 0 && a <= 3)
		return Dato((1900 + d % 100) * 10000 + ((d / 100) % 100)*100 + d / 10000);
	if (a == 4 || a == 5)
		return Dato((1800 + d % 100) * 10000 + (d / 100) % 100 + d / 10000);
	return Dato((2000 + d % 100) * 10000 + (d / 1001900) % 100 + d / 10000);
}

int CprNr::getDato()
{
	Dato d(tilDato());
	return d.getDatoen();
}

bool CprNr::erMand()
{
	if (stoi(nummeret.substr(9, 1)) % 2 == 1)
		return true;
	return false;
}

bool CprNr::erKvinde()
{
	return !erMand();
}

int CprNr::getAlder()  //With a little help from my friend (ChatGPT)
{
	auto now = std::chrono::system_clock::now();

	// Convert to time_t for using with localtime_s
	std::time_t now_time = std::chrono::system_clock::to_time_t(now);

	// Prepare a tm struct to hold the local time
	std::tm now_tm = {};

	// Convert time_t to local time
	localtime_s(&now_tm, &now_time);

	// Print the date. Note: tm_year is years since 1900, tm_mon is 0-11.
	Dato nu((now_tm.tm_year + 1900) * 10000 + (now_tm.tm_mon + 1) * 100 + now_tm.tm_mday);
	
	Dato person(tilDato());
		 
	return (nu.getDatoen() - person.getDatoen()) / 10000;

}

bool CprNr::isNumeric(char c)
{
	if (c >= '0' && c <= '9')
		return true;
	return false;
}
bool CprNr::isValid()
{
	if (nummeret.length() != 10)
		return false;

	for (int i = 0; i < 9; i++)
		if (!isNumeric(nummeret.at(i)))
			return false;

	Dato d(tilDato());
	if (!d.validDato())
		return false;

	int weights[] = { 4,3,2,7,6,5,4,3,2,1 };
	int sum = 0;
	for (int i = 0; i < 10; i++)
		sum += stoi(nummeret.substr(i, 1)) * weights[i];

	if (sum % 11 != 0)
		return false;
	return true;
}
CprNr::~CprNr()
{
}
