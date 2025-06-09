#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // For std::sort

// a) Palindrom-tjek
bool erPalindrom(const std::string& tekst) {
    std::string omvendtTekst = tekst;
    std::reverse(omvendtTekst.begin(), omvendtTekst.end());
    return tekst == omvendtTekst;
}

// b) Balancerede parenteser
bool erBalanceredeParenteser(const std::string& tekst) {
    int balance = 0;
    for (char c : tekst) {
        if (c == '(') {
            balance++;
        } else if (c == ')') {
            balance--;
        }
        if (balance < 0) {
            return false; // Flere lukkende end åbnende
        }
    }
    return balance == 0; // Samme antal åbnende og lukkende
}

// c) Søgning i sorteret array (binær søgning)
bool findHeltalSorteret(const std::vector<int>& array, int tal) {
    int venstre = 0;
    int højre = array.size() - 1;

    while (venstre <= højre) {
        int midte = venstre + (højre - venstre) / 2;
        if (array[midte] == tal) {
            return true;
        } else if (array[midte] < tal) {
            venstre = midte + 1;
        } else {
            højre = midte - 1;
        }
    }
    return false;
}

// c) Søgning i usorteret array (lineær søgning)
bool findHeltalUsorteret(const std::vector<int>& array, int tal) {
    for (int element : array) {
        if (element == tal) {
            return true;
        }
    }
    return false;
}

int main() {
    std::cout << "--- Palindrom Test ---" << std::endl;
    std::cout << "'mellem' er et palindrom: " << std::boolalpha << erPalindrom("mellem") << std::endl;
    std::cout << "'regninger' er et palindrom: " << std::boolalpha << erPalindrom("regninger") << std::endl;
    std::cout << std::endl; // Tom linje for at adskille resultater

    std::cout << "--- Balancerede Parenteser Test ---" << std::endl;
    std::cout << "'(()))(' er balancerede parenteser: " << std::boolalpha << erBalanceredeParenteser("(()))(") << std::endl;
    std::cout << "'(abc(def)ghi)' er balancerede parenteser: " << std::boolalpha << erBalanceredeParenteser("(abc(def)ghi)") << std::endl;
    std::cout << std::endl;

    std::cout << "--- Søgning i Array Test ---" << std::endl;
    std::vector<int> sorteretArray = {1, 3, 5, 7, 9};
    std::vector<int> usorteretArray = {9, 1, 5, 3, 7};

    std::cout << "Sorteret Array: {1, 3, 5, 7, 9}" << std::endl;
    std::cout << "Er 5 i sorteret array? " << std::boolalpha << findHeltalSorteret(sorteretArray, 5) << std::endl;
    std::cout << "Er 2 i sorteret array? " << std::boolalpha << findHeltalSorteret(sorteretArray, 2) << std::endl;
    std::cout << std::endl;

    std::cout << "Usorteret Array: {9, 1, 5, 3, 7}" << std::endl;
    std::cout << "Er 5 i usorteret array? " << std::boolalpha << findHeltalUsorteret(usorteretArray, 5) << std::endl;
    std::cout << "Er 2 i usorteret array? " << std::boolalpha << findHeltalUsorteret(usorteretArray, 2) << std::endl;

    return 0;
}