#include <iostream>
#include <string>
#include <cctype>

//Returns true if the input text is a palindrome, ignoring case and non-alphanumeric characters.
bool isPalindrome(const std::string &text) {
    int left = 0;
    int right = text.length() - 1;

    while (left < right) {
        //Skip non-alphanumeric characters from the left
        while (left < right && !std::isalnum(text[left])) {
            left++;
        }

        //Skip non-alphanumeric characters from the right
        while (left < right && !std::isalnum(text[right])) {
            right--;
        }

        //Compare characters (case-insensitive)
        if (std::tolower(text[left]) != std::tolower(text[right])) {
            return false; //Mismatch found
        }

        left++;
        right--;
    }

    return true; //No mismatches found
}

int main() {
    //Test examples
    std::string input;

    std::cout << "Enter a string to check if it's a palindrome: ";
    std::getline(std::cin, input);

    if (isPalindrome(input)) {
        std::cout << "\"" << input << "\" is a palindrome.\n";
    } else {
        std::cout << "\"" << input << "\" is NOT a palindrome.\n";
    }

    //Optional: predefined test cases
    std::cout << "\nQuick test cases:\n";
    std::cout << "racecar => " << (isPalindrome("racecar") ? "true" : "false") << "\n";
    std::cout << "A man, a plan, a canal: Panama => " 
              << (isPalindrome("A man, a plan, a canal: Panama") ? "true" : "false") << "\n";
    std::cout << "hello => " << (isPalindrome("hello") ? "true" : "false") << "\n";

    return 0;
}
