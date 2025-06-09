#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include "nr3.h"
#include "ludcmp.h"

using namespace std;

const double EPS = 1e-8;
const double TOL_RESIDUAL = 1e-4;
const int MAX_ITER = 100;

const double a1 = 1.1, a2 = 2.1, a3 = 0.8;
const double b1 = 0.4, b2 = 1.3, b3 = 0.5;

using Vec3 = vector<double>;

Vec3 rA(double u) {
    return {
        a1 * pow(cos(1 + u), 3),
        a2 * u * u,
        a3 * u * sin(u)
    };
}

Vec3 rB(double u) {
    return {
        b1 * u + exp(-u * u),
        b2 * pow(u, 3),
        b3 * cos(u)
    };
}

Vec3 rAprime(double u) {
    Vec3 plus = rA(u + EPS);
    Vec3 base = rA(u);
    return {
        (plus[0] - base[0]) / EPS,
        (plus[1] - base[1]) / EPS,
        (plus[2] - base[2]) / EPS
    };
}

Vec3 rBprime(double u) {
    Vec3 plus = rB(u + EPS);
    Vec3 base = rB(u);
    return {
        (plus[0] - base[0]) / EPS,
        (plus[1] - base[1]) / EPS,
        (plus[2] - base[2]) / EPS
    };
}

double dot(const Vec3 &a, const Vec3 &b) {
    return a[0]*b[0] + a[1]*b[1] + a[2]*b[2];
}

double f0(double uA, double uB) {
    Vec3 rA_val = rA(uA);
    Vec3 rB_val = rB(uB);
    Vec3 rA_diff = rAprime(uA);
    Vec3 diff = {
        rA_val[0] - rB_val[0],
        rA_val[1] - rB_val[1],
        rA_val[2] - rB_val[2]
    };
    return dot(rA_diff, diff);
}

double f1(double uA, double uB) {
    Vec3 rA_val = rA(uA);
    Vec3 rB_val = rB(uB);
    Vec3 rB_diff = rBprime(uB);
    Vec3 diff = {
        rA_val[0] - rB_val[0],
        rA_val[1] - rB_val[1],
        rA_val[2] - rB_val[2]
    };
    return -dot(rB_diff, diff);
}

void usrfun(VecDoub_I &x, VecDoub_O &fvec, MatDoub_O &fjac) {
    double uA = x[0];
    double uB = x[1];
    double h = 1e-6;

    fvec[0] = f0(uA, uB);
    fvec[1] = f1(uA, uB);

    fjac[0][0] = (f0(uA + h, uB) - fvec[0]) / h;
    fjac[0][1] = (f0(uA, uB + h) - fvec[0]) / h;
    fjac[1][0] = (f1(uA + h, uB) - fvec[1]) / h;
    fjac[1][1] = (f1(uA, uB + h) - fvec[1]) / h;
}

#include "mnewt.h"

int main() {
    double uA = 1.0;
    double uB = -1.0;

    double f0_val = f0(uA, uB);
    double f1_val = f1(uA, uB);

    cout << fixed << setprecision(10);
    cout << "Part i) Results:\n";
    cout << "f0(1, -1) = " << f0_val << endl;
    cout << "f1(1, -1) = " << f1_val << endl;

    // Part ii: Run Newton's method for 10 steps
    cout << "\nPart ii) Newton's Method (10 iterations):\n";
    VecDoub xvec(2);
    xvec[0] = 1.0;
    xvec[1] = -1.0;
    mnewt(10, xvec, 1e-12, 1e-12);
    cout << "Final uA = " << xvec[0] << endl;
    cout << "Final uB = " << xvec[1] << endl;

    // Part iii: Iterative Newton with convergence based on residual norm
    cout << "\nPart iii) Convergence Check (residual < 1e-4):\n";
    VecDoub x(2);
    x[0] = 1.0;
    x[1] = -1.0;

    int iterations = 0;
    while (iterations < MAX_ITER) {
        VecDoub fvec(2);
        MatDoub fjac(2, 2);
        usrfun(x, fvec, fjac);

        double residual = sqrt(fvec[0]*fvec[0] + fvec[1]*fvec[1]);
        if (residual < TOL_RESIDUAL) break;

        VecDoub p(2);
        for (int i = 0; i < 2; ++i) p[i] = -fvec[i];
        LUdcmp lu(fjac);
        lu.solve(p, p);
        for (int i = 0; i < 2; ++i) x[i] += p[i];

        iterations++;
    }

    cout << "Converged after " << iterations << " iterations." << endl;
    cout << "uA = " << x[0] << ", uB = " << x[1] << endl;

    return 0;
}
