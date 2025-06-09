#include <iostream>
#include <string>

//Returns true if the text starts with the given prefix
bool startsWith(const std::string &text, const std::string &prefix) {
    //Check if prefix is longer than text
    if (prefix.size() > text.size()) return false;

    //Compare prefix with beginning of text
    return text.substr(0, prefix.size()) == prefix;
}

int main() {
    std::string text, prefix;

    //Ask user for input
    std::cout << "Enter full text: ";
    std::getline(std::cin, text);

    std::cout << "Enter prefix to check: ";
    std::getline(std::cin, prefix);

    //Run and display result
    if (startsWith(text, prefix)) {
        std::cout << "The text starts with the prefix.\n";
    } else {
        std::cout << "The text does NOT start with the prefix.\n";
    }

    return 0;
}
