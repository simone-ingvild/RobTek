#include <iostream> 
#include <string>    

// Function to check if 'word' is a substring of 'text'
bool containsWord(const std::string &text, const std::string &word) {
    // std::string::find returns npos if 'word' is not found in 'text'
    // Otherwise, it returns the index where 'word' starts in 'text'
    return text.find(word) != std::string::npos;
}

int main() {
    std::string text, word;

    // Prompt user for the full text input
    std::cout << "Enter text: ";
    std::getline(std::cin, text);  // Read entire line including spaces

    // Prompt user for the word to search for
    std::cout << "Enter word to search for: ";
    std::getline(std::cin, word);  // Read word (can also be a substring)

    // Use the function and output the result
    if (containsWord(text, word)) {
        std::cout << "The word is contained in the text.\n";
    } else {
        std::cout << "The word is NOT contained in the text.\n";
    }

    return 0;  // Exit success
}
