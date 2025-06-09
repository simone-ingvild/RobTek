#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <algorithm>  // Needed for max_std loop
#include "nr3.h"
#include "svd.h"

using namespace std;

void read_data(const string &filename, vector<double> &x, vector<double> &y) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        exit(1);
    }
    string line;
    int count = 0;
    while (getline(file, line)) {
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
            A[i][j] = A[i][j - 1] * x[i];
        }
    }
}

void svd_threshold_analysis(const vector<double> &x, const vector<double> &y, const string &label, int degree) {
    int n = x.size();
    MatDoub A;
    build_design_matrix(x, A, degree);

    VecDoub b(n);
    for (int i = 0; i < n; ++i) b[i] = y[i];

    SVD svd(A);

    cout << "\n===========================================\n";
    cout << "SVD Threshold Analysis for: " << label << " (degree " << degree << ")\n";
    cout << "Singular values:\n";
    for (int i = 0; i < svd.w.size(); ++i)
        cout << "  w[" << i << "] = " << svd.w[i] << "\n";

    vector<Doub> thresholds = {svd.eps, 1e-12, 1e-10, 1e-8, 1e-6};

    for (Doub thresh : thresholds) {
        VecDoub coeffs(degree + 1);
        svd.solve(b, coeffs, thresh);

        // Compute Ax and error
        double norm_diff = 0.0, norm_b = 0.0;
        for (int i = 0; i < n; ++i) {
            double Ax = 0.0;
            for (int j = 0; j <= degree; ++j)
                Ax += coeffs[j] * pow(x[i], j);
            norm_diff += SQR(Ax - b[i]);
            norm_b += SQR(b[i]);
        }
        double rel_error = sqrt(norm_diff) / sqrt(norm_b);
        double sigma2 = norm_diff / (n - (degree + 1));

        // Estimate covariance matrix
        MatDoub cov(degree + 1, degree + 1, 0.0);
        for (int i = 0; i <= degree; ++i) {
            if (svd.w[i] > thresh) {
                for (int j = 0; j <= degree; ++j) {
                    for (int k = 0; k <= degree; ++k) {
                        cov[j][k] += (svd.v[j][i] * svd.v[k][i]) / (svd.w[i] * svd.w[i]);
                    }
                }
            }
        }

        for (int i = 0; i <= degree; ++i)
            for (int j = 0; j <= degree; ++j)
                cov[i][j] *= sigma2;

        // Compute standard deviations
        VecDoub std_params(degree + 1);
        for (int i = 0; i <= degree; ++i)
            std_params[i] = sqrt(cov[i][i]);

        // Output section
        cout << "\n--- Threshold: " << thresh << " ---\n";
        cout << "Coefficients (Vector " << (degree + 1) << "D):\n";
        for (int i = 0; i <= degree; ++i)
            cout << setw(12) << coeffs[i] << " ";
        cout << "\nRelative Error (||Ax - b|| / ||b||): " << rel_error << "\n";

        cout << "Standard deviation of estimated model parameters (Vector " << (degree + 1) << "D):\n";
        for (int i = 0; i <= degree; ++i)
            cout << setw(12) << std_params[i] << " ";
        cout << "\n";

        // Manual max finder (no STL iterators in NR3)
        double max_std = 0.0;
        for (int i = 0; i <= degree; ++i)
            if (std_params[i] > max_std)
                max_std = std_params[i];

        if (max_std > 1e3)
            cout << "This STD of model parameters is too big, try with model updating.\n";
        else
            cout << "This STD of model parameters is closer to stated values.\n";
    }

    cout << "===========================================\n";
}

int main() {
    vector<double> x_filip, y_filip, x_pontius, y_pontius;

    read_data("filip.data", x_filip, y_filip);
    read_data("pontius.data", x_pontius, y_pontius);

    svd_threshold_analysis(x_filip, y_filip, "Filip", 10);
    svd_threshold_analysis(x_pontius, y_pontius, "Pontius", 2);

    return 0;
}
