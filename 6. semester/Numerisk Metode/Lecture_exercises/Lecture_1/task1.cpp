#include <iostream>
#include <iomanip>
#include "nr3.h"
#include "ludcmp.h"

using namespace std;

void print_matrix(const MatDoub &M, const string &name) {
    cout << name << " Matrix " << M.nrows() << "x" << M.ncols() << ":\n";
    for (int i = 0; i < M.nrows(); ++i) {
        for (int j = 0; j < M.ncols(); ++j) {
            cout << setw(10) << M[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void print_vector(const VecDoub &v, const string &name) {
    cout << name << " Vector " << v.size() << "D:\n";
    for (int i = 0; i < v.size(); ++i)
        cout << setw(10) << v[i] << " ";
    cout << "\n" << endl;
}

int main() {
    // Define matrix A
    MatDoub A(3, 3);
    A[0][0] = 1;  A[0][1] = 2;  A[0][2] = 3;
    A[1][0] = 2;  A[1][1] = -4; A[1][2] = 6;
    A[2][0] = 3;  A[2][1] = -9; A[2][2] = -3;

    // Define vector b
    VecDoub b(3);
    b[0] = 5;
    b[1] = 18;
    b[2] = 6;

    // Show A and b
    print_matrix(A, "A");
    print_vector(b, "b");

    // LU decomposition
    LUdcmp lu(A);

    // Output LU matrix (combined)
    print_matrix(lu.lu, "The LU version in Eq. (2.3.14)");

    // Extract L and U
    MatDoub L(3, 3, 0.0), U(3, 3, 0.0);
    lu.decompose(L, U);
    print_matrix(L, "L");
    print_matrix(U, "U");

    // Solve for x
    VecDoub x(3);
    lu.solve(b, x);
    print_vector(x, "x");

    // Check L*U
    MatDoub LU(3, 3, 0.0);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            for (int k = 0; k < 3; ++k)
                LU[i][j] += L[i][k] * U[k][j];
    print_matrix(LU, "L*U");

    // Compute L*U*x
    VecDoub Lux(3, 0.0);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            Lux[i] += LU[i][j] * x[j];
    print_vector(Lux, "L*U*x");

    // Check A*x
    VecDoub Ax(3, 0.0);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            Ax[i] += A[i][j] * x[j];
    print_vector(Ax, "A*x");

    // Print pivot indices
    cout << "Pivoting bookkeeping from partial pivoting:\n";
    for (int i = 0; i < lu.indx.size(); ++i)
        cout << setw(5) << lu.indx[i];
    cout << "\n";

    return 0;
}
