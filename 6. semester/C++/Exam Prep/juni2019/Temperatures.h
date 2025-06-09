#ifndef TEMPERATURES_H
#define TEMPERATURES_H

#include <vector>
#include <initializer_list>
#include <algorithm>
#include <numeric>
#include <stdexcept>

class Temperatures {
public:
    // Constructor: list of measurements + units  ('C' or 'K')
    Temperatures(std::initializer_list<double> init, char unit)
        : mVals(init), mUnit(unit)
    {
        if (unit != 'C' && unit != 'K')
            throw std::invalid_argument("units must be 'C' or 'K'");
    }

    // Add one measurement (in the object’s own unit system)
    void add(double v) { mVals.push_back(v); }

    // Mean value
    double mean() const
    {
        if (mVals.empty()) return 0.0;
        double sum = std::accumulate(mVals.begin(), mVals.end(), 0.0);
        return sum / static_cast<double>(mVals.size());
    }

    // Range (max – min)
    double range() const
    {
        if (mVals.empty()) return 0.0;
        auto [mn, mx] = std::minmax_element(mVals.begin(), mVals.end());
        return *mx - *mn;
    }

    // Unit indicator
    char units() const { return mUnit; }

    // Return **new** object whose values are in Celsius
    Temperatures toDegC() const
    {
        if (mUnit == 'C') return *this;          // already Celsius
        std::vector<double> conv;
        conv.reserve(mVals.size());
        for (double k : mVals) conv.push_back(k - 273.15);
        return Temperatures(conv, 'C');
    }

private:
    // private ctor used by toDegC
    Temperatures(const std::vector<double>& v, char u) : mVals(v), mUnit(u) {}

    std::vector<double> mVals;
    char                mUnit;   // 'C' or 'K'
};

#endif   // TEMPERATURES_H
