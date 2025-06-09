// mathematics.cpp (no <cmath>, pure C++)
// A collection of mathematics-related functions in C++ implemented without standard math libraries

#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

// ========== BASIC MATH UTILITIES ==========
int power(int base, int exp) {
    int result = 1;
    while (exp--) result *= base;
    return result;
} // Integer exponentiation

double absolute(double x) {
    return (x < 0) ? -x : x;
} // Absolute value

double sqrt(double x) {
    double guess = x, epsilon = 1e-6;
    while (absolute(guess * guess - x) > epsilon) {
        guess = (guess + x / guess) / 2.0;
    }
    return guess;
} // Square root using Newton-Raphson

// ========== TRIGONOMETRY (Taylor Series) ==========
double sine(double x) {
    double term = x, sum = x;
    for (int i = 1; i < 10; ++i) {
        term *= -x * x / ((2 * i) * (2 * i + 1));
        sum += term;
    }
    return sum;
} // Approximation of sin(x)

double cosine(double x) {
    double term = 1, sum = 1;
    for (int i = 1; i < 10; ++i) {
        term *= -x * x / ((2 * i - 1) * (2 * i));
        sum += term;
    }
    return sum;
} // Approximation of cos(x)

double tangent(double x) {
    return sine(x) / cosine(x);
} // tan(x)

double cotangent(double x) {
    return cosine(x) / sine(x);
} // cot(x)

double secant(double x) {
    return 1 / cosine(x);
} // sec(x)

double cosecant(double x) {
    return 1 / sine(x);
} // csc(x)

// ========== REPLACEMENTS FOR STD FUNCTIONS ==========
template <typename T>
double average(const vector<T>& data) {
    double sum = 0.0;
    for (T val : data) sum += val;
    return sum / data.size();
} // Mean/average

double variance(const vector<int>& data) {
    double m = average(data);
    double var = 0.0;
    for (int x : data) var += (x - m) * (x - m);
    return var / data.size();
} // Variance

double standardDeviation(const vector<int>& data) {
    return sqrt(variance(data));
} // Standard deviation

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
} // GCD (iterative)

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
} // LCM based on GCD


int main (){
    cout << "Mathematical library loaded.\n";
    return 0;
}