#include <iostream>
#include <string>
#include "Rectangle.h"
using namespace std;

// C++ review
/*
Covers learning goals related to: pointers and memory management (new, delete), stack vs. heap understanding,
use of const for safety and design clarity, class design using dynamic memory and header guards in .h files.
*/

// Exercise 1 - Pointer basics
/* Declare an int variable and a pointer to it, 
print both the variable and the value via the pointer (* and &), 
and modify the value using the pointer */
void pointerBasics() {
    int number = 42;
    int* ptr = &number;

    cout << "Value of number: " << number << endl;
    cout << "Address of number (&number): " << &number << endl;
    cout << "Value via pointer (*ptr): " << *ptr << endl;
    cout << "Pointer value (ptr, i.e. address): " << ptr << endl;

    *ptr = 99;

    cout << "\nAfter modifying via pointer:" << endl;
    cout << "Value of number: " << number << endl;
    cout << "Value via pointer (*ptr): " << *ptr << endl;
}

// Exercise 2 - Dynamic array allocation
/* Ask the user for n, allocate an array dynamically with new, 
fill it in with values, print them in reverse, 
free the memory with delete */
void dynamicArrayAllocation() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Element " << i << ": ";
        cin >> arr[i];
    }

    cout << "\nArray in reverse order:" << endl;
    for (int i = n - 1; i >= 0; --i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
}

// Exercise 3 - Pointer to object
/* Create a simple class Book with title and year, 
allocate an object with new, use -> to access its members and print them */
class Book {
public:
    string title;
    int year;

    Book(const string& t, int y) : title(t), year(y) {}
};

void pointerToObject() {
    Book* myBook = new Book("The C++ Handbook", 2023);
    cout << "Book Title: " << myBook->title << endl;
    cout << "Published Year: " << myBook->year << endl;
    delete myBook;
}

// Exercise 4 - Const correctness in functions
/* Write a function that takes a const &int and prints it, 
try to modify it inside the function and observe the compile error, 
repeat with a const */
void printAndTryModify(const int& value) {
    cout << "Value received: " << value << endl;
    // value = value + 1; // ❌ Error if uncommented
}

void constCorrectnessFunction() {
    int number = 10;
    printAndTryModify(number);
}

// Exercise 5 - Const member functions
/* Make a class Student with getName(), getAge() as const member functions.
Create a const Student and show you can only call const methods on it */
class Student {
private:
    string name;
    int age;

public:
    Student(const string& n, int a) : name(n), age(a) {}
    string getName() const { return name; }
    int getAge() const { return age; }

    // void setName(const string& n) { name = n; } // ❌ Non-const
};

void constMemberFunctions() {
    const Student s("Alice", 21);
    cout << "Name: " << s.getName() << endl;
    cout << "Age: " << s.getAge() << endl;
    // s.setName("Bob"); // ❌ Compile error if uncommented
}

// Exercise 6 - Const with pointers
/* Write examples for each of the following:
   const int* ptr – value pointed to is constant
   int* const ptr – pointer itself is constant
   const int* const ptr – both are constant */
void constPointerExamples() {
    int a = 10;
    int b = 20;

    // 1️⃣ const int* ptr: value is const, pointer is not
    const int* ptr1 = &a;
    // *ptr1 = 15; // ❌ Error: cannot modify value through ptr1
    ptr1 = &b;     // ✅ OK: can point to another variable
    cout << "ptr1 points to: " << *ptr1 << endl;

    // 2️⃣ int* const ptr: pointer is const, value is not
    int* const ptr2 = &a;
    *ptr2 = 25;    // ✅ OK: can modify the value
    // ptr2 = &b;  // ❌ Error: cannot change what ptr2 points to
    cout << "ptr2 points to: " << *ptr2 << endl;

    // 3️⃣ const int* const ptr: both pointer and value are const
    const int* const ptr3 = &a;
    // *ptr3 = 30; // ❌ Error: cannot modify value
    // ptr3 = &b;  // ❌ Error: cannot change pointer
    cout << "ptr3 points to: " << *ptr3 << endl;
}

// Exercise 7 - Header guards
/* Use Rectangle.h and Rectangle.cpp. Instantiate a Rectangle and call getArea and getPerimeter. */
void rectangleDemo() {
    Rectangle r(5.0, 3.0);
    cout << "Area: " << r.getArea() << endl;
    cout << "Perimeter: " << r.getPerimeter() << endl;
}

// Menu
int main() {
    int choice;

    do {
        cout << "\n=== Day 2: Pointer & Const Menu ===\n";
        cout << "1. Pointer Basics\n";
        cout << "2. Dynamic Array Allocation\n";
        cout << "3. Pointer to Object\n";
        cout << "4. Const Correctness in Function\n";
        cout << "5. Const Member Functions\n";
        cout << "6. Const with Pointers\n";
        cout << "7. Header Guard Test with Rectangle\n";
        cout << "0. Exit\n";
        cout << "Choose an exercise to run: ";
        cin >> choice;

        switch (choice) {
            case 1: pointerBasics(); break;
            case 2: dynamicArrayAllocation(); break;
            case 3: pointerToObject(); break;
            case 4: constCorrectnessFunction(); break;
            case 5: constMemberFunctions(); break;
            case 6: constPointerExamples(); break;
            case 7: rectangleDemo(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
