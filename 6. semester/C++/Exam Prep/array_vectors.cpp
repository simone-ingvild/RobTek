#include <iostream>
#include <vector>
#include <algorithm>  // For sort()

/*
Store and print 10 integers using an array.
Convert to std::vector, allow user input, sort and print.
*/

using namespace std;

int main() {
    // Part 1: Using array
    int numbers[10] = {5, 8, 2, 9, 1, 6, 3, 4, 7, 0};

    cout << "Array contents:\n";
    for (int i = 0; i < 10; i++) {
        cout << numbers[i] << " ";
    }
    cout << "\n\n";

    // Part 2: Using vector
    vector<int> vecNumbers;

    cout << "Enter 10 integers:\n";
    for (int i = 0; i < 10; i++) {
        int value;
        cout << "Enter number " << i + 1 << ": ";
        cin >> value;
        vecNumbers.push_back(value);
    }

    // Sort the vector
    sort(vecNumbers.begin(), vecNumbers.end());

    // Print the sorted vector
    cout << "\nSorted vector contents:\n";
    for (int num : vecNumbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
