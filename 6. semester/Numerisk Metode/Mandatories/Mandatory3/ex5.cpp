#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <limits>

// Function to be integrated
double f(double x) {
    return (cos(pow(x, 3)) * exp(-x)) / sqrt(x);
}

// Extended Midpoint Rule
double extendedMidpointRule(double a, double b, int n, int& f_eval_count) {
    double h = (b - a) / n;
    double sum = 0.0;
    f_eval_count = 0;
    for (int i = 0; i < n; ++i) {
        double midpoint = a + (i + 0.5) * h;
        sum += f(midpoint);
        f_eval_count++;
    }
    return h * sum;
}

// DRule (simplified Romberg Integration)
double dRule(double a, double b, double tolerance, int& f_eval_count) {
    std::vector<double> R(1);
    int n = 1;
    f_eval_count = 0;

    R[0] = extendedMidpointRule(a, b, n, f_eval_count);

    for (int k = 1; ; ++k) {
        n *= 2;
        double R_prev = R[0];
        int fevals_new = 0;
        double R_new = extendedMidpointRule(a, b, n, fevals_new);
        f_eval_count += fevals_new;

        R[0] = R_new + (R_new - R_prev) / (pow(4, k) - 1);

        if (std::abs(R[0] - R_prev) < tolerance) {
            return R[0];
        }
        if (k > 20) {
            std::cerr << "DRule did not converge within the iteration limit." << std::endl;
            return R[0];
        }
    }
}

int main() {
    // Part i) Analytical expression for N = 2 (one midpoint)
    double a_analytical, b_analytical;
    std::cout << "Enter the lower limit (a) for the analytical expression: ";
    std::cin >> a_analytical;
    std::cout << "Enter the upper limit (b) for the analytical expression: ";
    std::cin >> b_analytical;

    int n_analytical = 2;
    double h_analytical = (b_analytical - a_analytical) / n_analytical;
    double midpoint_analytical = a_analytical + 0.5 * h_analytical;

    std::cout << "\nPart i) Analytical Expression for N = 2 (one midpoint):\n";
    std::cout << "Approximation ≈ h * f(midpoint) = " << h_analytical << " * f(" << midpoint_analytical << ")\n";
    std::cout << "≈ " << h_analytical * f(midpoint_analytical) << "\n";

    // Part ii) Extended Midpoint Rule with Richardson extrapolation
    double a = 0.0;
    double b = 4.0;
    double tolerance = 1e-3;

    std::cout << "\nPart ii) Extended Midpoint Rule with Richardson Extrapolation:\n";
    std::cout << std::setw(10) << "N" << std::setw(15) << "A(h)" << std::setw(15)
              << "A_extrap" << std::setw(15) << "Error" << std::setw(15) << "f-count\n";
    std::cout << std::setfill('-') << std::setw(70) << "" << std::setfill(' ') << "\n";

    int total_f_count = 0;
    int n_prev = 1;
    int f_count_prev;
    double A_prev = extendedMidpointRule(a, b, n_prev, f_count_prev);
    total_f_count += f_count_prev;

    for (int i = 1, n = 3; ; ++i, n = 2 * n - 1) {
        int f_count_curr;
        double A_curr = extendedMidpointRule(a, b, n, f_count_curr);
        total_f_count += f_count_curr;

        double A_extrap = A_curr + (A_curr - A_prev) / (std::pow(2.0, 1) - 1); // p = 1 for midpoint rule
        double error = std::abs(A_extrap - A_curr);

        std::cout << std::setw(10) << n << std::setw(15) << A_curr
                  << std::setw(15) << A_extrap << std::setw(15) << error
                  << std::setw(15) << total_f_count << "\n";

        if (error < tolerance) {
            std::cout << "Converged with desired accuracy " << tolerance << " at N = " << n << "\n";
            break;
        }

        A_prev = A_curr;
        n_prev = n;
    }

    // Part iii) DRule approximation
    int f_count_drule = 0;
    double drule_result = dRule(a, b, tolerance, f_count_drule);
    std::cout << "\nPart iii) DRule Result:\n";
    std::cout << "Approximation ≈ " << std::setprecision(8) << drule_result << "\n";
    std::cout << "Function evaluations: " << f_count_drule << "\n";

    return 0;
}
