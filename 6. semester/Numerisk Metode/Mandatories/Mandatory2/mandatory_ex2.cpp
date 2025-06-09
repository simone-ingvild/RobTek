#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <fstream>
#include "Numerical-Recipes-master/Numerical-Recipes-master/src/include/nr3.h"
#include "Numerical-Recipes-master/Numerical-Recipes-master/src/include/svd.h"
#include "Numerical-Recipes-master/Numerical-Recipes-master/src/include/roots_multidim.h"
#include "Numerical-Recipes-master/Numerical-Recipes-master/src/include/ludcmp.h"
#include "Numerical-Recipes-master/Numerical-Recipes-master/src/include/cholesky.h"
#include "Numerical-Recipes-master/Numerical-Recipes-master/src/include/qrdcmp.h"

using namespace std;

// Material constants
const double m = 120.0;      // Insulator weight (kg)
const double k = 2.5;        // Length of the insulators (m)
const double w = 4.0;        // Weight of the cable/meter (resting) (kg/m)
const double alpha = 2.0e-7; // Elasticity coefficient of the cable (kg^-1)
const double g = 9.81;       // Gravitational acceleration (m/s^2)

// Variables
double d;                   // Distance between the pylong
double L0;                  // Resting length of the cable
double L;                   // Suspended length of the cable
double n;                   // "Sagging" of the cable from the insulators attachment points
double p;                   // "Sagging" of the cable from the cables attachment points
double x;                   // Half the distance between the cables attachment points
double theta;               // Angle between insulator and the horizontal plane
double phi;                 // Angle between the cable and the horizontal plane, at the cables attachments points
double a;                   // Paramter in the catenary equation for the cable
double H;                   // String tension in the cable

// Equations
// p = a * (cosh(x / a) - 1);
double calculate_p(double a, double x){
    return a * (cosh(x / a) - 1);
}

// L = 2 * a * sinh(x / a);
double calculate_L(double a, double x){
    return 2 * a * sinh(x / a);
}

// d = 2 * x + 2 * k * cos(theta);
double calculate_d(double x, double theta){
    return 2 * x + 2 * k * cos(theta);
}

// n = p + k * sin(theta);
double calculate_n(double p, double k, double theta) {
    return p + k * sin(theta);
}

// tan(phi) = sinh(x / a);
// Solve for phi (phi = arctan(sinh(x/a)))
double calculate_phi(double a, double x) {
    return atan(sinh(x / a)); 
}

// tan(theta) = (1+(v/w*L0))*tan(phi);
// Solve for theta (theta = arctan((1 + (v/w*L0))*tan(phi)))
double calculate_theta(double v, double w, double L0, double phi) {
    return atan((1 + (v / (w * L0))) * tan(phi)); 
}

// L = L0 * (1 + alpha * H);
double calculate_L_from_H(double L0, double alpha, double H) {
    return L0 * (1 + alpha * H);
}

// H = (w * L0) / (2 * sin(phi));
double calculate_H(double w, double L0, double phi) {
    return (w * L0) / (2 * sin(phi));
}


// Defines wrapper for vector function F(q)
// Otherwise it's not compatible with the newt in the roots_multidim.h
std::vector<double> F(const std::vector<double>& q) {
    L0 = q[0]; L = q[1]; p = q[2]; x = q[3]; theta = q[4]; phi = q[5]; a = q[6]; H = q[7];
    return {
        p - calculate_p(a, x),
        L - calculate_L(a, x),
        d - calculate_d(x, theta),
        n - calculate_n(p, k, theta),
        phi - calculate_phi(a, x),
        theta - calculate_theta(m, w, L0, phi),
        L - calculate_L_from_H(L0, alpha, H),
        H - calculate_H(w, L0, phi)
    };
}

int main() {
    // Fixed distance between pylons
    d = 30.0;

    // Values of n to iterate over
    vector<double> n_values = {5.0, 2.0, 1.0, 0.5, 0.2, 0.1};

    // Iterate over each value of n
    for (double n_val : n_values) {
        n = n_val;

        // Initial guess for q = {L0, L, p, x, theta, phi, a, H}
        vector<double> q = {50.0, 60.0, 10.0, 15.0, 0.1, 0.1, 40.0, 100.0};

        // Solve using Newton's method
        bool check;
        try {
            newt(q, check, F);
            if (check) {
                cout << "Convergence failed for n = " << n << endl;
            } else {
                cout << fixed << setprecision(6);
                cout << "For n = " << n << ": L0 = " << q[0] << ", H = " << q[7] << endl;
            }
        } catch (const char* msg) {
            cerr << "Error: " << msg << " for n = " << n << endl;
        }
    }

    return 0;
}









