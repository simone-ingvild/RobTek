#include "student.h"
#include <iomanip>

using namespace std;

// Constructor: initializes name and username
Student::Student(const string& name, const string& username): name(name), username(username) {}

// Set the first exam
void Student::setExam1(const string& exam) {exam1 = exam;}

// Set the second exam
void Student::setExam2(const string& exam) {exam2 = exam;}

// Print student information in formatted columns
void Student::print(ostream& os) const {
    os << std::left << std::setw(18) << name
       << std::setw(12) << username
       << std::setw(8) << exam1
       << exam2 << "\n";
}
