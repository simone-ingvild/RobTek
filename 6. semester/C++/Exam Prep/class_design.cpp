#include <iostream>
#include <string>
using namespace std;

/*Create a Book class with title, author, pages.
Implement constructor, destructor, and printInfo() method.*/

class Book {
private:
    string title;
    string author;
    int pages;

public:
    // Constructor
    Book(string t, string a, int p) {
        title = t;
        author = a;
        pages = p;
        cout << "Book object created.\n";
    }

    // Destructor
    ~Book() {
        cout << "Book object destroyed.\n";
    }

    // Method to print book information
    void printInfo() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Pages: " << pages << endl;
    }
};

int main() {
    // Create a Book object
    Book myBook("1984", "George Orwell", 328);

    // Call printInfo
    myBook.printInfo();

    return 0;
}
