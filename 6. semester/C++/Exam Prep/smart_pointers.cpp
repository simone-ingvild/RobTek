#include <iostream>
#include <memory>  // for smart pointers
using namespace std;

/*Use std::unique_ptr to manage a dynamically allocated object.
Use std::shared_ptr and demonstrate reference counting.*/

// A simple class to use with smart pointers
class Book {
public:
    string title;

    Book(string t) : title(t) {
        cout << "Book '" << title << "' created.\n";
    }

    ~Book() {
        cout << "Book '" << title << "' destroyed.\n";
    }

    void print() {
        cout << "Book Title: " << title << endl;
    }
};

void sharedPointerDemo(shared_ptr<Book> sp) {
    cout << "[Inside function] Use count: " << sp.use_count() << endl;
    sp->print();
}

int main() {
    // Part 1: unique_ptr
    cout << "=== unique_ptr example ===\n";
    unique_ptr<Book> uniqueBook = make_unique<Book>("1984");
    uniqueBook->print();
    // unique_ptr automatically deletes the object when it goes out of scope

    // Part 2: shared_ptr
    cout << "\n=== shared_ptr example ===\n";
    shared_ptr<Book> sharedBook = make_shared<Book>("Brave New World");
    cout << "Initial use count: " << sharedBook.use_count() << endl;

    {
        shared_ptr<Book> sharedBook2 = sharedBook;
        cout << "Use count after copy: " << sharedBook.use_count() << endl;
        sharedPointerDemo(sharedBook2);
    } // sharedBook2 goes out of scope

    cout << "Use count after sharedBook2 is destroyed: " << sharedBook.use_count() << endl;

    return 0;
}
