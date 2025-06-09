#include <iostream>
using namespace std;

/*
Declare a pointer, allocate and deallocate memory.
Pass a pointer to a function to modify a variable.
Write a function that leaks memory — then fix it.
*/

// Function that modifies a variable using a pointer
void doubleValue(int* ptr) {
    if (ptr) {
        *ptr *= 2;
    }
}

// Function that leaks memory (bad)
void memoryLeak() {
    int* leakPtr = new int(42);
    // Memory is never deleted! BAD PRACTICE
    cout << "Leaked value (not cleaned up): " << *leakPtr << endl;
}

// Fixed version
void noMemoryLeak() {
    int* cleanPtr = new int(99);
    cout << "No leak, value: " << *cleanPtr << endl;
    delete cleanPtr;  // CLEANUP ✅
}

int main() {
    // Part 1: Pointer allocation and deallocation
    int* p = new int;   // allocate memory
    *p = 10;            // assign value
    cout << "Value through pointer: " << *p << endl;
    delete p;           // deallocate memory
    p = nullptr;        // good practice to avoid dangling pointers

    // Part 2: Modify a variable using a pointer
    int num = 21;
    cout << "Before: " << num << endl;
    doubleValue(&num);
    cout << "After: " << num << endl;

    // Part 3: Demonstrate a memory leak
    memoryLeak();

    // Fixed version
    noMemoryLeak();

    return 0;
}
