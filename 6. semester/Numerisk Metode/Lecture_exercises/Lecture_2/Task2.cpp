#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include "nr3.h"
#include "ludcmp.h"
#include "cholesky.h"

using namespace std;

void read_data(const string &filename, vector<double> &x, vector<double> &y) {
    ifstream infile(filename);
    if (!infile) {
        cerr << "Error opening file: " << filename << endl;
        exit(1);
    }

    string line;
    int count = 0;
    while (getline(infile, line)) {
        if (++count <= 60 || line.empty()) continue;

        double xi, yi;
        istringstream iss(line);
        if (iss >> xi >> yi) {
            x.push_back(xi);
            y.push_back(yi);
        }
    }
}

void build_design_matrix(const vector<double> &x, MatDoub &A, int degree) {
    int n = x.size();
    A.resize(n, degree + 1);
    for (int i = 0; i < n; ++i) {
        A[i][0] = 1.0;
        for (int j = 1; j <= degree; ++j) {
            A[i][j] = A[i][j - 1] * x[i]; // x^j
        }
    }
}

void compute_normal_equations(const MatDoub &A, const VecDoub &b, MatDoub &AtA, VecDoub &Atb) {
    int n = A.nrows(), m = A.ncols();
    AtA.assign(m, m, 0.0);
    Atb.assign(m, 0.0);

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < m; ++j)
            for (int k = 0; k < n; ++k)
                AtA[i][j] += A[k][i] * A[k][j];

    for (int i = 0; i < m; ++i)
        for (int k = 0; k < n; ++k)
            Atb[i] += A[k][i] * b[k];
}

void print_vector(const VecDoub &v) {
    for (int i = 0; i < v.size(); ++i)
        cout << setw(12) << v[i] << " ";
    cout << endl;
}

void print_matrix(const MatDoub &M) {
    for (int i = 0; i < M.nrows(); ++i) {
        for (int j = 0; j < M.ncols(); ++j)
            cout << setw(14) << M[i][j] << " ";
        cout << endl;
    }
}

void fit_model(const string &label, const vector<double> &x, const vector<double> &y, int degree) {
    int n = x.size();
    int m = degree + 1;

    MatDoub A;
    build_design_matrix(x, A, degree);

    VecDoub b(n);
    for (int i = 0; i < n; ++i) b[i] = y[i];

    MatDoub AtA;
    VecDoub Atb;
    compute_normal_equations(A, b, AtA, Atb);

    cout << "\n=== " << label << " ===\n";

    // LU Solution
    try {
        LUdcmp lu(AtA);
        VecDoub x_lu(m);
        lu.solve(Atb, x_lu);

        cout << "Parameters using LU:\nVector " << m << "D:\n";
        print_vector(x_lu);

        // Compute residuals and variance matrix
        VecDoub y_pred(n);
        for (int i = 0; i < n; ++i) {
            y_pred[i] = 0.0;
            for (int j = 0; j < m; ++j)
                y_pred[i] += A[i][j] * x_lu[j];
        }

        double rss = 0.0;
        for (int i = 0; i < n; ++i)
            rss += SQR(y[i] - y_pred[i]);

        double variance = rss / (n - m);

        MatDoub cov_lu = AtA;
        lu.inverse(cov_lu);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < m; ++j)
                cov_lu[i][j] *= variance;

        cout << "Variance of estimated parameters:\n";
        print_matrix(cov_lu);
    } catch (...) {
        cout << "ERROR: LU failed\n";
    }

    // Cholesky Solution
    try {
        Cholesky ch(AtA);
        VecDoub x_ch(m);
        ch.solve(Atb, x_ch);

        cout << "\nParameters using Cholesky:\nVector " << m << "D:\n";
        print_vector(x_ch);
    } catch (...) {
        cout << "\nERROR: Cholesky failed\n";
    }

    cout << "------------------------------------------------------\n";
}

int main() {
    vector<double> x_filip, y_filip, x_pontius, y_pontius;

    read_data("filip.data", x_filip, y_filip);
    read_data("pontius.data", x_pontius, y_pontius);

    fit_model("Pontius (degree 2)", x_pontius, y_pontius, 2);
    fit_model("Filip (degree 2)", x_filip, y_filip, 2);
    fit_model("Filip (degree 10)", x_filip, y_filip, 10);

    return 0;
}
