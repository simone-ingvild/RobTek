#include <iostream>
#include <iomanip>
#include <cmath>
#include "nr3.h"
#include "qrdcmp.h"
#include "ludcmp.h"
#include "roots_multidim.h"

using namespace std;

// Task 7: Solving a system of nonlinear equations using Newton's method
// Equations:
// (1) x0 + 2*sin(x1 - x0) - exp(-sin(x1 + x0)) = 0
// (2) x0*cos(x1) + sin(x0) - 1 = 0

struct System {
    VecDoub operator()(const VecDoub &x) {
        VecDoub f(2);
        f[0] = x[0] + 2 * sin(x[1] - x[0]) - exp(-sin(x[1] + x[0]));
        f[1] = x[0] * cos(x[1]) + sin(x[0]) - 1;
        return f;
    }
};

int main() {
    cout << fixed << setprecision(10);

    // Step 1: Evaluate LHS of system at x0=1, x1=1
    VecDoub initial_check(2);
    initial_check[0] = 1.0;
    initial_check[1] = 1.0;
    System system;
    VecDoub fvals = system(initial_check);

    cout << "Initial evaluation at x0 = 1, x1 = 1:\n";
    cout << "f1(x0,x1) = " << fvals[0] << endl;
    cout << "f2(x0,x1) = " << fvals[1] << endl << endl;

    // Step 2: Newton's method from x0 = 1, x1 = 2 (manual iteration)
    VecDoub x(2);
    x[0] = 1.0;
    x[1] = 2.0;

    const double h = 1e-8;
    int n = 2;
    MatDoub J(n, n);
    VecDoub f(n), dx(n), x_old(n);
    double dx_k, ratio, e, prev_dx_k = 0.0;

    cout << "\nNewton Iterations (starting from x0=1, x1=2):\n";
    cout << setw(4) << "k"
         << setw(15) << "x0"
         << setw(15) << "x1"
         << setw(15) << "dx_k"
         << setw(20) << "dx_k/dx_(k-1)^2"
         << setw(15) << "e" << endl;

    for (int k = 0; k < 6; k++) {
        x_old = x;
        f = system(x);

        // Finite difference Jacobian
        for (int j = 0; j < n; j++) {
            VecDoub xh = x;
            xh[j] += h;
            VecDoub fh = system(xh);
            for (int i = 0; i < n; i++)
                J[i][j] = (fh[i] - f[i]) / h;
        }

        LUdcmp lu(J);
        lu.solve(f, dx);

        for (int i = 0; i < n; i++)
            x[i] -= dx[i];

        dx_k = sqrt(dx[0] * dx[0] + dx[1] * dx[1]);
        ratio = (k > 0 && prev_dx_k > 1e-14) ? dx_k / (prev_dx_k * prev_dx_k) : INFINITY;
        e = dx_k;
        prev_dx_k = dx_k;

        cout << setw(4) << k
             << setw(15) << x[0]
             << setw(15) << x[1]
             << setw(15) << dx_k
             << setw(20) << ratio
             << setw(15) << e << endl;
    }

    cout << "\nEstimated error after 6 iterations: " << dx_k << endl;
    cout << "(Based on Euclidean norm of last dx)\n";

    return 0;
}
