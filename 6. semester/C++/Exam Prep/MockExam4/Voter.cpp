#include "Voter.h"
#include <random>

//Define the static random number generator
std::mt19937 Voter::rng;

//Constructor to set voter's name
Voter::Voter(const std::string& name) : name(name) {}

//Returns the voter's name
std::string Voter::getName() const {
    return name;
}

//Initializes the shared RNG with a seed
void Voter::initializeRNG(unsigned int seed) {
    rng.seed(seed);
}

//Returns a random candidate index between 0 and candidateCount - 1
int Voter::vote(int candidateCount) const {
    std::uniform_int_distribution<int> dist(0, candidateCount - 1);
    return dist(rng);
}
