#include <iostream>
using namespace std;

/*Write a swap function using references.
Write the same using pointers.
Compare the two approaches.*/

// Swap using references
void swapByReference(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Swap using pointers
void swapByPointer(int* a, int* b) {
    if (a && b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
}

int main() {
    int x = 5, y = 10;

    cout << "Original values: x = " << x << ", y = " << y << endl;

    // Use reference-based swap
    swapByReference(x, y);
    cout << "After swapByReference: x = " << x << ", y = " << y << endl;

    // Use pointer-based swap
    swapByPointer(&x, &y);
    cout << "After swapByPointer: x = " << x << ", y = " << y << endl;

    return 0;
}
