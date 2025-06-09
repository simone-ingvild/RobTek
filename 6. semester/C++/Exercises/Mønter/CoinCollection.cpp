#include "CoinCollection.h"

CoinCollection::CoinCollection() : numCoins(0) {
    for (int i = 0; i < 300; ++i) {
        coins[i] = nullptr; // Initialize pointers
    }
}

void CoinCollection::addCoin(Coin& coin) { // Take Coin by reference
    if (numCoins < 300) {
        coins[numCoins] = &coin; // Store reference to Coin
        numCoins++;
    }
}

int CoinCollection::getTotalValue() {
    int totalValue = 0;
    for (int i = 0; i < numCoins; ++i) {
        if (coins[i] != nullptr) {
            totalValue += getCoinValue(i);
        }
    }
    return totalValue;
}

int CoinCollection::getTotalValueDecade(int decade) {
    int totalDecadeValue = 0;
    for (int i = 0; i < numCoins; ++i) {
        if (coins[i] != nullptr) {
            int year = getCoinYear(i);
            if (year >= decade * 10 && year < (decade + 1) * 10) {
                totalDecadeValue += getCoinValue(i);
            }
        }
    }
    return totalDecadeValue;
}

int CoinCollection::getCoinValue(int index) {
    if (coins[index] != nullptr) {
        return coins[index]->getValue();
    }
    return 0; // Or handle error appropriately
}

int CoinCollection::getCoinYear(int index) {
    if (coins[index] != nullptr) {
        return coins[index]->getYearIssued();
    }
    return 0; // Or handle error appropriately
}