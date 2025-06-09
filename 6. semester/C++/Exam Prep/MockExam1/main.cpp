#include "course_lottery.h"
#include <iostream>

int main() {
    // Create a CourseLottery object with a fixed seed for reproducibility
    CourseLottery lottery(2024);  // Reproducible seed

    // Add students to the lottery
    lottery.addStudent("Hans Hansen", "hahan20");
    lottery.addStudent("Greta Grevsen", "grgr21");
    lottery.addStudent("Ole Olsen", "olol22");

    // Define subjects for each round
    std::vector<std::string> round1 = {"PLC", "OOP"};
    std::vector<std::string> round2 = {"RSI", "IIC"};

    // Run the lottery to assign subjects to students
    lottery.runLottery(round1, round2);

    // Output the results to the console
    lottery.printResults(std::cout);

    return 0;
}
