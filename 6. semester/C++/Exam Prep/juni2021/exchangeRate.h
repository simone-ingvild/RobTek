#ifndef EXCHANGERATE_H
#define EXCHANGERATE_H

#include <string>

// Class representing the exchange rate of a currency to DKK
class ExchangeRate {
private:
    std::string currency; // Currency code (e.g., "USD", "EUR")
    double rate;          // DKK per 100 units of the foreign currency

public:
    // Constructor to initialize currency and rate
    ExchangeRate(const std::string& currency, double rate)
        : currency(currency), rate(rate) {}

    // Getter for the exchange rate
    double getExchangeRate() const {
        return rate;
    }

    // Setter for the exchange rate
    void setExchangeRate(double newRate) {
        rate = newRate;
    }
};

#endif // EXCHANGERATE_H
