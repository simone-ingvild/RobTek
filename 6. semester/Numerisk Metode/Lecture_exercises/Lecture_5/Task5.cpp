#include <iostream>
#include <iomanip>
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

const double TOL = 1e-8;
const int MAX_ITER = 100;

double f(double x) {
    return x - cos(x);
}

double df(double x) {
    return 1 + sin(x);
}

int bisection(double a, double b, double &result) {
    double c;
    for (int k = 1; k <= MAX_ITER; ++k) {
        c = (a + b) / 2.0;
        if (fabs(f(c)) < TOL || fabs(b - a) < TOL) {
            result = c;
            return k;
        }
        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;
    }
    result = c;
    return MAX_ITER;
}

int secant(double x0, double x1, double &result) {
    double xk, dx;
    for (int k = 1; k <= MAX_ITER; ++k) {
        double fx0 = f(x0), fx1 = f(x1);
        xk = x1 - fx1 * (x1 - x0) / (fx1 - fx0);
        dx = xk - x1;
        if (fabs(dx) < TOL) {
            result = xk;
            return k;
        }
        x0 = x1;
        x1 = xk;
    }
    result = xk;
    return MAX_ITER;
}

int false_position(double a, double b, double &result) {
    double x;
    for (int k = 1; k <= MAX_ITER; ++k) {
        x = b - f(b)*(b - a)/(f(b) - f(a));
        if (fabs(f(x)) < TOL || fabs(b - a) < TOL) {
            result = x;
            return k;
        }
        if (f(a) * f(x) < 0)
            b = x;
        else
            a = x;
    }
    result = x;
    return MAX_ITER;
}

int ridder(double a, double b, double &result) {
    double x;
    for (int k = 1; k <= MAX_ITER; ++k) {
        double c = 0.5 * (a + b);
        double d = sqrt(f(c) * f(c) - f(a) * f(b));
        if (d == 0.0) break;
        x = c + (c - a) * ((f(a) >= f(b)) ? 1 : -1) * f(c) / d;
        if (fabs(f(x)) < TOL || fabs(b - a) < TOL) {
            result = x;
            return k;
        }
        if (f(a) * f(x) < 0) b = x;
        else a = x;
    }
    result = x;
    return MAX_ITER;
}

int newton(double x0, double &result) {
    double xk = x0, dx;
    for (int k = 1; k <= MAX_ITER; ++k) {
        dx = -f(xk) / df(xk);
        xk += dx;
        if (fabs(dx) < TOL) {
            result = xk;
            return k;
        }
    }
    result = xk;
    return MAX_ITER;
}

void print_bisection(double a, double b) {
    cout << "\nBisection\n";
    cout << setw(5) << "k" << setw(12) << "xmin" << setw(12) << "xmax" << setw(12) << "dx" << endl;
    double c, dx;
    for (int k = 1; k <= MAX_ITER; ++k) {
        c = (a + b) / 2.0;
        dx = fabs(b - a);
        cout << setw(5) << k << setw(12) << a << setw(12) << b << setw(12) << dx << endl;
        if (fabs(f(c)) < TOL || dx < TOL) break;
        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;
    }
    cout << "Result:\n" << c << endl;
}

void print_secant(double x0, double x1) {
    cout << "\nSecant\n";
    cout << setw(5) << "k" << setw(20) << "x" << setw(20) << "dx" << endl;
    double xk, dx;
    for (int k = 1; k <= MAX_ITER; ++k) {
        double fx0 = f(x0), fx1 = f(x1);
        xk = x1 - fx1 * (x1 - x0) / (fx1 - fx0);
        dx = xk - x1;
        cout << setw(5) << k << setw(20) << xk << setw(20) << dx << endl;
        if (fabs(dx) < TOL) break;
        x0 = x1;
        x1 = xk;
    }
    cout << "Result:\n" << xk << endl;
}

void print_false_position(double a, double b) {
    cout << "\nFalse Position\n";
    cout << setw(5) << "k" << setw(12) << "xmin" << setw(12) << "xmax" << setw(12) << "dx" << endl;
    double x, dx;
    for (int k = 1; k <= MAX_ITER; ++k) {
        x = b - f(b)*(b - a)/(f(b) - f(a));
        dx = b - a;
        cout << setw(5) << k << setw(12) << a << setw(12) << b << setw(12) << dx << endl;
        if (fabs(f(x)) < TOL || dx < TOL) break;
        if (f(a) * f(x) < 0)
            b = x;
        else
            a = x;
    }
    cout << "Result:\n" << x << endl;
}

void print_ridder(double a, double b) {
    cout << "\nRidder\n";
    cout << setw(5) << "k" << setw(12) << "x" << setw(12) << "dx" << endl;
    double x, dx;
    for (int k = 1; k <= MAX_ITER; ++k) {
        double c = 0.5 * (a + b);
        double d = sqrt(f(c) * f(c) - f(a) * f(b));
        if (d == 0.0) break;
        x = c + (c - a) * ((f(a) >= f(b)) ? 1 : -1) * f(c) / d;
        dx = fabs(b - a);
        cout << setw(5) << k << setw(12) << x << setw(12) << dx << endl;
        if (fabs(f(x)) < TOL || dx < TOL) break;
        if (f(a) * f(x) < 0) b = x;
        else a = x;
    }
    cout << "Result:\n" << x << endl;
}

void print_newton(double x0) {
    cout << "\nNewton\n";
    cout << setw(5) << "k" << setw(20) << "x" << setw(20) << "dx" << endl;
    double xk = x0, dx;
    for (int k = 1; k <= MAX_ITER; ++k) {
        dx = -f(xk) / df(xk);
        xk += dx;
        cout << setw(5) << k << setw(20) << xk << setw(20) << dx << endl;
        if (fabs(dx) < TOL) break;
    }
    cout << "Result:\n" << xk << endl;
}

int main() {
    double pi_2 = M_PI / 2.0;

    print_bisection(0.0, pi_2);
    print_secant(0.0, pi_2);
    print_false_position(0.0, pi_2);
    print_ridder(0.0, pi_2);
    print_newton(0.0);

    // Comparison summary
    double rb, rs, rfp, rr, rn;
    int ib = bisection(0.0, pi_2, rb);
    int is = secant(0.0, pi_2, rs);
    int ifp = false_position(0.0, pi_2, rfp);
    int ir = ridder(0.0, pi_2, rr);
    int in = newton(0.0, rn);

    cout << fixed << setprecision(10);
    cout << "\nSummary of Results (Side-by-Side):\n";
    cout << left << setw(15) << "Method" << setw(15) << "Iterations" << "Result" << endl;
    cout << string(45, '-') << endl;
    cout << left << setw(15) << "Bisection" << setw(15) << ib << rb << endl;
    cout << left << setw(15) << "Secant" << setw(15) << is << rs << endl;
    cout << left << setw(15) << "False Pos." << setw(15) << ifp << rfp << endl;
    cout << left << setw(15) << "Ridder" << setw(15) << ir << rr << endl;
    cout << left << setw(15) << "Newton" << setw(15) << in << rn << endl;

    return 0;
}
