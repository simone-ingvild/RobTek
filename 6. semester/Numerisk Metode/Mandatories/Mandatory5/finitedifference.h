#pragma once
#include "nr3.h"
#include "ludcmp.h"
void usrfun(VecDoub_I &x, VecDoub_O &fvec, MatDoub_O &fjac);
#include "mnewt.h"

// Context for solving the BVP
struct FDContext {
    Doub h;
    VecDoub u;
    Doub vA, vB;
};

// Global context for Newton solver
static FDContext ctx;

// Compute only residual vector F(V)
void compute_residual(const VecDoub &x, VecDoub &fvec) {
    Int N = x.size();
    fvec.resize(N);

    const VecDoub &u = ctx.u;
    Doub h = ctx.h;

    // Reconstruct full vector V including boundary values
    VecDoub V(N + 2);
    V[0] = ctx.vA;
    V[N + 1] = ctx.vB;
    for (int i = 1; i <= N; ++i)
        V[i] = x[i - 1];

    for (int i = 1; i <= N; ++i) {
        Doub ui = u[i];
        Doub dV = (V[i + 1] - V[i - 1]) / (2.0 * h);
        Doub d2V = (V[i + 1] - 2.0 * V[i] + V[i - 1]) / (h * h);

        Doub num = 48.0 * (pow(V[i], 3) + 2.0 * pow(ui, 3) * pow(dV, 2)) * (2.0 * ui * ui - V[i] * V[i]) * pow(dV, 2);
        Doub den = 1.0 + 64.0 * pow(ui, 6) + 16.0 * pow(V[i], 6);
        Doub rhs = num / den;

        fvec[i - 1] = d2V - rhs;
    }
}

// Compute both residual and Jacobian for use with mnewt
void usrfun(VecDoub_I &x, VecDoub_O &fvec, MatDoub_O &fjac) {
    Int N = x.size();
    fvec.resize(N);
    fjac.resize(N, N);

    compute_residual(x, fvec);

    Doub eps = 1e-8;
    VecDoub xtemp = x, ftemp(N);

    for (int j = 0; j < N; ++j) {
        xtemp[j] += eps;
        compute_residual(xtemp, ftemp);
        xtemp[j] -= eps;

        for (int i = 0; i < N; ++i)
            fjac[i][j] = (ftemp[i] - fvec[i]) / eps;
    }
}

// Solve boundary value problem using finite differences + Newton
bool solve_bvp(Doub uA, Doub vA, Doub uB, Doub vB, Int N, VecDoub &u, VecDoub &V, Doub tol = 1e-6) {
    Doub h = (uB - uA) / N;

    ctx.h = h;
    ctx.vA = vA;
    ctx.vB = vB;
    ctx.u.resize(N + 1);
    for (int i = 0; i <= N; ++i)
        ctx.u[i] = uA + i * h;

    u = ctx.u;

    // Solve for interior nodes only
    Int M = N - 1;
    VecDoub x(M);
    for (int i = 0; i < M; ++i)
        x[i] = vA + (vB - vA) * (i + 1.0) / N;  // Linear guess

    try {
        mnewt(30, x, tol, tol);
    } catch (...) {
        return false;
    }

    V.resize(N + 1);
    V[0] = vA;
    for (int i = 0; i < M; ++i)
        V[i + 1] = x[i];
    V[N] = vB;

    return true;
}
