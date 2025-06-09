// EAN.h
#ifndef EAN_H
#define EAN_H

#include <string>

class EAN {
private:
    std::string EANnr;

public:
    EAN();
    EAN(const std::string& ean);
    bool isValid() const;
    std::string convertISBNtoEAN(const std::string& isbn) const;
};

#endif