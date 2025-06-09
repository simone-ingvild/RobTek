// day4.cpp
// === Day 4: Full Projects, Operator Overloading & Review ===

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <numeric>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

// Forward declarations for Bonus exercise
class Animal { public: virtual void speak() const = 0; virtual ~Animal() {} };
class Dog : public Animal { public: void speak() const override { cout << "Dog barks" << endl; } };

template <typename T>
T findMax(T a, T b) {
    return (a > b) ? a : b;
}

// Exercise 1: Operator Overload with Broek Class
// Task:
// Implement a Broek (fraction) class with attributes taeller and naevner
// Add overloaded operators: +, -, *, /
// Ensure all results are reduced using a forkort() helper method
class Broek {
private:
    int taeller, naevner;
    void forkort() {
        int a = abs(taeller), b = abs(naevner);
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        taeller /= a;
        naevner /= a;
    }
public:
    Broek(int t = 0, int n = 1) : taeller(t), naevner(n) { forkort(); }

    Broek operator+(const Broek& other) const {
        return Broek(taeller * other.naevner + other.taeller * naevner, naevner * other.naevner);
    }
    Broek operator-(const Broek& other) const {
        return Broek(taeller * other.naevner - other.taeller * naevner, naevner * other.naevner);
    }
    Broek operator*(const Broek& other) const {
        return Broek(taeller * other.taeller, naevner * other.naevner);
    }
    Broek operator/(const Broek& other) const {
        return Broek(taeller * other.naevner, naevner * other.taeller);
    }
    void print() const {
        cout << taeller << "/" << naevner << endl;
    }
};

void testBroek() {
    Broek b1(1, 2), b2(3, 4);
    cout << "1/2 + 3/4 = "; (b1 + b2).print();
    cout << "1/2 - 3/4 = "; (b1 - b2).print();
    cout << "1/2 * 3/4 = "; (b1 * b2).print();
    cout << "1/2 / 3/4 = "; (b1 / b2).print();
}

// Exercise 2: Kunstsamling (Art Collection) System
// Task:
// Implement a class hierarchy: Kunstvaerk (abstract), Maleri, Bog, Komposition
// Include aggregation: Person[] in each art piece, Museum for paintings
// Store them in a KunstvaerkSamling and write 3 methods:
// findSangeMedFlereKomponister(), findMalerierPaaMuseum(string), beregnAntalLaesteSider()
class Person {
public:
    string navn;
    Person(string n) : navn(n) {}
};

class Kunstvaerk {
public:
    vector<Person> personer;
    virtual string type() const = 0;
    virtual ~Kunstvaerk() {}
};

class Maleri : public Kunstvaerk {
public:
    string museum;
    string type() const override { return "Maleri"; }
};

class Bog : public Kunstvaerk {
public:
    int sider;
    string type() const override { return "Bog"; }
};

class Komposition : public Kunstvaerk {
public:
    string sangnavn;
    string type() const override { return "Komposition"; }
};

void testKunstSamling() {
    vector<Kunstvaerk*> samling;
    auto* m = new Maleri(); m->museum = "ARoS";
    auto* b = new Bog(); b->sider = 123;
    auto* k = new Komposition(); k->sangnavn = "Symfoni";
    m->personer.push_back(Person("Kunstner"));
    k->personer.push_back(Person("Komponist1"));
    k->personer.push_back(Person("Komponist2"));
    samling.push_back(m); samling.push_back(b); samling.push_back(k);

    for (auto* v : samling) delete v;
}

// Exercise 3: CPR Number Class
// Task:
// Implement a CprNr class with a private string nummeret
// Implement:
// getAlder(), getDato() (YYYYMMDD format), erMand(), erKvinde(), isValid()
// (with length check, date check, modulus-11)
class CprNr {
private:
    string nummeret;
public:
    CprNr(string nr) : nummeret(nr) {}

    string getDato() const {
        return nummeret.substr(0, 6);
    }
    bool erMand() const {
        return (nummeret[9] - '0') % 2 != 0;
    }
    bool erKvinde() const {
        return !erMand();
    }
    bool isValid() const {
        return nummeret.length() == 10; // Simplified for now
    }
};

void testCpr() {
    CprNr c("0102031234");
    cout << "Dato: " << c.getDato() << endl;
    cout << (c.erMand() ? "Mand" : "Kvinde") << endl;
    cout << "Valid: " << (c.isValid() ? "Yes" : "No") << endl;
}

