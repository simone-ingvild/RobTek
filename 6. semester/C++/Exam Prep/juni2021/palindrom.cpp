#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

bool isPalindrome(const std::string& word) {
    if (word.length() < 3) return false;
    return std::equal(word.begin(), word.begin() + word.size() / 2, word.rbegin());
}

std::vector<std::string> extractPalindromes(const std::string& input) {
    std::vector<std::string> result;
    std::istringstream stream(input);
    std::string word;

    while (stream >> word) {
        if (isPalindrome(word)) {
            result.push_back(word);
        }
    }

    return result;
}


int main() {
    std::string text = "radar handle machine racecar kayak jetplane";
    std::vector<std::string> palindromes = extractPalindromes(text);
    std::cout << "Palindromes: ";
    for (const auto& p : palindromes) std::cout << p << " ";
    std::cout << "\n";

    return 0;
}