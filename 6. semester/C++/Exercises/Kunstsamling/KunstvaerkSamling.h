#ifndef KUNSTVAERKSAMLING_H
#define KUNSTVAERKSAMLING_H

#include <string>
#include <vector>
#include "Kunstvaerk.h"

class KunstvaerkSamling {
private:
    std::string samlingNavn;
    std::vector<Kunstvaerk*> kunstvaerker;

public:
    KunstvaerkSamling(std::string sN);
    void addKunstvaerk(Kunstvaerk* kv);
    void findSangeMedFlereKomponister();
    void findMalerierPaaMuseum(std::string museumNavn);
    void beregnAntalLaesteSider();
};

#endif