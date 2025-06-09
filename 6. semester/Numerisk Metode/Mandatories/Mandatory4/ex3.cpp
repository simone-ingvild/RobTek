#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

// Define the system of ODEs
vector<double> f(double t, const vector<double>& v) {
    vector<double> dvdt(3);
    dvdt[0] = exp(-t) * cos(v[1]) + pow(v[2], 2) - v[0];
    dvdt[1] = cos(pow(v[2], 2)) - v[1];
    dvdt[2] = cos(t) * exp(-pow(v[0], 2)) - v[2];
    return dvdt;
}

// Numerical Jacobian approximation
vector<vector<double>> jacobian(double t, const vector<double>& v, double eps = 1e-6) {
    int n = v.size();
    vector<vector<double>> J(n, vector<double>(n));
    vector<double> f0 = f(t, v);
    for (int j = 0; j < n; ++j) {
        vector<double> v_pert = v;
        v_pert[j] += eps;
        vector<double> f1 = f(t, v_pert);
        for (int i = 0; i < n; ++i) {
            J[i][j] = (f1[i] - f0[i]) / eps;
        }
    }
    return J;
}

// Gaussian elimination for small linear systems
vector<double> solve_linear_system(vector<vector<double>> A, vector<double> b) {
    int n = b.size();
    for (int i = 0; i < n; ++i) {
        // Pivot
        int maxRow = i;
        for (int k = i + 1; k < n; ++k)
            if (fabs(A[k][i]) > fabs(A[maxRow][i]))
                maxRow = k;
        swap(A[i], A[maxRow]);
        swap(b[i], b[maxRow]);

        // Elimination
        for (int k = i + 1; k < n; ++k) {
            double c = A[k][i] / A[i][i];
            for (int j = i; j < n; ++j)
                A[k][j] -= c * A[i][j];
            b[k] -= c * b[i];
        }
    }

    // Back substitution
    vector<double> x(n);
    for (int i = n - 1; i >= 0; --i) {
        x[i] = b[i];
        for (int j = i + 1; j < n; ++j)
            x[i] -= A[i][j] * x[j];
        x[i] /= A[i][i];
    }
    return x;
}

// Newton-Raphson solver for implicit Trapezoidal step
vector<double> trapezoidal_step(double t, double h, const vector<double>& v) {
    vector<double> k1 = f(t, v);
    vector<double> v_next = v; // initial guess

    for (int iter = 0; iter < 10; ++iter) {
        vector<double> f_val = f(t + h, v_next);
        vector<double> g(3);
        for (int i = 0; i < 3; ++i)
            g[i] = v_next[i] - v[i] - 0.5 * h * (k1[i] + f_val[i]);

        vector<vector<double>> J = jacobian(t + h, v_next);
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                J[i][j] = (i == j ? 1.0 : 0.0) - 0.5 * h * J[i][j];

        vector<double> delta = solve_linear_system(J, g);
        for (int i = 0; i < 3; ++i)
            v_next[i] -= delta[i];

        double norm = sqrt(delta[0]*delta[0] + delta[1]*delta[1] + delta[2]*delta[2]);
        if (norm < 1e-10) break;
    }
    return v_next;
}

int main() {
    // i) Derivative at t=0
    vector<double> v0 = {1.0, 2.0, 3.0};
    vector<double> dvdt0 = f(0.0, v0);

    cout << fixed << setprecision(6);
    cout << "i) (v1'(0), v2'(0), v3'(0)) = (" << dvdt0[0] << ", " << dvdt0[1] << ", " << dvdt0[2] << ")\n\n";

    // ii) Trapezoidal method
    vector<int> N_values = {50, 100, 200, 400, 800, 1600};
    double t0 = 0.0;
    double tf = 5.0;

    cout << "ii) Trapezoidal method results:\n";
    vector<vector<double>> results;

    for (int N : N_values) {
        double h = (tf - t0) / N;
        vector<double> v = v0;

        for (int i = 0; i < N; ++i) {
            double t = t0 + i * h;
            v = trapezoidal_step(t, h, v);
        }

        cout << "   N = " << N << ": (v1(5), v2(5), v3(5)) = (" << v[0] << ", " << v[1] << ", " << v[2] << ")\n";
        results.push_back(v);
    }

    // iii) Accuracy estimate using Richardson
    vector<double> diff(3), acc(3);
    for (int i = 0; i < 3; ++i) {
        diff[i] = results[4][i] - results[5][i]; // N=800 - N=1600
        acc[i] = diff[i] / (pow(2, 2) - 1); // order = 2
    }

    cout << "\niii) Estimated accuracy for N = 800:\n";
    cout << "   Differences: (" << diff[0] << ", " << diff[1] << ", " << diff[2] << ")\n";
    cout << "   Accuracy:   (" << acc[0] << ", " << acc[1] << ", " << acc[2] << ")\n";

    return 0;
}
