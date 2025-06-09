#include <iostream>
#include <string>
#include <sstream>

//Counts the number of space-separated words in the text
int wordCount(const std::string &text) {
    std::istringstream iss(text);
    std::string word;
    int count = 0;

    while (iss >> word) {
        count++;
    }

    return count;
}

int main() {
    std::string input;

    //Prompt for input
    std::cout << "Enter a line of text: ";
    std::getline(std::cin, input);

    //Display result
    std::cout << "Word count: " << wordCount(input) << std::endl;

    return 0;
}
