#ifndef FORBRUGER_H
#define FORBRUGER_H
#include <iostream>
#include <string>

class Forbruger {
private:
    std::string navn;
    int maalerNr;
    int nyAflaesning;
    int glAflaesning;
    int maalerMax;

public:
    // Constructor
    Forbruger(std::string navn, int maalerNr, int maalerMax);

    // Get-metode til maalerNr
    int getMaalerNr() const;

    // Get-metode til navn
    std::string getNavn() const;

    // Set-metode til navn
    void setNavn(std::string navn);

    // Metode til at aflaese maaler
    void aflaesMaaler(int nyAflaesning);

    // Beregn forbrug
    int beregnForbrug() const;
};

#endif