#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <fstream>
#include "nr3.h"
#include "finitedifference.h"

using namespace std;

// Surface r(u,v) = (u, v, v^4 - 2u^4)
VecDoub surface_r(Doub u, Doub v) {
    VecDoub r(3);
    r[0] = u;
    r[1] = v;
    r[2] = pow(v, 4) - 2 * pow(u, 4);
    return r;
}

int main() {
    const Doub uA = -0.9, vA = -0.85;
    const Doub uB = 0.8,  vB = -0.9;
    const Doub tol = 1e-6;

    VecInt Nvals(8);
    Nvals[0] = 2; Nvals[1] = 4; Nvals[2] = 8; Nvals[3] = 16;
    Nvals[4] = 32; Nvals[5] = 64; Nvals[6] = 128; Nvals[7] = 256;

    cout << fixed << setprecision(8);
    cout << "Part i) Finite Difference Solution for V(u):\n";
    cout << "N\tmidpoint u\tV(midpoint)\tconverged?\n";

    VecDoub u, V;
    Doub midpoint_u = 0.5 * (uA + uB);
    Doub best_Vmid = 0.0;
    Int best_N = 0;

    for (int i = 0; i < Nvals.size(); ++i) {
        Int N = Nvals[i];
        bool success = solve_bvp(uA, vA, uB, vB, N, u, V, tol);

        // Find V at midpoint
        Doub Vmid = 0.0;
        for (int j = 0; j < u.size() - 1; ++j) {
            if (u[j] <= midpoint_u && u[j + 1] >= midpoint_u) {
                Doub t = (midpoint_u - u[j]) / (u[j + 1] - u[j]);
                Vmid = (1 - t) * V[j] + t * V[j + 1];
                break;
            }
        }

        cout << N << "\t" << midpoint_u << "\t" << Vmid << "\t" << (success ? "yes" : "no") << "\n";

        if (success) {
            best_N = N;
            best_Vmid = Vmid;
        }
    }

    // Part ii) Print geodesic for best N
    cout << "\nPart ii) Geodesic curve r(u, V(u)) for N = " << best_N << ":\n";
    solve_bvp(uA, vA, uB, vB, best_N, u, V, tol);

    cout << "u\tV(u)\tr_x\tr_y\tr_z\n";
    for (int i = 0; i <= best_N; ++i) {
        VecDoub r = surface_r(u[i], V[i]);
        cout << u[i] << "\t" << V[i] << "\t" << r[0] << "\t" << r[1] << "\t" << r[2] << "\n";
    }

    // CSV output
    ofstream fout("geodesic.csv");
    fout << "u,V,r_x,r_y,r_z\n";
    for (int i = 0; i <= best_N; ++i) {
        VecDoub r = surface_r(u[i], V[i]);
        fout << u[i] << "," << V[i] << "," << r[0] << "," << r[1] << "," << r[2] << "\n";
    }
    fout.close();
    cout << "\nTrajectory written to geodesic.csv (for visualization).\n";

    return 0;
}
