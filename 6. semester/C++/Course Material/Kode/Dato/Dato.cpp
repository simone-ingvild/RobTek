#include <string>
#include "Dato.h"
using namespace std;
Dato::Dato()
{

}

Dato::Dato(int enD)
{
	datoen = enD;
}

int Dato::getDatoen()
{
	return datoen;
}

int Dato::getAar()
{
	return datoen / 10000;
}

int Dato::getMaaned()
{
	return (datoen / 100) % 100;
}

int Dato::getDag()
{
	return datoen % 100;
}

void Dato::setAar(int nytAar)
{
	datoen = nytAar * 10000 + datoen % 10000;
}

void Dato::setDag(int nyDag)
{
	datoen = datoen - getDag() + nyDag;
}

void Dato::setMaaned(int nyMaaned)
{
	datoen = getAar() * 10000 + nyMaaned * 100 + getDag();
}

int Dato::getKvartal()
{
	return ((getMaaned() - 1) / 3) + 1;
}
// Precondition: datoen er valid
bool Dato::skudAar()
{
	if (getAar() % 4 != 0)
		return false;
	if (getAar() % 100 == 0 && getAar() % 400 != 0)
		return false;
	return true;
}

bool Dato::validDato()
{
	if (datoen < 17000301)
		return false;
	if (getMaaned() < 1 || getMaaned() > 12)
		return false;
	if (getDag() < 1 || getDag() > 31)
		return false;
	if (getMaaned() == 2 && skudAar() && getDag() > 29)
		return false;
	if (getMaaned() == 2 && !skudAar() && getDag() > 28)
		return false;
	if (getDag() > 30 && (getMaaned() == 4 || getMaaned() == 6 ||
		getMaaned() == 9 || getMaaned() == 11))
		return false;
	return true;
}

int Dato::dagIAarX()
{
	int arr[13] = { 0,0,31,59,90,120,151,181,212,243,273,304,334 };
	int skudDag = 0;
	if (skudAar()) skudDag++;
	if (getMaaned() > 2)
		return getDag() + skudDag + arr[getMaaned()];
	return getDag() + arr[getMaaned()];
}

int Dato::dagIAar()
{
	int skudDag = 0;
	if (skudAar()) skudDag++;
	switch (getMaaned())
	{
	case 1:
		return getDag();
	case 2:
		return getDag() + 31;
	case 3:
		return getDag() + skudDag + 59;
	case 4:
		return getDag() + skudDag + 90;
	case 5:
		return getDag() + skudDag + 120;
	case 6:
		return getDag() + skudDag + 151;
	case 7:
		return getDag() + skudDag + 181;
	case 8:
		return getDag() + skudDag + 212;
	case 9:
		return getDag() + skudDag + 243;
	case 10:
		return getDag() + skudDag + 273;
	case 11:
		return getDag() + skudDag + 304;
	default:
		return getDag() + skudDag + 334;
	}
}

int Dato::restDageIAar()
{
	if (skudAar())
		return 366 - dagIAar();
	else
		return 365 - dagIAar();
}

void Dato::setDatoPlusEn()
{
	datoen++;
	while (!validDato())
		datoen++;
}

void Dato::setDatoMinusEn()
{
	datoen--;
	while (!validDato())
		datoen--;
}

void Dato::setNyDato(int antalDage)
{
	if (antalDage > 0)
		for (int i = 0; i < antalDage; i++)
		{
			setDatoPlusEn();
		}
	else
		if (antalDage < 0)
			for (int i = 0; i > antalDage; i--)
				setDatoMinusEn();
}

int Dato::forskelIDage(Dato enDato)
{
	int antalDage = 0;

	Dato kopiDato(getDatoen());

	if (kopiDato.datoen < enDato.datoen)
	{
		while (kopiDato.datoen != enDato.datoen)
		{
			kopiDato.setDatoPlusEn();
			antalDage++;
		}
	}
	else
		if (kopiDato.datoen > enDato.datoen)
		{
			while (kopiDato.datoen != enDato.datoen)
			{
				kopiDato.setDatoMinusEn();
				antalDage--;
			}
		}
	return antalDage;
}

int Dato::ugeDag()
{
	Dato udgDato(17000301);

	return udgDato.forskelIDage(datoen) % 7 + 1;

}

string Dato::ugeDagTekst()
{
	string dage[7] = {"mandag","tirsdag","onsdag","torsdag","fredag","lørdag","søndag"};
	return dage[ugeDag() - 1];
}


Dato::~Dato()
{}