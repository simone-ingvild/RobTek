#include <iostream>
#include "Broek.h"

int main() {
    int taeller1, naevner1, taeller2, naevner2;

    // Bed brugeren om at indtaste den første brøk
    std::cout << "Indtast tæller for den første brøk: ";
    std::cin >> taeller1;
    std::cout << "Indtast nævner for den første brøk: ";
    std::cin >> naevner1;

    // Bed brugeren om at indtaste den anden brøk
    std::cout << "Indtast tæller for den anden brøk: ";
    std::cin >> taeller2;
    std::cout << "Indtast nævner for den anden brøk: ";
    std::cin >> naevner2;

    // Opret Broek-objekter med de indtastede værdier
    Broek b1(taeller1, naevner1);
    Broek b2(taeller2, naevner2);

    // Udregn og udskriv resultaterne
    std::cout << "\nBrøk 1: " << b1.getTaeller() << "/" << b1.getNaevner() << std::endl;
    std::cout << "Brøk 2: " << b2.getTaeller() << "/" << b2.getNaevner() << std::endl;

    Broek sum = b1 + b2;
    Broek forskel = b1 - b2;
    Broek produkt = b1 * b2;
    Broek kvotient = b1 / b2;

    std::cout << "\nSummen af brøkerne: " << sum.getTaeller() << "/" << sum.getNaevner() << std::endl;
    std::cout << "Forskellen mellem brøkerne: " << forskel.getTaeller() << "/" << forskel.getNaevner() << std::endl;
    std::cout << "Produktet af brøkerne: " << produkt.getTaeller() << "/" << produkt.getNaevner() << std::endl;
    std::cout << "Kvotienten af brøkerne: " << kvotient.getTaeller() << "/" << kvotient.getNaevner() << std::endl;

    return 0;
}