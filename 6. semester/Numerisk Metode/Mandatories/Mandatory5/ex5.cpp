#include <iostream>
#include <iomanip>
#include <cmath>
#include "nr3.h"
#include "quadrature.h"
#include "derule.h"

using namespace std;

// Parameters
const Doub a = 0.1;
const Doub b = 2.0;
const Doub tol = 1e-3;

// Integrand
struct Integrand {
    Int evals = 0;

    Doub operator()(Doub x) {
        evals++;
        return cos(pow(x, 3)) * exp(-x) / sqrt(x);
    }

    Doub operator()(Doub x, Doub) { return (*this)(x); } // For DErule
};

int main() {
    cout << fixed << setprecision(10);

    cout << "===========================\n";
    cout << "Part i) Midpoint Method with N = 2\n";
    cout << "===========================\n";
    cout << "Method: Use midpoint rule on two intervals.\n";

    Doub h = (b - a) / 2.0;
    Doub x1 = a + h / 2.0;
    Doub x2 = a + 3 * h / 2.0;
    Integrand f1;
    Doub approx_i = h * (f1(x1) + f1(x2));
    cout << "Midpoints: x1 = " << x1 << ", x2 = " << x2 << endl;
    cout << "Approximate value: " << approx_i << "\n\n";

    cout << "===========================\n";
    cout << "Part ii) Convergence of Midpoint Rule\n";
    cout << "===========================\n";
    cout << "We increase N in the sequence N = 3, 5, 9, ...\n";
    cout << "We stop when the error between successive approximations is < 1e-3.\n";
    cout << "Error is computed as abs(I_N - I_prev).\n\n";
    cout << "N\tApproximation\tError\t\tEvals\n";

    Doub prev = approx_i;
    for (Int n = 3; n <= 129; n = 2 * n - 1) {
        Integrand f;
        Doub h = (b - a) / n;
        Doub sum = 0.0;
        for (Int i = 0; i < n; ++i) {
            Doub xmid = a + (i + 0.5) * h;
            sum += f(xmid);
        }
        Doub approx = h * sum;
        Doub error = abs(approx - prev);
        cout << n << "\t" << approx << "\t" << error << "\t" << f.evals << endl;
        if (error < tol) {
            cout << "\nConverged to within " << tol << " using N = " << n << ".\n";
            cout << "Final approximation: " << approx << "\n";
            cout << "Total function evaluations: " << f.evals << "\n\n";
            break;
        }
        prev = approx;
    }

    cout << "===========================\n";
    cout << "Part iii) Double Exponential Rule\n";
    cout << "===========================\n";
    cout << "We now use DErule which applies a double exponential transformation.\n";
    cout << "This method is accurate for integrals with endpoint singularities.\n\n";

    Integrand f3;
    DErule<Integrand> de(f3, a, b);
    Doub result = 0.0;
    for (int i = 0; i < 20; ++i) result = de.next();
    cout << "DE approximation: " << result << "\n";
    cout << "Function evaluations: " << f3.evals << "\n";

    return 0;
}
