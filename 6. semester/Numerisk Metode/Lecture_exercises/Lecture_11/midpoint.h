#ifndef MIDPOINT_H
#define MIDPOINT_H

#include <functional>

double midpoint_rule(std::function<double(double)> f, double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        double x = a + h * (i + 0.5);
        sum += f(x);
    }
    return h * sum;
}

#endif
