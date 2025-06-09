#ifndef KUNSTVAERK_H
#define KUNSTVAERK_H

#include <string>
#include "Person.h"

class Kunstvaerk {
protected:
    std::string titel;
    int aar;
    Person ophavsMaend[5];
    int ophavsMaendCount;

public:
    Kunstvaerk(std::string t, int a);
    void addOM(Person p);
    std::string getTitel() const;
    Person* getOphavsMaend();
    int getOphavsMaendCount();
    int getAar() const;
    virtual int getAntalSider() const;
    virtual std::string getMuseumNavn() const;
};

#endif