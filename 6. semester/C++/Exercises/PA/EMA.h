#ifndef EMA_H
#define EMA_H
#include <iostream>
#include <string>

using namespace std;

class EMA {
    public:
        EMA();
        EMA(string email);
        ~EMA();

        string getEMA() const;
        void setEMA(string email);
        bool isValid() const;

    private:
        int snabelA() const;
        bool dot() const;
        bool checkLengths() const;
        bool checkChars() const;

        string emailAddress;

};

#endif