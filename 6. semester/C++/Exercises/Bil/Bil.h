#ifndef BIL_H
#define BIL_H

#pragma once
#include <string>
using namespace std;
class Bil
{
    public:
        Bil();                  // Default constructor
        Bil(string, int);
        string getRegNr();
        int getAargang();
        ~Bil();                // Destructor

    private:
        // Attributter er altid private
        string regNr;
        int aargang;
};

#endif // BIL_H