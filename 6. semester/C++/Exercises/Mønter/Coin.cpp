#include "Coin.h"
#include <iostream>
using namespace std;

Coin::Coin() {}

Coin::Coin(Country& country, int catalogueNumber, int yearIssued, std::string motive, int faceValue, int value)
    : country(country), catalogueNumber(catalogueNumber), yearIssued(yearIssued), motive(motive), faceValue(faceValue), value(value) {}

Country& Coin::getCountry() {
    return country;
}

int Coin::getCatalogueNumber() {
    return catalogueNumber;
}

int Coin::getYearIssued() {
    return yearIssued;
}

std::string Coin::getMotive() {
    return motive;
}

int Coin::getFaceValue() {
    return faceValue;
}

int Coin::getValue() {
    return value;
}

void Coin::changeValue(int amount) {
    value += amount;
    cout << "Coin value changed by: " << amount << ", new value: " << value << endl;
}

Coin::~Coin() {}