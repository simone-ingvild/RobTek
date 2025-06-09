#ifndef BOG_H
#define BOG_H

#include <string>
#include "Kunstvaerk.h"

class Bog : public Kunstvaerk {
private:
    std::string genre;
    int antalSider;

public:
    Bog(std::string t, int a, std::string g, int aS);
    int getAntalSider() const override;
};

#endif