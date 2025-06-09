#pragma once
#include "nr3.h"

// Midpoint stepper: fixed step size, no error estimate
template <class D>
struct StepperMid {
    D &derivs;
    Doub x;
    VecDoub y, dydx, yout;

    StepperMid(D &derivs_, const VecDoub &ystart, Doub xstart)
        : derivs(derivs_), x(xstart), y(ystart), dydx(ystart.size()), yout(ystart.size()) {
        derivs(x, y, dydx);
    }

    // Take one fixed Midpoint step of size h
    void step(const Doub h) {
        Int n = y.size();
        VecDoub ym(n), dyt(n);

        for (Int i = 0; i < n; ++i)
            ym[i] = y[i] + 0.5 * h * dydx[i];

        derivs(x + 0.5 * h, ym, dyt);

        for (Int i = 0; i < n; ++i)
            y[i] += h * dyt[i];

        x += h;
        derivs(x, y, dydx);  // update for next step
    }

    const VecDoub& current_y() const { return y; }
    Doub current_x() const { return x; }
};
