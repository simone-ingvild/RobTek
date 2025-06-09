#include "Bin.h"

#include <chrono>          // seed source for RNG
#include <stdexcept>       // std::out_of_range
#include <algorithm>       // std::shuffle, std::count
#include <random>          // std::uniform_int_distribution

// Seeds the random-number engine so every program run produces a different sequence.
Bin::Bin()
{
    const auto seed = static_cast<unsigned long>(
        std::chrono::system_clock::now().time_since_epoch().count());
    mRandomEngine.seed(seed);
}


// Fills the bin with an (as) even (as possible) distribution of integers in the inclusive range [min, max].  Any remainder is spread one-by-one across the range.
void Bin::fillBin(int min, int max, int amount)
{
    mValues.clear();

    const int range      = max - min + 1;
    const int baseCount  = amount / range;  // baseline per value
    const int remainder  = amount % range;  // leftovers to distribute

    // Insert baseCount copies of each value.
    for (int v = min; v <= max; ++v)
        mValues.insert(mValues.end(), baseCount, v);

    // Distribute the remainder cyclically.
    for (int i = 0; i < remainder; ++i)
        mValues.push_back(min + (i % range));

    // Randomise starting order.
    std::shuffle(mValues.begin(), mValues.end(), mRandomEngine);
}

// Draws a random ticket, removes it using swap-and-pop, and returns the drawn value (O(1) removal).
int Bin::drawAndRemove()
{
    if (mValues.empty())
        throw std::out_of_range("Cannot draw from empty bin");

    std::uniform_int_distribution<std::size_t> dist(0, mValues.size() - 1);
    const std::size_t idx = dist(mRandomEngine);
    const int value       = mValues[idx];

    std::swap(mValues[idx], mValues.back());
    mValues.pop_back();

    return value;
}


// Returns how many tickets with the requested value remain.
unsigned int Bin::count(int value) const
{
    return static_cast<unsigned int>(
        std::count(mValues.begin(), mValues.end(), value));
}


//Current number of tickets left in the bin.
unsigned int Bin::size() const
{
    return static_cast<unsigned int>(mValues.size());
}
