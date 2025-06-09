// main.cpp
#include <iostream>
#include <sstream>
#include "gradebook.h"

int main() {
    Gradebook gb;

    // Simulated input stream with user data
    std::stringstream input(
        "alice 100 2.5 80 5.0 95 45.0\n"
        "bob 88 20.0 92 30.0 70 50.0\n"
    );

    gb.readFromStream(input); // Load data from stream
    gb.printReport();         // Output results

    return 0;
}