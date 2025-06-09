#include <iostream>
#include <algorithm> // For std::sort

int largestSumOfTwo(int ar1[], int ar2[], int size) {
    // Sorter begge arrays i faldende rækkefølge
    std::sort(ar1, ar1 + size, std::greater<int>());
    std::sort(ar2, ar2 + size, std::greater<int>());

    // Returner summen af de to største elementer (første element i hvert sorteret array)
    return ar1[0] + ar2[0];
}

int main() {
    int ar1[] = {17, 33, 44, 11, 9};
    int ar2[] = {22, 66, 1, 35, 22};
    int size = 5;

    int sum = largestSumOfTwo(ar1, ar2, size);
    std::cout << "Summen af de to største tal er: " << sum << std::endl;

    return 0;
}