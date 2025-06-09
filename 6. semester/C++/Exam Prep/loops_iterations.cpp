#include <iostream>
using namespace std;

/*
Print numbers from 1–100 using:
while
for
do-while
range-based for-loop
Nested for-loop
Sum all even numbers under 100.
*/

int main(){
   // while lopp
   int i = 1;
   cout << "While loop: ";
   while (i <= 100) {
       cout << i << " ";
       i++;
   }    
    cout << endl;

    // for loop
    cout << "For loop: ";
    for (int j = 1; j <= 100; j++) {
        cout << j << " ";
    }
    cout << endl;

    // do-while loop
    int k = 1;
    cout << "Do-while loop: ";
    do {
        cout << k << " ";
        k++;
    } while (k <= 100);
    cout << endl;   

    // range-based for loop
    cout << "Range-based for loop: ";
    int numbers[] = {1, 2, 3, 4, 5};
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    // Nested for loop
    cout << "Nested for loop: " << endl;
    for (int row = 1; row <= 5; row++) {
        for (int col = 1; col <= 5; col++) {
            cout << "(" << row << ", " << col << ") ";
        }
        cout << endl;
    }

    // Sum of even numbers under 100
    int sum = 0;
    for (int n = 0; n < 100; n++) {
        if (n % 2 == 0) {
            sum += n;
        }
    }
    cout << "Sum of even numbers under 100: " << sum << endl;


    return 0;
}