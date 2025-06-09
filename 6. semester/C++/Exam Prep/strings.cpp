#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

// 1. Counting Character Occurrences
void countCharacter(const std::string& text, char target) {
    int count = 0;
    for (char c : text) {
        if (c == target) {
            count++;
        }
    }
    std::cout << "Bogstavet '" << target << "' forekommer " << count << " gange i teksten." << std::endl;
}

// 2. Reversing a String
std::string reverseString(std::string text) {
    std::reverse(text.begin(), text.end());
    return text;
}

// 3. Printing Every Other Character
std::string everyOtherCharacter(const std::string& text) {
    std::string result = "";
    for (size_t i = 0; i < text.length(); i += 2) {
        result += text[i];
    }
    return result;
}

// 4. Summing Two Strings Representing Numbers
int sumStrings(const std::string& num1, const std::string& num2) {
    std::stringstream ss1(num1);
    std::stringstream ss2(num2);
    int n1, n2;
    ss1 >> n1;
    ss2 >> n2;
    return n1 + n2;
}

// 5. Checking if a Word Exists in a Text
bool wordExists(const std::string& text, const std::string& word) {
    return text.find(word) != std::string::npos;
}

int main() {
    // Example Usage:
    std::string text1 = "anna har en hat";
    char target = 'a';
    countCharacter(text1, target); // Example for task 1

    std::string text2 = "olfert";
    std::string reversed = reverseString(text2);
    std::cout << reversed << std::endl; // Example for task 2

    std::string text3 = "P. Hansen Danmark";
    std::string everyOther = everyOtherCharacter(text3);
    std::cout << everyOther << std::endl; // Example for task 3

    std::string num1 = "19";
    std::string num2 = "21";
    int sum = sumStrings(num1, num2);
    std::cout << sum << std::endl; // Example for task 4

    std::string text4 = "den som solen skinner på";
    std::string word1 = "som";
    std::string word2 = "vinter";

    std::cout << std::boolalpha;
    std::cout << wordExists(text4, word1) << std::endl; // Example for task 5
    std::cout << wordExists(text4, word2) << std::endl;

    return 0;
}