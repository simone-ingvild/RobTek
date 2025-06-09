#include "KunstvaerkSamling.h"
#include <iostream>
#include "Komposition.h"
#include "Maleri.h"
#include "Bog.h"

KunstvaerkSamling::KunstvaerkSamling(std::string sN) : samlingNavn(sN) {}

void KunstvaerkSamling::addKunstvaerk(Kunstvaerk* kv) {
    kunstvaerker.push_back(kv);
}

void KunstvaerkSamling::findSangeMedFlereKomponister() {
    std::cout << "Sange med flere komponister:" << std::endl;
    for (Kunstvaerk* kv : kunstvaerker) {
        Komposition* komposition = dynamic_cast<Komposition*>(kv);
        if (komposition && kv->getOphavsMaendCount() > 1) {
            std::cout << kv->getTitel() << std::endl;
        }
    }
}

void KunstvaerkSamling::findMalerierPaaMuseum(std::string museumNavn) {
    std::cout << "Malerier på " << museumNavn << ":" << std::endl;
    for (Kunstvaerk* kv : kunstvaerker) {
        Maleri* maleri = dynamic_cast<Maleri*>(kv);
        if (maleri && maleri->getMuseum().getNavn() == museumNavn) {
            std::cout << kv->getTitel() << std::endl;
        }
    }
}

void KunstvaerkSamling::beregnAntalLaesteSider() {
    int totalSider = 0;
    for (Kunstvaerk* kv : kunstvaerker) {
        totalSider += kv->getAntalSider();
    }
    std::cout << "Antal læste sider: " << totalSider << std::endl;
}