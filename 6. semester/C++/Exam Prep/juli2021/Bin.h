#ifndef BIN_H
#define BIN_H

#include <vector>
#include <random>
#include <algorithm>

// Represents a bin (bucket) of numbered tickets for random drawing without replacement
class Bin {
public:
    // Constructor initializes the random engine
    Bin();

    // Fills the bin with a fair distribution of integers in the range [min, max]
    void fillBin(int min, int max, int amount);

    // Draws and removes a random value from the bin
    int drawAndRemove();

    // Counts how many times a specific value appears in the bin
    unsigned int count(int value) const;

    // Returns the current number of tickets in the bin
    unsigned int size() const;

private:
    std::default_random_engine mRandomEngine; // RNG for drawing
    std::vector<int> mValues;                 // Stored values (tickets)
};

#endif // BIN_H
