#ifndef BIN_H
#define BIN_H

#include <string>
#include <vector>
#include <random>

// Helper class for random assignment of subjects
class Bin {
private:
    std::vector<std::string> items; // Items in the bin
    std::mt19937 rng;               // Random number generator

public:
    Bin(unsigned int seed = 42);                                                // reproducible random number generator
    void fillEvenly(const std::vector<std::string>& elements, int totalSlots);  // Fill bin evenly and shuffle
    std::string draw();                                                         // Draw an item from the bin
    bool empty() const;                                                         // Check if bin is empty
};

#endif
