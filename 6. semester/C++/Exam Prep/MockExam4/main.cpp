#include "BallotBox.h"
#include "Voter.h"
#include <iostream>

int main() {
    //Initialize random number generator for all voters
    Voter::initializeRNG(42); // Use a fixed seed for consistent results

    BallotBox election;

    //Add candidates to the ballot
    election.addCandidate("Alice");
    election.addCandidate("Bob");
    election.addCandidate("Charlie");

    //Add 100 voters (e.g., Voter1, Voter2, ...)
    for (int i = 1; i <= 100; ++i) {
        election.addVoter("Voter" + std::to_string(i));
    }

    //Run the election simulation
    election.runElection();

    //Display all results
    election.printResults();

    //Announce the winner
    std::cout << "\nWinner: " << election.getWinner() << std::endl;

    return 0;
}
