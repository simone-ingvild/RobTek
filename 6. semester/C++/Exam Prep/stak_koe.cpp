#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <stdexcept>

using namespace std;

// Exercise 1: Method to Check for Matching Parentheses in a String
bool checkParentheses(const string& str) {
    stack<char> s;

    for (char c : str) {
        if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            if (s.empty()) {
                return false;
            }
            s.pop();
        }
    }

    return s.empty();
}

// Exercise 2: Class to Represent a Queue
template <typename T>
class Queue {
private:
    std::queue<T> q;

public:
    void enqueue(T value) {
        q.push(value);
    }

    T dequeue() {
        if (q.empty()) {
            throw out_of_range("Queue is empty");
        }
        T front = q.front();
        q.pop();
        return front;
    }

    bool isEmpty() const {
        return q.empty();
    }

    size_t size() const {
        return q.size();
    }
};

// Exercise 1 (Templates): Template Function to Find Maximum Element in an Array
template <typename T>
T findMax(T arr[], int size) {
    if (size <= 0) {
        throw invalid_argument("Array size must be positive");
    }

    T maxVal = arr[0];
    for (int i = 1; i < size; ++i) {
        maxVal = max(maxVal, arr[i]);
    }
    return maxVal;
}

// Exercise 2 (Templates): Template Class for a Simple Pair
template <typename T1, typename T2>
class Pair {
private:
    T1 first;
    T2 second;

public:
    Pair(T1 val1, T2 val2) : first(val1), second(val2) {}

    T1 getFirst() const { return first; }
    T2 getSecond() const { return second; }

    void setFirst(T1 val) { first = val; }
    void setSecond(T2 val) { second = val; }

    void print() const {
        cout << "(" << first << ", " << second << ")" << endl;
    }
};

// Exercise 3 (Templates): Template Function to Reverse an Array
template <typename T>
void reverseArray(T arr[], int size) {
    for (int i = 0; i < size / 2; ++i) {
        swap(arr[i], arr[size - 1 - i]);
    }
}

template <typename T>
void printArray(T arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Test Exercise 1: Parentheses
    cout << "**Exercise 1: Parentheses**\n";
    string test1 = "(hello(world))";
    string test2 = "(hello(world)";
    string test3 = "hello(world))";
    string test4 = "hello world";

    cout << test1 << ": " << (checkParentheses(test1) ? "true" : "false") << endl;
    cout << test2 << ": " << (checkParentheses(test2) ? "true" : "false") << endl;
    cout << test3 << ": " << (checkParentheses(test3) ? "true" : "false") << endl;
    cout << test4 << ": " << (checkParentheses(test4) ? "true" : "false") << endl;

    cout << "\n";

    // Test Exercise 2: Queue
    cout << "**Exercise 2: Queue**\n";
    Queue<int> intQueue;
    intQueue.enqueue(10);
    intQueue.enqueue(20);
    intQueue.enqueue(30);

    cout << "Queue size: " << intQueue.size() << endl;

    cout << "Dequeue: " << intQueue.dequeue() << endl;
    cout << "Dequeue: " << intQueue.dequeue() << endl;

    cout << "Is empty: " << (intQueue.isEmpty() ? "true" : "false") << endl;

    cout << "Dequeue: " << intQueue.dequeue() << endl;
    cout << "Is empty: " << (intQueue.isEmpty() ? "true" : "false") << endl;

    try {
        intQueue.dequeue(); // Should throw
    } catch (const out_of_range& e) {
        cerr << "Exception: " << e.what() << endl;
    }

    Queue<string> stringQueue;
    stringQueue.enqueue("hello");
    stringQueue.enqueue("world");

    cout << "Dequeue string: " << stringQueue.dequeue() << endl;

    cout << "\n";

    // Test Exercise 1 (Templates): Find Max
    cout << "**Exercise 1 (Templates): Find Max**\n";
    int intArray[] = {3, 1, 4, 1, 5, 9, 2, 6};
    double doubleArray[] = {2.7, 1.6, 3.14, 1.41};

    cout << "Max int: " << findMax(intArray, 8) << endl;
    cout << "Max double: " << findMax(doubleArray, 4) << endl;

    try {
        findMax(intArray, 0); // Should throw
    } catch (const invalid_argument& e) {
        cerr << "Exception: " << e.what() << endl;
    }

    cout << "\n";

    // Test Exercise 2 (Templates): Pair
    cout << "**Exercise 2 (Templates): Pair**\n";
    Pair<int, string> myPair1(10, "hello");
    Pair<double, double> myPair2(3.14, 2.71);

    myPair1.print();
    myPair2.print();

    cout << "First: " << myPair1.getFirst() << endl;
    cout << "Second: " << myPair1.getSecond() << endl;

    myPair1.setFirst(20);
    myPair1.setSecond("world");
    myPair1.print();

    cout << "\n";

    // Test Exercise 3 (Templates): Reverse Array
    cout << "**Exercise 3 (Templates): Reverse Array**\n";
    int intArray2[] = {1, 2, 3, 4, 5};
    double doubleArray2[] = {1.1, 2.2, 3.3, 4.4};

    cout << "Original int array: ";
    printArray(intArray2, 5);

    reverseArray(intArray2, 5);

    cout << "Reversed int array: ";
    printArray(intArray2, 5);

    cout << "Original double array: ";
    printArray(doubleArray2, 4);

    reverseArray(doubleArray2, 4);

    cout << "Reversed double array: ";
    printArray(doubleArray2, 4);

    return 0;
}