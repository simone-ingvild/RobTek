#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>

#include "cholesky.h"
#include "ludcmp.h"
#include "qrdcmp.h"
#include "roots_multidim.h"
#include "svd.h"
#include "nr3.h"

using namespace std;

// Material constants
const double v = 120.0;
const double k = 2.5;
const double w = 4.0;
const double alpha = 2.0e-7;
const double d = 30.0;

// Function declarations
double calculate_p(double a, double x);
double calculate_L(double a, double x);
double calculate_d(double x, double theta);
double calculate_n(double p, double k, double theta);
double calculate_phi(double a, double x);
double calculate_theta(double L0, double phi);
double calculate_L_from_H(double L0, double H);
double calculate_H(double L0, double phi);

// System of Equations struct, if they're not wrapped newt can't use them
struct SystemOfEquations {
    double n_value;

    SystemOfEquations(double n) : n_value(n) {}

    // Function to calculate the Jacobian matrix
    NRvector<double> operator()(const NRvector<double>& q) const {
        NRvector<double> results(8);

        // Unpack the input vector
        double L0 = q[0];
        double L = q[1];
        double p = q[2];
        double x = q[3];
        double theta = q[4];
        double phi = q[5];
        double a = q[6];
        double H = q[7];

        // Calculate the equations based on the input variables (see bottom of this file)
        results[0] = p - calculate_p(a, x);
        results[1] = L - calculate_L(a, x);
        results[2] = d - calculate_d(x, theta);
        results[3] = n_value - calculate_n(p, k, theta);
        results[4] = phi - calculate_phi(a, x);
        results[5] = theta - calculate_theta(L0, phi);
        results[6] = L - calculate_L_from_H(L0, H);
        results[7] = H - calculate_H(L0, phi);

        return results;
    }
};

int main() {
    // Set up the output format
    cout << fixed << setprecision(6);

    // The requested n values
    vector<double> n_values = {5.0, 2.0, 1.0, 0.5, 0.2, 0.1};

    // Open the log file for writing
    ofstream log_file("results_alternative.log");
    if (!log_file.is_open()) {
        cerr << "Error: Could not open log file!" << endl;
        return 1;
    }

    log_file << "Results for different n values:\n\n";
    log_file << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    log_file << setw(12) << "n" << setw(15) << "L0" << setw(15) << "L" << setw(15) << "p"
             << setw(15) << "x" << setw(15) << "theta" << setw(15) << "phi"
             << setw(15) << "a" << setw(15) << "H" << endl;
    log_file << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

    // Loop over different n values
    for (double n_val : n_values) {
        // Initial guess for the variables, gotta be honest here, i tried a lot of different
        // combinations and this is the only one that worked for all n values
        NRvector<double> q(8);
        q[0] = 60.0;  
        q[1] = 60.0;  
        q[2] = 5.0;   
        q[3] = 28;      
        q[4] = 0.5; 
        q[5] = 0.1; 
        q[6] = 40.0;  
        q[7] = 100.0;    

        // Set the initial guess for the variables
        SystemOfEquations system(n_val);

        // Set the maximum number of iterations
        NRfdjac<SystemOfEquations> fdjac(system);
        bool check;

        try {
            newt(q, check, system);
        
            // Calculate the norm of the results vector
            NRvector<double> results = system(q);
            double norm = 0.0;
            for (int i = 0; i < results.size(); ++i) {
                norm += results[i] * results[i];
            }
            norm = sqrt(norm);
        
            // Check if the solution meets the stopping condition given
            if (!check && norm < 1e-8) {
                log_file << setw(12) << n_val << setw(15) << q[0] << setw(15) << q[1]
                         << setw(15) << q[2] << setw(15) << q[3] << setw(15) << q[4]
                         << setw(15) << q[5] << setw(15) << q[6] << setw(15) << q[7] << endl;
            } else {
                log_file << setw(12) << n_val << " - Convergence Failed.\n";
            }
        } catch (int errCode) {
            if (errCode == 1) {
                cerr << "Error: MAXITS exceeded for n = " << n_val << endl;
                log_file << setw(10) << n_val << " - Convergence Failed (MAXITS).\n";
            } else {
                cerr << "Error: Unknown error for n = " << n_val << endl;
                log_file << setw(10) << n_val << " - Convergence Failed (Unknown).\n";
            }
        } catch (const char* msg) {
            cerr << "Error: " << msg << " for n = " << n_val << endl;
            log_file << setw(10) << n_val << " - Convergence Failed (Exception).\n";
        }
    }

    log_file << "\n-------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    log_file.close();
    return 0;
}

// Function definitions
double calculate_p(double a, double x) {
    return a * (cosh(x / a) - 1);
}

double calculate_L(double a, double x) {
    return 2 * a * sinh(x / a);
}

double calculate_d(double x, double theta) {
    return 2 * x + 2 * k * cos(theta);
}

double calculate_n(double p, double k, double theta) {
    return p + k * sin(theta);
}

double calculate_phi(double a, double x) {
    return atan(sinh(x / a));
}

double calculate_theta(double L0, double phi) {
    return atan((1 + (v / (w * L0))) * tan(phi));
}

double calculate_L_from_H(double L0, double H) {
    return L0 * (1 + alpha * H);
}

double calculate_H(double L0, double phi) {
    return (w * L0) / (2 * sin(phi));
}