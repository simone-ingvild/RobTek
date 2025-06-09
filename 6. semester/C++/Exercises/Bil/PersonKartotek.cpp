#include "PersonKartotek.h"
#include <iostream>

using namespace std;

PersonKartotek::PersonKartotek() 
{
    antalPersoner = 0;
    navn = "";
    personer = vector<Person>();
}

PersonKartotek::PersonKartotek(string n)
{
    personer = vector<Person>();
    antalPersoner = 0;
    navn = n;
}

string PersonKartotek::getNavn()
{
    return navn;
}

int PersonKartotek::getAntalPersoner()
{
    return antalPersoner;
}

void PersonKartotek::addPerson(Person& p)
{
    personer.push_back(p);
    antalPersoner++;
}

Person& PersonKartotek::getElement(int i)
{
    return personer.at(i);
}

PersonKartotek::~PersonKartotek() {}