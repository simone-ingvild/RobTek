#include <iostream>
#include "nr3.h"
#include "ludcmp.h"
#include "utilities.h"

using namespace std;
	
int main() {

	MatDoub A(3,3); // Initialize A matrix
	A[0][0] = 1.0;	A[0][1] = 2.0;	A[0][2] = 3.0;
	A[1][0] = 2.0;	A[1][1] = -4.0;	A[1][2] = 6.0;
	A[2][0] = 3.0;	A[2][1] = -9.0;	A[2][2] = -3.0;

	VecDoub b(3); // Initialize b vector
	b[0] = 5.0;
	b[1] = 18.0;
	b[2] = 6.0;

	// Exercise 1:
	// Solve A x = b using LU decomposition, and print the result.
	// evaluate x
	// print x


	VecDoub x(3); // Allocating x vector
	LUdcmp LU(A); // Compute LU decomposition

	LU.solve(b,x); //Evaluate x
				  // L * (U*x) = b

	auto L = LU.lu;
	L[0][1] = L[0][2] = L[1][2] = 0;
	L[0][0] = L[1][1] = L[2][2] = 1;

	auto U = LU.lu;
	U[1][0] = U[2][0] = U[2][1] = 0;

		
	U[1][0] = U[2][0] = U[2][1] = 0;
	
	util::print(A,"A");
	util::print(b,"b");
	util::print(LU.lu,"The LU version in eq. (2.3.14)");
	util::print(L,"L");
	util::print(U,"U");
	util::print(x,"x");
	util::print(L*U,"L*U");
	util::print(L*U*x, "L*U*x");
	util::print(A*x, "A*x");

	return 0;
}
