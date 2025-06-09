#include "Kunstvaerk.h"
#include "Person.h" // Include Person.h here

Kunstvaerk::Kunstvaerk(std::string t, int a) : titel(t), aar(a), ophavsMaendCount(0) {}

void Kunstvaerk::addOM(Person p) {
    if (ophavsMaendCount < 5) {
        ophavsMaend[ophavsMaendCount++] = p;
    }
}

std::string Kunstvaerk::getTitel() const { return titel; }

Person* Kunstvaerk::getOphavsMaend() { return ophavsMaend; }

int Kunstvaerk::getOphavsMaendCount() { return ophavsMaendCount; }

int Kunstvaerk::getAar() const {return aar;}

int Kunstvaerk::getAntalSider() const { return 0; }

std::string Kunstvaerk::getMuseumNavn() const { return ""; }