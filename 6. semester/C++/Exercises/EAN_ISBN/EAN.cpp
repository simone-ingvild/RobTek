// EAN.cpp
#include "EAN.h"

// Attribute
EAN::EAN() : EANnr("") {}

// Constructor
EAN::EAN(const std::string& ean) : EANnr(ean) {}

// Checks is valid
bool EAN::isValid() const {

    // Checks if the EAN number is 13 digits long
    if (EANnr.length() != 13) {
        return false;
    }

    int oddSum = 0;
    int evenSum = 0;

    // Calculates the sum of the even and the odd numbers
    for (int i = 0; i < 13; ++i) {

        // Checks if the number is a digit
        if (!isdigit(EANnr[i])) {
            return false; // Not a digit
        }
        // Adds number to sum of the even or odd numbers depending on the index of the number
        int digit = EANnr[i] - '0';
        if (i % 2 == 1) {
            oddSum += digit;
        } else {
            evenSum += digit;
        }
    }

    // Adds the two sums together and checks if they're modulo 10
    return (oddSum * 3 + evenSum) % 10 == 0;
}

// Converts ISBN to EAN
std::string EAN::convertISBNtoEAN(const std::string& isbn) const {
    std::string tempISBN = "";
    bool foundISBN = false;
    for (char c : isbn) {
        if (isdigit(c)) {
            // Add digit to tempISBN
            tempISBN += c;

        // Check if the ISBN is found and if the next 4 characters are "ISBN"
        } else if (!foundISBN && c == 'I' && isbn.substr(isbn.find('I'), 4) == "ISBN") {
            foundISBN = true;
            tempISBN += "978";
        }
    }

    // Calculate check digit
    int oddSum = 0;
    int evenSum = 0;
    for (int i = 0; i < 12; ++i) {
        int digit = tempISBN[i] - '0';
        if (i % 2 == 1) {
            oddSum += digit;
        } else {
            evenSum += digit;
        }
    }
    // Calculate check digit and add it to the ISBN 
    int checkDigit = (10 - ((oddSum * 3 + evenSum) % 10)) % 10;
    return tempISBN + std::to_string(checkDigit);
}