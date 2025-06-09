#ifndef STDDEV_H
#define STDDEV_H

#include <vector>
#include <type_traits>
#include <cmath>
#include <string>

// ──────────────────────────────────────────────────────────────
//  stdDev
//      Population standard deviation for arithmetic element
//      types.  For non-arithmetic vectors (e.g. std::vector<std::string>)
//      the function simply returns 0.0.
// ──────────────────────────────────────────────────────────────
template <typename T>
double stdDev(const std::vector<T>& v)
{
    if constexpr (!std::is_arithmetic_v<T>) {
        // Non-numeric type → always 0.0
        return 0.0;
    } else {
        const std::size_t n = v.size();
        if (n == 0) return 0.0;

        // Mean value
        double mean = 0.0;
        for (T x : v) mean += static_cast<double>(x);
        mean /= static_cast<double>(n);

        // Variance
        double var = 0.0;
        for (T x : v) {
            const double diff = static_cast<double>(x) - mean;
            var += diff * diff;
        }
        var /= static_cast<double>(n);    // population variance
        return std::sqrt(var);
    }
}

#endif   // STDDEV_H
