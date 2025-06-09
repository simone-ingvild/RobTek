#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <vector>
#include <limits>
#include "nr3.h"
#include "steppermid.h"

using namespace std;

// Parameters
const double a1 = 1.0, b1 = 1.0;
const double a2 = 0.25, b2 = 0.25;
const double g1 = 2.0, g2 = 1.0;

// Forcing functions
double f1(double x) { return x; }
double f2(double x) { return 3 * x * (1 - x * x); }

// RHS of the ODE system
struct RHS {
    void operator()(const double t, VecDoub_I &z, VecDoub_O &dz) {
        dz[0] = z[1];  // y1'
        dz[1] = a1 * (b1 * (g1 - z[0]) - z[1]) + f1(z[4]); // y1''
        dz[2] = z[3];  // y2'
        dz[3] = a2 * (b2 * (g2 - z[2]) - z[3]) + f2(z[4]); // y2''
        dz[4] = -z[4]; // x'
    }
};

// Save trajectory to CSV
void save_trajectory_csv(const vector<VecDoub> &traj, const vector<double> &ts) {
    ofstream file("trajectory.csv");
    file << "t,y1,y2\n";
    for (size_t i = 0; i < traj.size(); ++i)
        file << ts[i] << "," << traj[i][0] << "," << traj[i][2] << "\n";
    file.close();
    cout << "Trajectory saved to trajectory.csv\n";
}

// ASCII plot
void plot_ascii_trajectory(const vector<VecDoub> &traj) {
    const int width = 60, height = 20;
    vector<string> grid(height, string(width, ' '));

    double y1min = numeric_limits<double>::max();
    double y1max = -numeric_limits<double>::max();
    double y2min = numeric_limits<double>::max();
    double y2max = -numeric_limits<double>::max();

    for (const auto &z : traj) {
        y1min = min(y1min, z[0]);
        y1max = max(y1max, z[0]);
        y2min = min(y2min, z[2]);
        y2max = max(y2max, z[2]);
    }

    for (const auto &z : traj) {
        int x = static_cast<int>((z[0] - y1min) / (y1max - y1min) * (width - 1));
        int y = static_cast<int>((z[2] - y2min) / (y2max - y2min) * (height - 1));
        y = height - 1 - y;
        if (x >= 0 && x < width && y >= 0 && y < height)
            grid[y][x] = '*';
    }

    cout << "\nASCII Plot of Trajectory (y1 vs y2):\n";
    for (const auto &line : grid)
        cout << line << "\n";
}

void part_i() {
    cout << "Part i) Reformulated system:\n";
    cout << "Let z1 = y1, z2 = y1', z3 = y2, z4 = y2', z5 = x\n";
    cout << "Then the system becomes:\n";
    cout << " z1' = z2                                 with z1(0) = 0\n";
    cout << " z2' = a1[b1(g1 - z1) - z2] + f1(z5)       with z2(0) = 0\n";
    cout << " z3' = z4                                 with z3(0) = 0\n";
    cout << " z4' = a2[b2(g2 - z3) - z4] + f2(z5)       with z4(0) = 0\n";
    cout << " z5' = -z5                                with z5(0) = 1\n";
}

void part_ii(double h = 0.001) {
    cout << "\nPart ii) Midpoint integration with h = " << h << ":\n";

    VecDoub z(5);
    z[0] = z[1] = z[2] = z[3] = 0.0;
    z[4] = 1.0;

    RHS rhs;
    StepperMid<RHS> stepper(rhs, z, 0.0);

    double t1 = 20.0;
    int steps = static_cast<int>(t1 / h);

    double max_y1 = -1e9;
    double max_t = 0.0;

    vector<VecDoub> trajectory;
    vector<double> times;

    for (int i = 0; i < steps; ++i) {
        const VecDoub &y = stepper.current_y();
        double t = stepper.current_x();

        if (y[0] > max_y1) {
            max_y1 = y[0];
            max_t = t;
        }

        trajectory.push_back(y);
        times.push_back(t);
        stepper.step(h);
    }

    cout << "Trajectory ends at: y1 = " << stepper.current_y()[0]
         << ", y2 = " << stepper.current_y()[2] << "\n";
    cout << "Max y1(t) = " << max_y1 << " at t = " << max_t << "\n";

    save_trajectory_csv(trajectory, times);
    plot_ascii_trajectory(trajectory);
}

void part_iii() {
    cout << "\nPart iii) Convergence test for y2(5):\n";
    const double t_target = 5.0;
    const double true_tol = 1e-4;
    double last = 0.0;

    for (int N = 5; N <= 100000; N *= 2) {
        double h = 5.0 / N;
        VecDoub z(5);
        z[0] = z[1] = z[2] = z[3] = 0.0;
        z[4] = 1.0;

        RHS rhs;
        StepperMid<RHS> stepper(rhs, z, 0.0);

        for (int i = 0; i < N; ++i)
            stepper.step(h);

        double y2 = stepper.current_y()[2];

        if (N > 5) {
            double err = abs(y2 - last);
            cout << "N = " << setw(6) << N
                 << "  y2(5) = " << setw(10) << y2
                 << "  diff = " << err << "\n";
            if (err < true_tol) {
                cout << "Converged to within 1e-4 using N = " << N << " subdivisions.\n";
                break;
            }
        }
        last = y2;
    }
}

int main() {
    cout << fixed << setprecision(6);
    part_i();
    part_ii();
    part_iii();
    return 0;
}
