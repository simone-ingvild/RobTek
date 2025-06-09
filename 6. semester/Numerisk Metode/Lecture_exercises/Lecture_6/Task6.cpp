#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

const double TOL = 1e-8;
const int MAX_ITER = 100;

// Fixed precision formatting
const int PRECISION = 10;

double f(double x) {
    return x - cos(x);
}

double df(double x) {
    return 1 + sin(x);
}

// Utility to print iteration header
void print_header() {
    cout << left << setw(5) << "k"
         << setw(20) << "x_k"
         << setw(20) << "d_k"
         << setw(20) << "C_k"
         << setw(20) << "e_k" << endl;
}

void print_bisection(double a, double b) {
    cout << "\nBisection (C=0.5 assumed, order=1)\n";
    print_header();
    vector<double> xk;
    double c;
    cout << fixed << setprecision(PRECISION);
    for (int k = 0; k < MAX_ITER; ++k) {
        c = 0.5 * (a + b);
        xk.push_back(c);
        double dx = (k == 0) ? 0.0 : xk[k] - xk[k - 1];
        double C = (k > 1 && fabs(xk[k - 1] - xk[k - 2]) > 0.0) ? fabs(dx) / fabs(xk[k - 1] - xk[k - 2]) : 0.0;
        double e_k = fabs(dx) / (1 - 0.5);
        cout << left << setw(5) << k+1
             << setw(20) << xk[k]
             << setw(20) << dx
             << setw(20) << C
             << setw(20) << e_k << endl;
        if (fabs(f(c)) < TOL || fabs(b - a) < TOL) break;
        if (f(a) * f(c) < 0) b = c;
        else a = c;
    }
    cout << "Result: x = " << c << endl;
}

void print_secant(double x0, double x1) {
    cout << "\nSecant (order ~1.618)\n";
    print_header();
    vector<double> xk = {x0, x1};
    double xk_new;
    cout << fixed << setprecision(PRECISION);
    for (int k = 2; k < MAX_ITER; ++k) {
        double fx0 = f(xk[k - 2]), fx1 = f(xk[k - 1]);
        xk_new = xk[k - 1] - fx1 * (xk[k - 1] - xk[k - 2]) / (fx1 - fx0);
        xk.push_back(xk_new);
        double d_k = xk[k] - xk[k - 1];
        double C_k = (k >= 2 && fabs(xk[k - 1] - xk[k - 2]) > 0.0) ? fabs(d_k) / pow(fabs(xk[k - 1] - xk[k - 2]), 1.618) : 0.0;
        double e_k = fabs(d_k);
        cout << left << setw(5) << k
             << setw(20) << xk[k]
             << setw(20) << d_k
             << setw(20) << C_k
             << setw(20) << e_k << endl;
        if (fabs(d_k) < TOL) break;
    }
    cout << "Result: x = " << xk.back() << endl;
}

void print_newton(double x0) {
    cout << "\nNewton (order = 2)\n";
    print_header();
    vector<double> xk = {x0};
    double xk_new;
    cout << fixed << setprecision(PRECISION);
    for (int k = 1; k <= MAX_ITER; ++k) {
        double dx = -f(xk.back()) / df(xk.back());
        xk_new = xk.back() + dx;
        xk.push_back(xk_new);
        double d_k = xk[k] - xk[k - 1];
        double C_k = (k >= 2 && fabs(xk[k - 1] - xk[k - 2]) > 0.0) ? fabs(d_k) / pow(fabs(xk[k - 1] - xk[k - 2]), 2.0) : 0.0;
        double e_k = fabs(d_k);
        cout << left << setw(5) << k
             << setw(20) << xk[k]
             << setw(20) << d_k
             << setw(20) << C_k
             << setw(20) << e_k << endl;
        if (fabs(d_k) < TOL) break;
    }
    cout << "Result: x = " << xk.back() << endl;
}

void print_false_position(double a, double b) {
    cout << "\nFalse Position (order ~1)\n";
    print_header();
    vector<double> xk;
    double c = a;
    cout << fixed << setprecision(PRECISION);
    for (int k = 0; k < MAX_ITER; ++k) {
        double fa = f(a), fb = f(b);
        c = b - fb * (b - a) / (fb - fa);
        xk.push_back(c);
        double dx = (k == 0) ? 0.0 : xk[k] - xk[k - 1];
        double C_k = (k > 1 && fabs(xk[k - 1] - xk[k - 2]) > 0.0) ? fabs(dx) / fabs(xk[k - 1] - xk[k - 2]) : 0.0;
        double e_k = fabs(dx);
        cout << left << setw(5) << k+1
             << setw(20) << xk[k]
             << setw(20) << dx
             << setw(20) << C_k
             << setw(20) << e_k << endl;
        if (fabs(f(c)) < TOL) break;
        if (fa * f(c) < 0) b = c;
        else a = c;
    }
    cout << "Result: x = " << c << endl;
}

void print_ridder(double a, double b) {
    cout << "\nRidder (order ~2)\n";
    print_header();
    vector<double> xk;
    double c = a;
    cout << fixed << setprecision(PRECISION);
    for (int k = 0; k < MAX_ITER; ++k) {
        double fa = f(a), fb = f(b);
        double xm = 0.5 * (a + b);
        double fm = f(xm);
        double s = sqrt(fm * fm - fa * fb);
        if (s == 0.0) break;
        c = xm + (xm - a) * ((fa >= fb ? 1 : -1) * fm / s);
        xk.push_back(c);
        double dx = (k == 0) ? 0.0 : xk[k] - xk[k - 1];
        double C_k = (k > 1 && fabs(xk[k - 1] - xk[k - 2]) > 0.0) ? fabs(dx) / pow(fabs(xk[k - 1] - xk[k - 2]), 2.0) : 0.0;
        double e_k = fabs(dx);
        cout << left << setw(5) << k+1
             << setw(20) << xk[k]
             << setw(20) << dx
             << setw(20) << C_k
             << setw(20) << e_k << endl;
        if (fabs(f(c)) < TOL) break;
        if (fa * f(c) < 0) b = c;
        else a = c;
    }
    cout << "Result: x = " << c << endl;
}

int main() {
    double pi_2 = M_PI / 2.0;

    print_bisection(0.0, pi_2);
    print_secant(0.0, pi_2);
    print_false_position(0.0, pi_2);
    print_ridder(0.0, pi_2);
    print_newton(0.0);

    return 0;
}
