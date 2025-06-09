#include "Candidate.h"

//Constructor initializes candidate name and zero votes
Candidate::Candidate(const std::string& name) : name(name), votes(0) {}

//Returns the candidate's name
std::string Candidate::getName() const {
    return name;
}

//Returns the number of votes the candidate has received
int Candidate::getVotes() const {
    return votes;
}

//Increments the vote count for the candidate by one
void Candidate::addVote() {
    votes++;
}
