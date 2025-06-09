#include "nr3.h"
#include "banded.h"
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int idx(int j, int k, int N) {
    return (N - 1) * (k - 1) + (j - 1);  // 1-based to 0-based indexing
}

Doub solve_poisson(int N, Doub &u_mid) {
    int n = (N - 1) * (N - 1);    // total unknowns
    Doub h = 1.0 / N;
    int m1 = N - 1, m2 = N - 1;

    MatDoub A(n, m1 + m2 + 1, 0.0);
    VecDoub phi(n, 0.0);

    for (int k = 1; k <= N - 1; ++k) {
        for (int j = 1; j <= N - 1; ++j) {
            int i = idx(j, k, N);
            Doub x = j * h;
            Doub y = k * h;
            phi[i] = h * h * (1 + x + y);

            // Center
            A[i][m1] = 4.0;

            // Left neighbor
            if (j > 1)
                A[i][m1 - 1] = -1.0;

            // Right neighbor
            if (j < N - 1)
                A[i][m1 + 1] = -1.0;

            // Bottom neighbor
            if (k > 1)
                A[i][m1 - (N - 1)] = -1.0;

            // Top neighbor
            if (k < N - 1)
                A[i][m1 + (N - 1)] = -1.0;
        }
    }

    Bandec band_solver(A, m1, m2);
    VecDoub solution(n);
    band_solver.solve(phi, solution);

    // Extract u(0.5, 0.5) → closest to (j = N/2, k = N/2)
    int j_mid = N / 2;
    int k_mid = N / 2;
    int i_mid = idx(j_mid, k_mid, N);
    u_mid = solution[i_mid];
    return u_mid;
}

int main() {
    vector<int> Ns = {4, 8, 16, 32, 64, 128};
    vector<Doub> u;

    cout << "umi = u(0.5, 0.5)_i\n";
    cout << "using k=2 for richardson extrapolation error estimate\n";
    cout << left << setw(6) << "i" << setw(8) << "N" << setw(14) << "umi"
         << setw(14) << "umi-1 - umi" << setw(10) << "k" << "e" << "\n";

    for (int i = 0; i < Ns.size(); ++i) {
        Doub umi = 0.0;
        solve_poisson(Ns[i], umi);
        u.push_back(umi);

        cout << left << setw(6) << i + 1 << setw(8) << Ns[i] << setw(14) << fixed << setprecision(6) << umi;

        if (i > 0) {
            Doub diff = u[i - 1] - u[i];
            Doub err = diff / 3.0;  // Richardson for 2nd order
            Doub k = log(abs((u[i - 1] - u[i - 2]) / diff)) / log(2.0);
            cout << setw(14) << scientific << diff
                 << setw(10) << fixed << setprecision(5) << k
                 << scientific << err << endl;
        } else {
            cout << setw(14) << "nan" << setw(10) << "nan" << "nan" << endl;
        }
    }

    return 0;
}
