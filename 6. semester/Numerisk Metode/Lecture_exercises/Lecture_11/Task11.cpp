#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

// Function definitions for the system
double f1(double x, double u, double v) {
    return std::cos(-1 + x + u + 3 * v);
}

double f2(double x, double u, double v) {
    return -u * u + 2 * std::sin(v);
}

// Perform one Midpoint method step
void midpoint_step(double x, double h, double& u, double& v) {
    double k1u = f1(x, u, v);
    double k1v = f2(x, u, v);

    double midu = u + h * k1u / 2.0;
    double midv = v + h * k1v / 2.0;

    double k2u = f1(x + h / 2.0, midu, midv);
    double k2v = f2(x + h / 2.0, midu, midv);

    u += h * k2u;
    v += h * k2v;
}

// Solve system from x=0 to x=1 with given step size
std::pair<double, double> solve_midpoint(double h) {
    double x = 0.0, u = 1.0, v = 0.0;
    int steps = static_cast<int>(1.0 / h);
    for (int i = 0; i < steps; ++i) {
        midpoint_step(x, h, u, v);
        x += h;
    }
    return {u, v};
}

// Richardson extrapolation estimate
double richardson_extrapolate(double uh, double uh2) {
    return (4.0 * uh2 - uh) / 3.0;
}

// Compute observed order of accuracy
double compute_order(double E1, double E2) {
    return std::log2(std::abs(E1 / E2));
}

void generate_table(const std::vector<int>& n_list,
                    const std::vector<double>& A_vals,
                    const std::vector<double>& errors,
                    const std::string& label) {
    std::cout << "\nShowing results for " << label << " at x = 1\n";
    std::cout << "n\tA(h_i)\t\tA(h_{i-1}) - A(h_i)\talp^k\t\terror\t\torder-estimate\n";

    for (size_t i = 0; i < A_vals.size(); ++i) {
        std::cout << n_list[i] << "\t";
        std::cout << std::fixed << std::setprecision(8) << A_vals[i] << "\t";

        if (i == 0) {
            std::cout << "-\t\t\t-\t\t-\t\t-\n";
        } else {
            double diff = A_vals[i - 1] - A_vals[i];
            double error = std::abs(errors[i]);
            double alpha_k = std::pow(2.0, 2.0); // midpoint is order 2
            double order = compute_order(errors[i - 1], errors[i]);

            std::cout << diff << "\t" << alpha_k << "\t\t" << error << "\t" << order << "\n";
        }
    }
}

int main() {
    std::vector<int> n_list;
    std::vector<double> u_vals, v_vals;
    std::vector<double> u_errors = {0.0}, v_errors = {0.0};

    std::vector<double> h_list = {1.0 / 1, 1.0 / 2, 1.0 / 4, 1.0 / 8, 1.0 / 16,
                                  1.0 / 32, 1.0 / 64, 1.0 / 128, 1.0 / 256,
                                  1.0 / 512, 1.0 / 1024, 1.0 / 2048, 1.0 / 4096};

    for (size_t i = 0; i < h_list.size(); ++i) {
        double h = h_list[i];
        auto [u, v] = solve_midpoint(h);
        n_list.push_back(static_cast<int>(1.0 / h));
        u_vals.push_back(u);
        v_vals.push_back(v);

        if (i > 0) {
            // Richardson extrapolated value and error
            double extrap_u = richardson_extrapolate(u_vals[i - 1], u_vals[i]);
            double extrap_v = richardson_extrapolate(v_vals[i - 1], v_vals[i]);
            u_errors.push_back(extrap_u - u_vals[i]);
            v_errors.push_back(extrap_v - v_vals[i]);
        }
    }

    generate_table(n_list, u_vals, u_errors, "u(x)");
    generate_table(n_list, v_vals, v_errors, "v(x)");

    return 0;
}

/*
Jacobian matrix for Trapezoidal method:

∂f1/∂u = -sin(-1 + x + u + 3v)
∂f1/∂v = -3*sin(-1 + x + u + 3v)
∂f2/∂u = -2u
∂f2/∂v = 2*cos(v)

Jacobian J =
| ∂f1/∂u   ∂f1/∂v |
| ∂f2/∂u   ∂f2/∂v |
*/
