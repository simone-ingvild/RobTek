#ifndef MALERI_H
#define MALERI_H

#include <string>
#include "Kunstvaerk.h"
#include "Museum.h"

class Maleri : public Kunstvaerk {
private:
    int laengde;
    int bredde;
    Museum museum;

public:
    Maleri(std::string t, int a, int l, int b, Museum m);
    Museum getMuseum() const;
    std::string getMuseumNavn() const override;
};

#endif