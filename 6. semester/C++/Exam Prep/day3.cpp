#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <list>
#include <stdexcept>
using namespace std;

// Exercise 1: Basic Inheritance
// Create a base class Animal with a method speak().
// Create two derived classes: Dog and Cat, both overriding speak().
class Animal {
public:
    virtual void speak() const {
        cout << "Animal speaks" << endl;
    }
    virtual ~Animal() {}
};

class Dog : public Animal {
public:
    void speak() const override {
        cout << "Dog barks" << endl;
    }
};

class Cat : public Animal {
public:
    void speak() const override {
        cout << "Cat meows" << endl;
    }
};

// Exercise 2: Polymorphism with Pointers
// Create an Animal* pointer pointing to a Dog object.
// Call speak() and confirm that Dog::speak() is invoked.
void testPolymorphismPointer() {
    Animal* a = new Dog();
    a->speak(); // Dog barks
    delete a;
}

// Exercise 3: Template Function – Find Maximum
// Write a function template findMax that returns the max of two values.
// Use it with int, double, and string.
template <typename T>
T findMax(T a, T b) {
    return (a > b) ? a : b;
}

void testFindMax() {
    cout << "Max(3, 5): " << findMax(3, 5) << endl;
    cout << "Max(2.7, 3.14): " << findMax(2.7, 3.14) << endl;
    cout << "Max(\"apple\", \"banana\"): " << findMax(string("apple"), string("banana")) << endl;
}

// Exercise 4: Template Class – Pair
// Implement a class template Pair<T1, T2> holding two values.
// Include a constructor and a method print().
template <typename T1, typename T2>
class Pair {
private:
    T1 first;
    T2 second;
public:
    Pair(T1 a, T2 b) : first(a), second(b) {}
    void print() const {
        cout << "Pair: (" << first << ", " << second << ")" << endl;
    }
};

void testPair() {
    Pair<int, string> p(1, "one");
    p.print();
}

// Exercise 5: Stack with Match-Parentheses
// Implement a function using a stack<char> that checks if parentheses in a string are balanced.
// Return true if balanced, false otherwise.
bool isBalanced(const string& expr) {
    stack<char> s;
    for (char c : expr) {
        if (c == '(' || c == '[' || c == '{') {
            s.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (s.empty()) return false;
            char top = s.top();
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{'))
                return false;
            s.pop();
        }
    }
    return s.empty();
}

void testParentheses() {
    cout << "Is ([]){} balanced? " << (isBalanced("([]){}") ? "Yes" : "No") << endl;
    cout << "Is ((] balanced? " << (isBalanced("((]") ? "Yes" : "No") << endl;
}

// Exercise 6: Template Queue Class
// Write a template class Queue<T> with enqueue() and dequeue().
// Test it with int and string.
template <typename T>
class Queue {
private:
    list<T> data;
public:
    void enqueue(const T& item) {
        data.push_back(item);
    }
    T dequeue() {
        if (data.empty()) throw out_of_range("Queue is empty");
        T front = data.front();
        data.pop_front();
        return front;
    }
    bool isEmpty() const {
        return data.empty();
    }
};

void testQueue() {
    Queue<int> qi;
    qi.enqueue(10);
    qi.enqueue(20);
    cout << "Dequeued from int queue: " << qi.dequeue() << endl;

    Queue<string> qs;
    qs.enqueue("hello");
    qs.enqueue("world");
    cout << "Dequeued from string queue: " << qs.dequeue() << endl;
}

// Exercise 7: Polymorphic Array
// Create a vector<Animal*> and fill it with both Dog* and Cat*.
// Loop through and call speak() on each element.
void testPolymorphicArray() {
    vector<Animal*> zoo;
    zoo.push_back(new Dog());
    zoo.push_back(new Cat());

    for (Animal* a : zoo) {
        a->speak(); // dynamic dispatch
    }

    for (Animal* a : zoo) {
        delete a;
    }
}

// Menu
int main() {
    int choice;

    do {
        cout << "\n=== Day 3: Inheritance, Polymorphism & Templates ===\n";
        cout << "1. Basic Inheritance (Dog & Cat)\n";
        cout << "2. Polymorphism with Pointer\n";
        cout << "3. Template Function - findMax\n";
        cout << "4. Template Class - Pair\n";
        cout << "5. Stack - Match Parentheses\n";
        cout << "6. Template Queue Class\n";
        cout << "7. Polymorphic Array (vector of Animal*)\n";
        cout << "0. Exit\n";
        cout << "Choose an exercise to run: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Dog d;
                Cat c;
                d.speak();
                c.speak();
                break;
            }
            case 2:
                testPolymorphismPointer();
                break;
            case 3:
                testFindMax();
                break;
            case 4:
                testPair();
                break;
            case 5:
                testParentheses();
                break;
            case 6:
                testQueue();
                break;
            case 7:
                testPolymorphicArray();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
