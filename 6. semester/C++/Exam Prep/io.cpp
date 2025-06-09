#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
Ask for name and age via cin.
Print the result using cout.
Write the info to a file.
Read it back and display.
*/

int main() {
    string name;
    int age;

    // Step 1: Input from user
    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Enter your age: ";
    cin >> age;

    // Step 2: Output to console
    cout << "Hello, " << name << ". You are " << age << " years old." << endl;

    // Step 3: Write to file
    ofstream outFile("userinfo.txt");
    if (outFile.is_open()) {
        outFile << name << endl;
        outFile << age << endl;
        outFile.close();
        cout << "Data written to userinfo.txt\n";
    } else {
        cerr << "Error writing to file.\n";
        return 1;
    }

    // Step 4: Read back from file
    ifstream inFile("userinfo.txt");
    if (inFile.is_open()) {
        string readName;
        int readAge;

        getline(inFile, readName);
        inFile >> readAge;

        inFile.close();

        cout << "Data read from file:\n";
        cout << "Name: " << readName << "\nAge: " << readAge << endl;
    } else {
        cerr << "Error reading from file.\n";
        return 1;
    }

    return 0;
}
