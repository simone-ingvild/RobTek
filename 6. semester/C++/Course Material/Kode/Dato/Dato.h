#include <string>
#pragma once
using namespace std;
class Dato
{
public:
	Dato();
	Dato(int);
	int getDatoen();
	int getAar();
	int getMaaned();
	int getDag();
	int getKvartal();
	void setAar(int);
	void setMaaned(int);
	void setDag(int);
	bool skudAar();
	bool validDato();
	int dagIAar();
	int dagIAarX();
	int restDageIAar();
	void setDatoPlusEn();	// 20191231 bliver til 20200101
	void setDatoMinusEn();  // 20191101 bliver til 20191031
	void setNyDato(int);
	int forskelIDage(Dato);
	int ugeDag();			// Hvis datoen er en mandag returneres 1, tirsdag 2, etc.
	string ugeDagTekst();
	~Dato();
private:
	int datoen = 0;
};


