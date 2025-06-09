#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include "nr3.h"
#include "svd.h"

using namespace std;

// Reads a matrix from file with format:
// <rows>
// <cols>
// <data> (rows × cols numbers)
void readMatrix(const string &filename, MatDoub &mat) {
    ifstream in(filename);
    if (!in) throw runtime_error("Could not open file: " + filename);

    int rows_n, cols_n;
    in >> rows_n >> cols_n;

    mat.resize(rows_n, cols_n);
    for (int i = 0; i < rows_n; ++i)
        for (int j = 0; j < cols_n; ++j)
            in >> mat[i][j];
}

// Reads a column vector from file with format:
// <rows>
// <cols> (must be 1)
// <data> (rows × 1 numbers)
void readVector(const string &filename, VecDoub &vec) {
    ifstream in(filename);
    if (!in) throw runtime_error("Could not open file: " + filename);

    int rows_n, cols_n;
    in >> rows_n >> cols_n;

    if (cols_n != 1)
        throw runtime_error("Expected column vector with 1 column.");

    vec.resize(rows_n);
    for (int i = 0; i < rows_n; ++i)
        in >> vec[i];
}

int main() {
    try {
        // Read A and b
        MatDoub A;
        VecDoub b;
        readMatrix("Ex1A.dat", A);
        readVector("Ex1b.dat", b);

        cout << "Loaded matrix A: " << A.nrows() << " x " << A.ncols() << endl;
        cout << "Loaded vector b: size = " << b.size() << endl;

        if (b.size() != A.nrows())
            throw runtime_error("Vector b size does not match number of rows in A.");

        // Solve Ax = b using SVD
        VecDoub x(A.ncols());
        SVD svd(A);
        svd.solve(b, x);

        cout << fixed << setprecision(6);
        cout << "\nSolution vector x (solving Ax = b using SVD):\n";
        for (int i = 0; i < x.size(); ++i)
            cout << "x[" << i << "] = " << x[i] << endl;

        // Compute residual norm ||Ax - b||
        VecDoub Ax(b.size());
        for (int i = 0; i < A.nrows(); ++i) {
            Ax[i] = 0.0;
            for (int j = 0; j < A.ncols(); ++j)
                Ax[i] += A[i][j] * x[j];
        }

        Doub residual = 0.0;
        for (int i = 0; i < b.size(); ++i)
            residual += pow(Ax[i] - b[i], 2);

        residual = sqrt(residual);
        cout << "\nResidual ||Ax - b|| = " << residual << endl;


        // Part iii - explanation
        cout << "\nPart iii) Explanation:\n";
        cout << "For symmetric matrices A = A^T, the SVD decomposition A = U W V^T results in U = V.\n";
        cout << "This is because symmetry ensures identical left and right singular vectors.\n";

    } catch (exception &e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}
