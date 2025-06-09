#include <iostream>
#include <string>
#include <ctime>
#include <cctype>

class CprNr {
private:
    std::string nummeret;

public:
    // Constructor
    CprNr(std::string etCprNr) {
        nummeret = etCprNr;
    }

    // Getter for CPR number
    std::string getCprNr() {
        return nummeret;
    }

    // Setter for CPR number
    void setCprNr(std::string etCprNr) {
        nummeret = etCprNr;
    }

    // Extract day from CPR number
    int getDag() {
        return std::stoi(nummeret.substr(0, 2));
    }

    // Extract month from CPR number
    int getMaaned() {
        return std::stoi(nummeret.substr(2, 2));
    }

    // Extract year from CPR number
    int getAar() {
        int year = std::stoi(nummeret.substr(4, 2));
        int seventhDigit = nummeret[6] - '0'; // Convert char to int

        if (seventhDigit >= 0 && seventhDigit <= 3)
            return 1900 + year;
        else if (seventhDigit >= 4 && seventhDigit <= 5)
            return 1800 + year;
        else if (seventhDigit >= 6 && seventhDigit <= 9)
            return 2000 + year;

        return 1900 + year; // Default case
    }

    // Get full date in YYYYMMDD format
    int getDato() {
        return getAar() * 10000 + getMaaned() * 100 + getDag();
    }

    // Calculate age
    int getAlder() {
        time_t t = time(0);
        tm* now = localtime(&t);
        int currentYear = now->tm_year + 1900;
        int currentMonth = now->tm_mon + 1;
        int currentDay = now->tm_mday;

        int birthYear = getAar();
        int birthMonth = getMaaned();
        int birthDay = getDag();

        int age = currentYear - birthYear;

        if (currentMonth < birthMonth || (currentMonth == birthMonth && currentDay < birthDay)) {
            age--; // If birthday hasn't occurred yet this year
        }

        return age;
    }

    // Check if the CPR holder is male (last digit odd)
    bool erMand() {
        return (nummeret.back() - '0') % 2 == 1;
    }

    // Check if the CPR holder is female (last digit even)
    bool erKvinde() {
        return (nummeret.back() - '0') % 2 == 0;
    }

    // Check if CPR number is valid using Modulus-11
    bool isValid() {
        if (nummeret.length() != 10) return false; // Must be 10 characters
        for (char c : nummeret) {
            if (!isdigit(c)) return false; // Must be numeric
        }

        int weights[] = {4, 3, 2, 7, 6, 5, 4, 3, 2, 1};
        int sum = 0;

        for (int i = 0; i < 10; i++) {
            sum += (nummeret[i] - '0') * weights[i];
        }

        return sum % 11 == 0;
    }
};

// Example usage
int main() {
    CprNr person("0409981186"); // Example CPR number

    std::cout << "CPR Number: " << person.getCprNr() << std::endl;
    std::cout << "Day: " << person.getDag() << std::endl;
    std::cout << "Month: " << person.getMaaned() << std::endl;
    std::cout << "Year: " << person.getAar() << std::endl;
    std::cout << "Date (YYYYMMDD): " << person.getDato() << std::endl;
    std::cout << "Age: " << person.getAlder() << std::endl;
    std::cout << "Is Male? " << (person.erMand() ? "Yes" : "No") << std::endl;
    std::cout << "Is Female? " << (person.erKvinde() ? "Yes" : "No") << std::endl;
    std::cout << "Is Valid CPR? " << (person.isValid() ? "Yes" : "No") << std::endl;

    return 0;
}
