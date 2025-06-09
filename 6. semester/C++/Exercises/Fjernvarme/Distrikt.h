#ifndef DISTRIKT_H
#define DISTRIKT_H

#include "Forbruger.h"
#include <vector>

class Distrikt {
    private:
        std::vector<Forbruger*> forbrugere;
        double prisM3;
    
    public:

        // Constructor
        Distrikt(double pris);

        // Add forbruger
        void addForbruger(Forbruger& forbruger);

        // Afregn forbruger
        double afregnForbruger(int maalerNr);
};

#endif