#include "Dato.h"
#include <cmath>
#include <iostream>
using namespace std;

Dato::Dato() {}

Dato::Dato(int d)
{
    datoen = d;
}

int Dato::getDatoen()
{
    return datoen;
}

int Dato::getDag()
{
    return datoen % 100;
}

int Dato::getMaaned()
{
    return (datoen % 10000) / 100;
}

int Dato::getKvartal()
{
    int month = getMaaned();
    if (month >= 1 && month <= 3)
        return 1;
    else if (month >= 4 && month <= 6)
        return 2;
    else if (month >= 7 && month <= 9)
        return 3;
    else
        return 4;
}

int Dato::getAar()
{
    return datoen / 10000;
}

void Dato::setAar(int aar)
{
    datoen = (aar * 10000) + (datoen % 10000);
}

void Dato::setMaaned(int maaned)
{
    datoen = (datoen / 10000) * 10000 + (maaned * 100) + (datoen % 100);
}

void Dato::setDag(int dag)
{
    datoen = (datoen / 100) * 100 + dag;
}

bool Dato::skudAar()
{
    int aar = getAar();
    if (aar % 4 == 0)
    {
        if (aar % 100 == 0)
        {
            if (aar % 400 == 0)
                return true;
            else
                return false;
        }
        else
            return true;
    }
    else
        return false;
}

bool Dato::validDato()
{
    int dag = getDag();
    int maaned = getMaaned();
    int aar = getAar();

    if (maaned < 1 || maaned > 12)
        return false;

    if (dag < 1)
        return false;

    if (maaned == 2)
    {
        if (skudAar())
        {
            if (dag > 29)
                return false;
        }
        else
        {
            if (dag > 28)
                return false;
        }
    }
    else if (maaned == 4 || maaned == 6 || maaned == 9 || maaned == 11)
    {
        if (dag > 30)
            return false;
    }
    else
    {
        if (dag > 31)
            return false;
    }

    return true;
}

int Dato::dagIAar()
{
    int dag = getDag();
    int maaned = getMaaned();
    int aar = getAar();

    int dagePrMaaned[] = { 31, (skudAar() ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int dagIAar = 0;

    for (int i = 0; i < maaned - 1; i++)
    {
        dagIAar += dagePrMaaned[i];
    }

    dagIAar += dag;

    return dagIAar;
}

int Dato::restDageIAar()
{
    int dageIAar = skudAar() ? 366 : 365;
    return dageIAar - dagIAar();
}

void Dato::setDatoPlusEn()
{
    int dag = getDag();
    int maaned = getMaaned();
    int aar = getAar();

    int dagePrMaaned[] = { 31, (skudAar() ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    dag++;
    if (dag > dagePrMaaned[maaned - 1])
    {
        dag = 1;
        maaned++;
        if (maaned > 12)
        {
            maaned = 1;
            aar++;
        }
    }

    datoen = aar * 10000 + maaned * 100 + dag;
}

void Dato::setDatoMinusEn()
{
    int dag = getDag();
    int maaned = getMaaned();
    int aar = getAar();

    int dagePrMaaned[] = { 31, (skudAar() ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    dag--;
    if (dag < 1)
    {
        maaned--;
        if (maaned < 1)
        {
            maaned = 12;
            aar--;
        }
        dag = dagePrMaaned[maaned - 1];
    }

    datoen = aar * 10000 + maaned * 100 + dag;
}

void Dato::setNyDato(int nyDato)
{
    datoen = nyDato;
}

int Dato::forskelIDage(Dato d)
{
    return abs(dagIAar() - d.dagIAar());
}

int Dato::ugeDag()
{
    int dag = getDag();
    int maaned = getMaaned();
    int aar = getAar();

    // Zeller's Congruence algorithme for at finde ugedagen
    if (maaned < 3)
    {
        maaned += 12;
        aar--;
    }

    int K = aar % 100;
    int J = aar / 100;

    int h = (dag + 13 * (maaned + 1) / 5 + K + K / 4 + J / 4 + 5 * J) % 7;

    // Omdan til 1 = Mandag, 2 = Tirsdag, ..., 7 = Søndag
    int ugeDag = ((h + 5) % 7) + 1;

    return ugeDag;
}

Dato::~Dato() {}