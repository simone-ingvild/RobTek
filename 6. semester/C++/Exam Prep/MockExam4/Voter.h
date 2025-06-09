#ifndef VOTER_H
#define VOTER_H

#include <string>
#include <vector>
#include <random>

// Represents a voter who casts a vote randomly for one of the candidates
class Voter {
private:
    std::string name;
    static std::mt19937 rng; // Shared random number generator

public:
    Voter(const std::string& name);

    // Returns the voter's name
    std::string getName() const;

    // Selects a candidate index randomly from the given list
    int vote(int candidateCount) const;

    // Initializes RNG once
    static void initializeRNG(unsigned int seed);
};

#endif
