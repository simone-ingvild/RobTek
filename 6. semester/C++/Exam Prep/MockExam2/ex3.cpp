// ex3.cpp
#include <iostream>
#include <algorithm> // for std::max

// Function to find the maximum value in two arrays of equal length
int maxInBothArrays(int arr1[], int arr2[], int size) {
    int maxVal = arr1[0]; // assume arrays are non-empty
    for (int i = 0; i < size; ++i) {
        maxVal = std::max({maxVal, arr1[i], arr2[i]});
    }
    return maxVal;
}

int main() {
    int a[] = {17, 33, 44, 11, 9};
    int b[] = {22, 66, 1, 35, 22};
    int size = 5;

    std::cout << "Max value in both arrays: "
              << maxInBothArrays(a, b, size) << std::endl;

    return 0;
}
