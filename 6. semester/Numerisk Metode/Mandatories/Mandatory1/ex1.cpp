#include <iostream>
#include <fstream>
#include <string>
#include "nr3.h"
#include "svd.h" // SVD class from Numerical Recipes

using namespace std;

// Read matrix from file
void readMatrix(const string &filename, MatDoub &A) {
    ifstream file(filename);
    if (!file) throw runtime_error("Cannot open file " + filename);
    int m, n;
    file >> m >> n;
    A.resize(m, n);
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            file >> A[i][j];
}

// Read vector from file
void readVector(const string &filename, VecDoub &b) {
    ifstream file(filename);
    if (!file) throw runtime_error("Cannot open file " + filename);
    int m, n;
    file >> m >> n;
    if (n != 1) throw runtime_error("Expected a vector");
    b.resize(m);
    for (int i = 0; i < m; ++i)
        file >> b[i];
}

// Compute residual r = Ax - b
VecDoub computeResidual(const MatDoub &A, const VecDoub &x, const VecDoub &b) {
    int m = A.nrows();
    int n = A.ncols();
    VecDoub r(m);
    for (int i = 0; i < m; ++i) {
        r[i] = -b[i];
        for (int j = 0; j < n; ++j)
            r[i] += A[i][j] * x[j];
    }
    return r;
}

// Apply weighting to A and b
void reweightSystem(const MatDoub &A, const VecDoub &b, const VecDoub &r,
                    MatDoub &A_weighted, VecDoub &b_weighted) {
    int m = A.nrows(), n = A.ncols();
    A_weighted.resize(m, n);
    b_weighted.resize(m);
    for (int i = 0; i < m; ++i) {
        double sigma = max(1.0, abs(r[i]));
        for (int j = 0; j < n; ++j)
            A_weighted[i][j] = A[i][j] / sigma;
        b_weighted[i] = b[i] / sigma;
    }
}

// Compute standard deviation estimate per parameter
VecDoub estimateStdDev(const VecDoub &singularValues, const VecDoub &residual, int m) {
    double norm_r = 0.0;
    for (int i = 0; i < residual.size(); ++i)
        norm_r += residual[i] * residual[i];
    norm_r = sqrt(norm_r);

    VecDoub stddev(singularValues.size());
    for (int i = 0; i < singularValues.size(); ++i)
        stddev[i] = norm_r / (sqrt(double(m)) * singularValues[i]);

    return stddev;
}

int main() {
    try {
        MatDoub A, A_weighted;
        VecDoub b, b_weighted;

        // Read inputs
        readMatrix("Ex1A.dat", A);
        readVector("Ex1b.dat", b);

        // Exercise i: SVD
        SVD svd(A);
        cout << "Exercise i: Printing diagonal singular elements W:\tVector 6D:\n";
        for (int i = 0; i < svd.w.size(); ++i)
            cout << svd.w[i] << "\t";
        cout << "\n\n";

        // Exercise ii: Solve Ax = b
        VecDoub x(A.ncols());
        svd.solve(b, x);
        cout << "Exercise ii: Printing solution estimated parameters a:\tVector 6D:\n";
        for (int i = 0; i < x.size(); ++i)
            cout << x[i] << "\t";
        cout << "\n\n";

        // Exercise iii: Standard deviation indicator of accuracy
        VecDoub r = computeResidual(A, x, b);
        VecDoub stddev = estimateStdDev(svd.w, r, A.nrows());
        cout << "Exercise iii: No true value, standard deviation indicator of accuracy of estimated parameters a:\tVector 6D:\n";
        for (int i = 0; i < stddev.size(); ++i)
            cout << stddev[i] << "\t";
        cout << "\n\n";

        // Exercise iv: Print residual
        cout << "Exercise iv: Printing residual vector r:\tVector 40D:\n";
        for (int i = 0; i < r.size(); ++i) {
            cout << r[i] << "\t";
            if ((i + 1) % 6 == 0) cout << endl;
        }
        cout << "\n";

        // Exercise v: Reweight system
        reweightSystem(A, b, r, A_weighted, b_weighted);
        cout << "Exercise v:\n";
        cout << "[A]_0,0: " << A_weighted[0][0] << "\n";
        cout << "[b]_6: " << b_weighted[6] << "\n\n";

        // Exercise vi: Solve reweighted system
        SVD svd2(A_weighted);
        VecDoub x_weighted(A_weighted.ncols());
        svd2.solve(b_weighted, x_weighted);
        cout << "Exercise vi: Printing solution estimated parameters a:\tVector 6D:\n";
        for (int i = 0; i < x_weighted.size(); ++i)
            cout << x_weighted[i] << "\t";
        cout << "\n";

    } catch (exception &e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}
