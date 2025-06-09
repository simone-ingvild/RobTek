#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // File name
    const string filename = "example.txt";

    // Step 1: Write to the file
    ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << "Hello, world!" << endl;
        outFile << "This is a test." << endl;
        outFile << "C++ file I/O is straightforward." << endl;
        outFile.close();
    }
    else {
        cerr << "Error opening file for writing." << endl;
        return 1;
    }

    // Step 2: Read from the file
    ifstream inFile(filename);
    if (inFile.is_open()) {
        string line;
        cout << "File contents:\n";
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    }
    else {
        cerr << "Error opening file for reading." << endl;
        return 1;
    }

    return 0;
}