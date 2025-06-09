#ifndef COINCOLLECTION_H
#define COINCOLLECTION_H

#include "Coin.h"

class CoinCollection {
public:
    CoinCollection();
    void addCoin(Coin& coin);
    int getTotalValue();
    int getTotalValueDecade(int decade);
private:
    Coin* coins[300];
    int numCoins;
    int getCoinValue(int index); // Removed const
    int getCoinYear(int index); // Removed const
};

#endif