#ifndef STACKOFMONEY_H
#define STACKOFMONEY_H

#include "valuable.h"
#include "exchangeRate.h"

// Class representing a stack of foreign money, converted to DKK
class StackOfMoney : public Valuable {
private:
    ExchangeRate& rateRef; // Reference to the exchange rate for this currency

public:
    // Constructor to initialize name, value in foreign currency, and exchange rate reference
    StackOfMoney(const std::string& name, double value, ExchangeRate& rateRef)
        : Valuable(name, value), rateRef(rateRef) {}

    // Override to return the value in DKK
    double getValue() const override {
        return Valuable::getValue() * (rateRef.getExchangeRate() / 100.0);
    }
};

#endif // STACKOFMONEY_H
