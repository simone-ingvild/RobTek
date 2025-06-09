#include <iostream>
#include <cmath>
#include <functional>
#include "midpoint.h"
#include "trapezoidal.h"
#include "simpson.h"

int main() {
    using namespace std;

    auto f1 = [](double x) { return cos(x * x) * exp(-x); };
    auto f2 = [](double x) { return sqrt(x) * cos(x * x) * exp(-x); };
    auto f3 = [](double x) { return (x > 0) ? (cos(x * x) * exp(-x) / sqrt(x)) : 0.0; };
    auto f4 = [](double x) {
        if (x <= 0.0 || x >= 1.0) return 0.0;
        return 1000 * exp(-1.0 / x) * exp(-1.0 / (1.0 - x));
    };

    double a = 0.0, b = 1.0;
    int n = 1024; // You can increase this for better precision

    cout.precision(8);

    // Equation 1
    cout << "Equation 1: ∫ cos(x^2) * exp(-x) dx\n";
    cout << "Midpoint:     " << midpoint_rule(f1, a, b, n) << endl;
    cout << "Trapezoidal:  " << trapezoidal_rule(f1, a, b, n) << endl;
    cout << "Simpson:      " << simpsons_rule(f1, a, b, n) << endl;

    // Equation 2
    cout << "\nEquation 2: ∫ sqrt(x) * cos(x^2) * exp(-x) dx\n";
    cout << "Simpson:      " << simpsons_rule(f2, a, b, n) << endl;

    // Equation 3
    cout << "\nEquation 3: ∫ (1/sqrt(x)) * cos(x^2) * exp(-x) dx\n";
    cout << "Midpoint:     " << midpoint_rule(f3, a, b, n) << endl;

    // Equation 4
    cout << "\nEquation 4: ∫ 1000 * exp(-1/x) * exp(-1/(1-x)) dx\n";
    cout << "Trapezoidal:  " << trapezoidal_rule(f4, a, b, n) << endl;

    return 0;
}
