#include <iostream>
#include <cmath>
#include "nr3.h"
#include "quadrature.h"
#include "derule.h"

using namespace std;

// Equation 1: f(x) = cos(x^2) * e^(-x)
struct F1 {
    Doub operator()(Doub x, Doub) {
        return cos(x * x) * exp(-x);
    }
};

// Equation 2: f(x) = sqrt(x) * cos(x^2) * e^(-x)
struct F2 {
    Doub operator()(Doub x, Doub) {
        return sqrt(x) * cos(x * x) * exp(-x);
    }
};

// Equation 3: f(x) = (1/sqrt(x)) * cos(x^2) * e^(-x)
struct F3 {
    Doub operator()(Doub x, Doub) {
        return (x > 0.0) ? (cos(x * x) * exp(-x) / sqrt(x)) : 0.0;
    }
};

// Equation 4: f(x) = 1000 * e^(-1/x) * e^(-1/(1 - x))
struct F4 {
    Doub operator()(Doub x, Doub) {
        if (x <= 0.0 || x >= 1.0) return 0.0;
        return 1000.0 * exp(-1.0 / x) * exp(-1.0 / (1.0 - x));
    }
};

// General-purpose DE integration with controlled iterations
template<typename T>
void compute_DE_integral(const string& label, T& func, Doub a, Doub b, int target_iters, Doub hmax = 3.7) {
    cout << label << " result:\n";
    DErule<T> rule(func, a, b, hmax);
    Doub prev = 0.0, current = 0.0;

    for (int i = 1; i <= target_iters; ++i) {
        current = rule.next();
        cout << "i\t" << i << "\tA(h_i)\t" << current;

        if (i > 1) {
            Doub diff = prev - current;
            cout << "\tA(h_(i-1)) - A(h_i)\t" << diff;
        }

        cout << endl;
        prev = current;
    }

    // Final value
    cout << current << "\n\n";
}

int main() {
    cout.precision(10);
    Doub a = 0.0, b = 1.0;

    // Instantiate each function
    F1 f1;
    F2 f2;
    F3 f3;
    F4 f4;

    // Compute each DE integral with specified iteration counts
    compute_DE_integral("Function 1", f1, a, b, 7); // Equation 1
    compute_DE_integral("Function 2", f2, a, b, 7); // Equation 2
    compute_DE_integral("Function 3", f3, a, b, 7); // Equation 3
    compute_DE_integral("Function 4", f4, a, b, 8); // Equation 4

    return 0;
}
