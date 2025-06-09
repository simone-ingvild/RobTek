#include "Maleri.h"

Maleri::Maleri(std::string t, int a, int l, int b, Museum m) : Kunstvaerk(t, a), laengde(l), bredde(b), museum(m) {}

Museum Maleri::getMuseum() const { return museum; }

std::string Maleri::getMuseumNavn() const { return museum.getNavn(); }