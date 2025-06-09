#include "Classroom.h"
#include <sstream>
#include <iostream>

int main() {
    Classroom classroom;

    //Simulated quiz data: "name" username points weight ...
    std::stringstream input(
        "\"Alice Smith\" alicex 85 30.0 90 40.0 78 30.0\n"
        "\"Bob Jones\" bobj 88 25.0 76 35.0 92 40.0\n"
        "\"Charlie Lee\" charliel 100 20.0 95 30.0 60 50.0\n"
    );

    //Load data and print report
    classroom.loadFromStream(input);
    classroom.printReport();

    return 0;
}
