# ifndef DATO_H
# define DATO_H

#pragma once
using namespace std;
class Dato
{
public:
	Dato();
	Dato(int);
	int getDatoen();
	int getDag();
	int getMaaned();
	int getKvartal();
	int getAar();

	void setAar(int);        
    void setMaaned(int);     
    void setDag(int); 

    bool skudAar();
    bool validDato();
	
    int dagIAar();
    int restDageIAar();
    void setDatoPlusEn();    // 20191231 bliver til 20200101
    void setDatoMinusEn();   // 20191101 bliver til 20191031
    void setNyDato(int);
    int forskelIDage(Dato);
    int ugeDag();
	~Dato();
private:
	int datoen; // YYYYMMDD

};

#endif // DATO_H
