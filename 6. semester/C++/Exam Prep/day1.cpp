#include <iostream>
#include <string>
using namespace std;

// C++ review
/*
Covers learning goals related to: I/O (cin, out) arrays and strings, basic class design and syntax correctness
*/

// Exercise 1
/*Program asks for user's name and age, print greeting depending on over/under 18, prints all even numbers up to user's age*/
void basicIO() {
    string name;
    int age;

    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your age: ";
    cin >> age;

    cout << "Hello, " << name << "! You are " << (age >= 18 ? "an adult." : "a minor.") << endl;

    cout << "Even numbers up to your age:" << endl;
    for (int i = 0; i <= age; i += 2) {
        cout << i << " ";
    }
    cout << endl;
}

// Exercise 2
/*Reads n numbers from user, stores them in array, calls function to find and print maximum*/
int findMaxValue(int arr[], int size) {
    int maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}
void arrayMax() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Enter " << n << " numbers:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int maxValue = findMaxValue(arr, n);
    cout << "The maximum value is: " << maxValue << endl;

    delete[] arr;
}

// Exercise 3
/*Asks user for a string and a character, counts how many times the char appears and makes a case-sensitive check*/
int countLetter(const string& text, char letter) {
    int count = 0;
    for (char c : text) {
        if (c == letter) {
            count++;
        }
    }
    return count;
}
void letterCount() {
    cin.ignore(); // flush leftover newline
    string text;
    char letter;

    cout << "Enter a string: ";
    getline(cin, text);

    cout << "Enter a character to count: ";
    cin >> letter;

    int count = countLetter(text, letter);
    cout << "The character '" << letter << "' appears " << count << " times in the string." << endl;
}

// Exercise 4
/* Asks user for string, outputs the reversed string*/
string reverseString(const string& text) {
    string reversed = "";
    for (int i = text.length() - 1; i >= 0; i--) {
        reversed += text[i];
    }
    return reversed;
}
void reverseText() {
    cin.ignore();
    string text;
    cout << "Enter a string to reverse: ";
    getline(cin, text);

    cout << "Reversed string: " << reverseString(text) << endl;
}

// Exercise 5
/* Uses simplified class and creates two car objects and prints registration number and year*/
class Car {
public:
    Car(string r, int y) : regNr(r), year(y) {}
    string getRegNr() { return regNr; }
    int getYear() { return year; }

private:
    string regNr;
    int year;
};
void carDemo() {
    Car car1("ABC123", 2020);
    Car car2("XYZ789", 2018);

    cout << "Car 1 Registration Number: " << car1.getRegNr() << ", Year: " << car1.getYear() << endl;
    cout << "Car 2 Registration Number: " << car2.getRegNr() << ", Year: " << car2.getYear() << endl;
}

// Exercise 6
/* Prints multiplication table from 1 to n, formatted like a grid*/
void printMultiplicationTable(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << i * j << "\t";
        }
        cout << endl;
    }
}
void multiplicationTable() {
    int n;
    cout << "Enter the size of the multiplication table: ";
    cin >> n;

    printMultiplicationTable(n);
}

// Main Menu
int main() {
    int choice;
    do {
        cout << "\n=== C++ Exercise Menu ===\n";
        cout << "1. Basic I/O & Control Flow\n";
        cout << "2. Array - Find Max\n";
        cout << "3. String - Count Letter\n";
        cout << "4. Reverse String\n";
        cout << "5. Car Class Demo\n";
        cout << "6. Multiplication Table\n";
        cout << "0. Exit\n";
        cout << "Choose an exercise to run: ";
        cin >> choice;

        switch (choice) {
            case 1: basicIO(); break;
            case 2: arrayMax(); break;
            case 3: letterCount(); break;
            case 4: reverseText(); break;
            case 5: carDemo(); break;
            case 6: multiplicationTable(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid option. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
