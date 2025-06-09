#pragma once
#ifndef BROEK_H
#define BROEK_H

class Broek
{
    public:
        Broek(void);
        Broek(int aN, int aD);

        int getTaeller();
        int getNaevner();
        Broek adder(Broek aF);
        Broek subtraher(Broek aF);
        Broek multiplicer(Broek aF);
        Broek divider(Broek aF);

        Broek operator+(Broek b);
        Broek operator-(Broek b);
        Broek operator*(Broek b);
        Broek operator/(Broek b);
        ~Broek(void);

    private:
        int taeller;
        int naevner;
        void forkort();
};

#endif