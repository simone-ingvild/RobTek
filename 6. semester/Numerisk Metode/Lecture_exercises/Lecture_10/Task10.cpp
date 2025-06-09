#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include "nr3.h"

using namespace std;

// Euler method for the system
void euler_method(double u0, double v0, double h, int n_steps, double &uf, double &vf) {
    double u = u0, v = v0;
    for (int i = 0; i < n_steps; ++i) {
        double du = u * v;
        double dv = -u * u;
        u += h * du;
        v += h * dv;
    }
    uf = u;
    vf = v;
}

// Midpoint method for the system
void midpoint_method(double u0, double v0, double h, int n_steps, double &uf, double &vf) {
    double u = u0, v = v0;
    for (int i = 0; i < n_steps; ++i) {
        double ku1 = u * v;
        double kv1 = -u * u;

        double u_half = u + 0.5 * h * ku1;
        double v_half = v + 0.5 * h * kv1;

        double ku2 = u_half * v_half;
        double kv2 = -u_half * u_half;

        u += h * ku2;
        v += h * kv2;
    }
    uf = u;
    vf = v;
}

// Trapezoidal method for the system
void trapezoidal_method(double u0, double v0, double h, int n_steps, double &uf, double &vf) {
    double u = u0, v = v0;
    for (int i = 0; i < n_steps; ++i) {
        double du1 = u * v;
        double dv1 = -u * u;

        double u_temp = u + h * du1;
        double v_temp = v + h * dv1;

        double du2 = u_temp * v_temp;
        double dv2 = -u_temp * u_temp;

        u += h * 0.5 * (du1 + du2);
        v += h * 0.5 * (dv1 + dv2);
    }
    uf = u;
    vf = v;
}

// RK4 reference solution
void rk4_method(double u0, double v0, double h, int n_steps, double &uf, double &vf) {
    double u = u0, v = v0;
    for (int i = 0; i < n_steps; ++i) {
        double ku1 = u * v;
        double kv1 = -u * u;

        double ku2 = (u + 0.5 * h * ku1) * (v + 0.5 * h * kv1);
        double kv2 = -(u + 0.5 * h * ku1) * (u + 0.5 * h * ku1);

        double ku3 = (u + 0.5 * h * ku2) * (v + 0.5 * h * kv2);
        double kv3 = -(u + 0.5 * h * ku2) * (u + 0.5 * h * ku2);

        double ku4 = (u + h * ku3) * (v + h * kv3);
        double kv4 = -(u + h * ku3) * (u + h * ku3);

        u += h * (ku1 + 2 * ku2 + 2 * ku3 + ku4) / 6.0;
        v += h * (kv1 + 2 * kv2 + 2 * kv3 + kv4) / 6.0;
    }
    uf = u;
    vf = v;
}

void run_method(const string &name, void (*method)(double, double, double, int, double &, double &), double u0, double v0, double ref_u, bool is_u) {
    double tol = 1e-6;
    cout << name << " method convergence test for " << (is_u ? "u(10):" : "v(10):") << endl;
    for (int n = 5; n <= 1000000; n *= 2) {
        double h = 10.0 / n;
        double uf, vf;
        method(u0, v0, h, n, uf, vf);
        double err = abs((is_u ? uf : vf) - ref_u);
        cout << "n = " << setw(6) << n << ", error = " << scientific << setprecision(10) << err;
        if (err < tol) {
            cout << ", A(h_i) = " << (is_u ? uf : vf) << endl;
            break;
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    double ref_u, ref_v;

    rk4_method(1.0, 1.0, 1e-5, int(10.0 / 1e-5), ref_u, ref_v);
    run_method("Euler", euler_method, 1.0, 1.0, ref_u, true);

    rk4_method(2.0, 1.0, 1e-5, int(10.0 / 1e-5), ref_u, ref_v);
    run_method("Euler", euler_method, 2.0, 1.0, ref_v, false);

    rk4_method(1.0, 1.0, 1e-5, int(10.0 / 1e-5), ref_u, ref_v);
    run_method("Midpoint", midpoint_method, 1.0, 1.0, ref_u, true);

    rk4_method(2.0, 1.0, 1e-5, int(10.0 / 1e-5), ref_u, ref_v);
    run_method("Midpoint", midpoint_method, 2.0, 1.0, ref_v, false);

    rk4_method(1.0, 1.0, 1e-5, int(10.0 / 1e-5), ref_u, ref_v);
    run_method("Trapezoidal", trapezoidal_method, 1.0, 1.0, ref_u, true);

    rk4_method(2.0, 1.0, 1e-5, int(10.0 / 1e-5), ref_u, ref_v);
    run_method("Trapezoidal", trapezoidal_method, 2.0, 1.0, ref_v, false);

    return 0;
}
