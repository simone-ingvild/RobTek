#ifndef CANDIDATE_H
#define CANDIDATE_H

#include <string>

// Represents a candidate in the election
class Candidate {
private:
    std::string name;
    int votes;

public:
    Candidate(const std::string& name);

    // Returns candidate's name
    std::string getName() const;

    // Returns current vote count
    int getVotes() const;

    // Increments the candidate's vote count
    void addVote();
};

#endif
