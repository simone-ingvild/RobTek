#ifndef KOMPOSITION_H
#define KOMPOSITION_H

#include <string>
#include "Kunstvaerk.h"

class Komposition : public Kunstvaerk {
private:
    std::string genre;
    int spilletid;

public:
    Komposition(std::string t, int a, std::string g, int sT);
};

#endif