#include "Bog.h"

Bog::Bog(std::string t, int a, std::string g, int aS) : Kunstvaerk(t, a), genre(g), antalSider(aS) {}

int Bog::getAntalSider() const { return antalSider; }