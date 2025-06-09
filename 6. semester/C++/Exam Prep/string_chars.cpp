#include <iostream>
#include <string>
#include <algorithm>  // For reverse()
using namespace std;

/*
Input a word and print its reverse.
Count vowels in a user-provided sentence.
Compare safety and syntax between char[] and std::string.
*/

bool isVowel(char ch) {
    ch = tolower(ch);
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int main() {
    // Part 1: Reverse a word
    string word;
    cout << "Enter a word: ";
    cin >> word;

    string reversedWord = word;
    reverse(reversedWord.begin(), reversedWord.end());

    cout << "Reversed word: " << reversedWord << endl;

    // Part 2: Count vowels in a sentence
    cin.ignore();  // Clear newline left in input buffer
    string sentence;
    cout << "\nEnter a sentence: ";
    getline(cin, sentence);

    int vowelCount = 0;
    for (char ch : sentence) {
        if (isVowel(ch)) {
            vowelCount++;
        }
    }

    cout << "Number of vowels: " << vowelCount << endl;

    // Part 3: Compare char[] vs std::string
    cout << "\nComparison of char[] and std::string:" << endl;

    // Using char array (C-style string)
    char cstr[] = "Hello";
    cout << "char[] value: " << cstr << " (can be tricky to manage memory and functions)\n";

    // Using std::string (C++ style)
    string cppStr = "Hello";
    cppStr += " World";  // Easy string manipulation
    cout << "std::string value: " << cppStr << " (safe and flexible)\n";

    return 0;
}
