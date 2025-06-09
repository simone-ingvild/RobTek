#ifndef PERSONKARTOTEK_H
#define PERSONKARTOTEK_H

#pragma once
#include <string>
#include <vector>
#include "Person.h"

using namespace std;

class PersonKartotek
{
    public:
        PersonKartotek();               // Default constructor
        PersonKartotek(string);         // Constructor
        string getNavn();               // Returnerer navnet på kartoteket
        int getAntalPersoner();         // Returnerer antal personer i kartoteket
        Person& getElement(int);        // Returnerer en reference til en person
        void addPerson(Person &p);      // Tilføjer en person til kartoteket
        ~PersonKartotek();              // Destructor

    private:
        string navn;                    // Navn på kartoteket
        vector<Person> personer;        // Vektor af personer
        int antalPersoner;              // Antal personer i kartoteket
};  

#endif