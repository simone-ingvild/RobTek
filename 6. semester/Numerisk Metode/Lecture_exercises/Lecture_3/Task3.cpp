#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
#include <sstream>
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

void print_error_estimate(const vector<double> &x, const VecDoub &model, const VecDoub &b) {
    cout << "\nAnd the error (sigma = |(Ax - b)/b|):\n";
    int n = x.size();
    int m = model.size();

    for (int i = 0; i < n; ++i) {
        double Axi = 0.0;
        for (int j = 0; j < m; ++j)
            Axi += model[j] * pow(x[i], j);
        double sigma = fabs((Axi - b[i]) / b[i]);
        cout << fixed << setprecision(8) << sigma << " ";
        if ((i + 1) % 5 == 0) cout << endl;
    }
    cout << endl;
}

void solve_with_svd(const vector<double> &x, const vector<double> &y, const string &label, bool is_filip = false) {
    int n = x.size();
    int m = 3; // quadratic: [1, x, x^2]

    MatDoub A(n, m);
    VecDoub b(n);
    for (int i = 0; i < n; ++i) {
        A[i][0] = 1.0;
        A[i][1] = x[i];
        A[i][2] = x[i] * x[i];
        b[i] = y[i];
    }

    // SVD object
    SVD svd(A);

    // Teacher version: custom small threshold for Filip
    if (is_filip) {
        cout << "\nSolution Filip using SVD:\n";
        VecDoub coeff_custom(m);
        svd.solve(b, coeff_custom, 1e-12);
        cout << "Own solver:\n";
        for (int i = 0; i < m; ++i)
            cout << setw(12) << coeff_custom[i] << " ";
        cout << endl;

        cout << "NR3 solver with default threshold:\n";
    } else {
        cout << "\nSolution " << label << " using SVD:\n";
        cout << "Own solver:\n";
    }

    // Default SVD solve
    VecDoub coeffs(m);
    svd.solve(b, coeffs);
    for (int i = 0; i < m; ++i)
        cout << setw(12) << coeffs[i] << " ";
    cout << "\n";

    // Print singular values
    cout << "Singular values:\n";
    for (int i = 0; i < svd.w.size(); ++i)
        cout << "w[" << i << "] = " << svd.w[i] << "\n";

    // Error vector
    print_error_estimate(x, coeffs, b);
}

int main() {
    vector<double> x_filip, y_filip, x_pontius, y_pontius;

    read_data("filip.data", x_filip, y_filip);
    read_data("pontius.data", x_pontius, y_pontius);

    solve_with_svd(x_filip, y_filip, "Filip", true);
    solve_with_svd(x_pontius, y_pontius, "Pontius");

    return 0;
}