// Exercise 4: File I/O – Aktivitet Project
// Task:
// Read event;task;duration from a file into an Aktivitet class
// Store in a vector<Aktivitet>
// Print:
// Number of activities, Average duration, Duration and sequence of the critical path
class Aktivitet {
public:
    string event, task;
    int duration;
};

void testAktivitet() {
    ifstream file("aktiviteter.txt");
    vector<Aktivitet> aktiviteter;
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string e, t, d;
        getline(ss, e, ';'); getline(ss, t, ';'); getline(ss, d, ';');
        aktiviteter.push_back({e, t, stoi(d)});
    }
    cout << "Antal aktiviteter: " << aktiviteter.size() << endl;
    if (!aktiviteter.empty()) {
        double avg = accumulate(aktiviteter.begin(), aktiviteter.end(), 0.0,
            [](double sum, const Aktivitet& a) { return sum + a.duration; }) / aktiviteter.size();
        cout << "Gennemsnitlig varighed: " << avg << endl;
    }
}

// Exercise 5: Coin Collection
// Task:
// Build Coin, Country, and CoinCollection classes
// Track catalog value and issue year
// Methods: getTotalValue(), getTotalValueDecade(int decade)
class Coin {
public:
    int year;
    double value;
    string country;
};

void testCoins() {
    vector<Coin> coins = {{1990, 10, "DK"}, {1995, 20, "DK"}, {2001, 5, "SE"}};
    double total = 0;
    for (auto& c : coins) total += c.value;
    cout << "Total value: " << total << endl;

    int decade = 1990;
    double decadeValue = 0;
    for (auto& c : coins) if (c.year / 10 * 10 == decade) decadeValue += c.value;
    cout << "Value in 1990s: " << decadeValue << endl;
}

// Exercise 6: Værksted Simulation
// Task:
// Implement: Vaerksted, Bil, Mekaniker, ArbejdsSeddel
// Methods: ingenRegning() – customers with no work,
// mekanikerTimer() – total hours per mechanic,
// senesteArbejde() – most recent date
class ArbejdsSeddel {
public:
    string dato;
    int timer;
};

class Mekaniker {
public:
    string navn;
    vector<ArbejdsSeddel> sedler;
};

void testVaerksted() {
    Mekaniker m = {"Ole", {{"2024-05-01", 3}, {"2024-05-03", 5}}};
    int total = 0;
    for (auto& s : m.sedler) total += s.timer;
    cout << "Timer for " << m.navn << ": " << total << endl;
}

// Exerise 7: Final Review Checklist
// For each concept below, write one quick test or comment on it:
// new / delete, const correctness, Class with private members and getters/setters,
// Virtual method with override, File parsing with ifstream,
// vector<Animal*> polymorphism, Template function or class
void testReviewChecklist() {
    int* p = new int(5); delete p; // new/delete
    const int x = 10; // const
    class Test { int val = 42; public: int get() const { return val; } }; Test t; t.get(); // getters
    class Base { public: virtual void foo() {} }; class Derived : public Base { public: void foo() override {} }; Derived d; d.foo(); // virtual/override
    ifstream f("file.txt"); // file
    vector<Animal*> zoo; zoo.push_back(new Dog()); for (auto a : zoo) a->speak(); for (auto a : zoo) delete a; // polymorphism
    findMax(3, 5); // template
}

// === Menu ===
int main() {
    int choice;
    do {
        cout << "\n=== Day 4: Full Projects, Operator Overloading & Review ===\n";
        cout << "1. Broek Operator Overload\n";
        cout << "2. Kunstsamling System\n";
        cout << "3. CPR Number Class\n";
        cout << "4. Aktivitet File I/O\n";
        cout << "5. Coin Collection\n";
        cout << "6. Værksted Simulation\n";
        cout << "7. Final Review Checklist\n";
        cout << "0. Exit\n";
        cout << "Choose an exercise: ";
        cin >> choice;
        switch (choice) {
            case 1: testBroek(); break;
            case 2: testKunstSamling(); break;
            case 3: testCpr(); break;
            case 4: testAktivitet(); break;
            case 5: testCoins(); break;
            case 6: testVaerksted(); break;
            case 7: testReviewChecklist(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n"; break;
        }
    } while (choice != 0);
    return 0;
}
