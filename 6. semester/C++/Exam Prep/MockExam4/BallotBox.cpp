#include "BallotBox.h"
#include <iostream>

//Adds a candidate to the list
void BallotBox::addCandidate(const std::string& name) {
    candidates.emplace_back(name);
}

//Adds a voter to the list
void BallotBox::addVoter(const std::string& name) {
    voters.emplace_back(name);
}

//Simulates the election: each voter casts one vote randomly
void BallotBox::runElection() {
    int numCandidates = candidates.size();

    for (const Voter& voter : voters) {
        int choice = voter.vote(numCandidates);  // Get random candidate index
        candidates[choice].addVote();            // Give vote to that candidate
    }
}

//Prints each candidate and their total vote count
void BallotBox::printResults() const {
    std::cout << "Election Results:\n";
    for (const Candidate& c : candidates) {
        std::cout << "- " << c.getName() << ": " << c.getVotes() << " votes\n";
    }
}

//Returns the name of the candidate with the highest vote count
std::string BallotBox::getWinner() const {
    const Candidate* winner = nullptr;
    for (const Candidate& c : candidates) {
        if (!winner || c.getVotes() > winner->getVotes()) {
            winner = &c;
        }
    }
    return winner ? winner->getName() : "";
}
