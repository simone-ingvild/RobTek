#include <iostream>
#include <iomanip>
#include <cmath>
#include "nr3.h"
#include "tridag.h"

using namespace std;

// Define the residual F_i(y)
Doub residual(Doub ym, Doub y0, Doub yp, Doub x, Doub h) {
    Doub dy = (yp - ym) / (2 * h);
    return (ym - 2 * y0 + yp) / (h * h) - (2 * x + sin(dy) - cos(y0));
}

// Derivatives for Jacobian entries
Doub dF_dym(Doub ym, Doub y0, Doub yp, Doub h) {
    Doub dy = (yp - ym) / (2 * h);
    return (1.0 / (h * h)) - (1.0 / (2 * h)) * cos(dy);
}

Doub dF_dy0(Doub y0, Doub h) {
    return -2.0 / (h * h) + sin(y0);
}

Doub dF_dyp(Doub ym, Doub yp, Doub h) {
    Doub dy = (yp - ym) / (2 * h);
    return (1.0 / (h * h)) + (1.0 / (2 * h)) * cos(dy);
}

void solveBVP(int N, VecDoub &y, Doub &y1) {
    Doub a = 0.0, b = 2.0;
    Doub h = (b - a) / N;

    VecDoub x(N + 1);
    for (int i = 0; i <= N; ++i)
        x[i] = a + i * h;

    y.resize(N + 1);
    for (int i = 0; i <= N; ++i)
        y[i] = x[i] / 2.0;

    y[0] = 0.0;
    y[N] = 1.0;

    VecDoub a_tr(N - 1), b_tr(N - 1), c_tr(N - 1), rhs(N - 1), dy(N - 1);

    for (int iter = 0; iter < 100; ++iter) {
        for (int i = 1; i < N; ++i) {
            rhs[i - 1] = -residual(y[i - 1], y[i], y[i + 1], x[i], h);
            a_tr[i - 1] = dF_dym(y[i - 1], y[i], y[i + 1], h);
            b_tr[i - 1] = dF_dy0(y[i], h);
            c_tr[i - 1] = dF_dyp(y[i - 1], y[i + 1], h);
        }

        tridag(a_tr, b_tr, c_tr, rhs, dy);

        Doub max_corr = 0.0;
        for (int i = 1; i < N; ++i) {
            y[i] += dy[i - 1];
            max_corr = max(max_corr, abs(dy[i - 1]));
        }

        if (max_corr < 1e-10) break;
    }

    // Interpolate y(1)
    int idx = int(1.0 / h);
    Doub t = (1.0 - x[idx]) / (x[idx + 1] - x[idx]);
    y1 = y[idx] + t * (y[idx + 1] - y[idx]);
}

int main() {
    vector<int> Nvals = {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
    vector<Doub> results;

    cout << "i\tA(h_i)\t\tA(h_{i-1}) - A(h_i)\talp^k\t\terror\n";

    for (size_t i = 0; i < Nvals.size(); ++i) {
        VecDoub y;
        Doub y1;
        solveBVP(Nvals[i], y, y1);
        results.push_back(y1);

        cout << i + 1 << "\t" << setprecision(8) << y1;

        if (i > 0) {
            Doub diff = results[i - 1] - results[i];
            Doub error = abs(diff) / 3.0; // midpoint estimate
            cout << "\t" << diff << "\t\t4.0000\t" << error << "\n";
        } else {
            cout << "\n";
        }
    }

    return 0;
}
