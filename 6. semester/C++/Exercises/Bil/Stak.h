#pragma once
#ifndef STAK_H
#define STAK_H
#include <vector>
#include "Person.h"

class Stak
{
    public:
    Stak();
    Stak(string);
    bool isEmpty() const;
    string getNavn() const;
    int getStakSize() const;
    void push(Person);
    Person pop();
    ~Stak();

    private:
    string navn;
    vector<Person> personStak;
    int stakSize;
    Person getElement(int) const;
};

#endif