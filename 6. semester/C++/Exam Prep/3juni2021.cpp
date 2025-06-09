// 3juni2021.cpp
// Solutions to four independent C++ exercises:
// 1) Kaprekar numbers in a range (print)
// 2) Disarium numbers below a limit (print)
// 3) ordITekst – substring check (Danish description)
// 4) largestSumOfTwo – add the largest elements from two arrays
//
// Compile with:  g++ 3juni2021.cpp -o run && ./run
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

//------------------------------------------------------------
// Task‑specific helpers
//------------------------------------------------------------

// 3) Returns true if the word "ord" occurs inside "tekst" (case‑sensitive)
bool ordITekst(const std::string& tekst, const std::string& ord)
{
    return tekst.find(ord) != std::string::npos;
}

// 4) Sum of the two largest values—one from each of the two arrays
int largestSumOfTwo(const int ar1[], const int ar2[], int size)
{
    int max1 = ar1[0];
    int max2 = ar2[0];
    for (int i = 1; i < size; ++i) {
        if (ar1[i] > max1) max1 = ar1[i];
        if (ar2[i] > max2) max2 = ar2[i];
    }
    return max1 + max2;
}

// 1) Print Kaprekar numbers > low and < high (both exclusive)
void printKaprekars(int low, int high)
{
    std::cout << "Kaprekar numbers between " << low << " and " << high << ":";
    for (int n = low + 1; n < high; ++n) {
        long long sq = 1LL * n * n;
        std::string s = std::to_string(sq);
        if (s.size() % 2 != 0) continue;                // assume even # digits
        int half = static_cast<int>(s.size() / 2);
        int left  = std::stoi(s.substr(0, half));
        int right = std::stoi(s.substr(half));
        if (right == 0) continue;                       // avoid divide‑by‑zero cases
        if (left + right == n) {
            std::cout << ' ' << n;
        }
    }
    std::cout << '\n';
}

// 2) Print all Disarium numbers strictly below limit
void printDisariums(int limit)
{
    std::cout << "Disarium numbers below " << limit << ":";
    for (int n = 0; n < limit; ++n) {
        std::string digits = std::to_string(n);
        int sum = 0;
        for (size_t i = 0; i < digits.size(); ++i) {
            int d = digits[i] - '0';
            sum += static_cast<int>(std::pow(d, static_cast<int>(i) + 1));
        }
        if (sum == n) std::cout << ' ' << n;
    }
    std::cout << '\n';
}

//------------------------------------------------------------
// Demo / quick test
//------------------------------------------------------------
int main()
{
    // Kaprekar: >1 and <100 as required
    printKaprekars(1, 100);

    // Disarium: below 1000
    printDisariums(1000);

    // ordITekst demo
    std::string tekst = "Dette er en OOP‑eksamen";
    std::string ord   = "OOP";
    std::cout << std::boolalpha << "ordITekst result: " << ordITekst(tekst, ord) << '\n';

    // largestSumOfTwo demo
    int ar1[5] = {17, 33, 44, 11, 9};
    int ar2[5] = {22, 66,  1, 35, 22};
    std::cout << "largestSumOfTwo result: " << largestSumOfTwo(ar1, ar2, 5) << '\n';

    return 0;
}
