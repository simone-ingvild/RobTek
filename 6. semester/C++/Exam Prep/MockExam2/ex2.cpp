// ex2.cpp
#include <iostream>
#include <string>
#include <cctype> // for std::tolower

// Function to count occurrences of a character in a string (case-insensitive)
int countOccurrences(const std::string &text, char ch) {
    int count = 0;
    char lowerCh = std::tolower(ch);
    for (char c : text) {
        if (std::tolower(c) == lowerCh) count++;
    }
    return count;
}

int main() {
    std::string sample = "BanAna";
    char toFind = 'a';

    std::cout << "Occurrences of '" << toFind << "': "
              << countOccurrences(sample, toFind) << std::endl;

    return 0;
}