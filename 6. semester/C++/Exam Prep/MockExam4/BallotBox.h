#ifndef BALLOTBOX_H
#define BALLOTBOX_H

#include <vector>
#include <string>
#include "Candidate.h"
#include "Voter.h"

// Manages the voting process: candidates, voters, and the vote tally
class BallotBox {
private:
    std::vector<Candidate> candidates;
    std::vector<Voter> voters;

public:
    // Adds a candidate to the list
    void addCandidate(const std::string& name);

    // Adds a voter to the list
    void addVoter(const std::string& name);

    // Simulates the voting process (each voter casts one vote)
    void runElection();

    // Prints all candidates and their vote counts
    void printResults() const;

    // Returns the name of the candidate with the most votes
    std::string getWinner() const;
};

#endif
