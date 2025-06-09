#include "Student.h"

// Default constructor
Student::Student() = default;

// Constructor with name and username
Student::Student(const std::string& name, const std::string& username)
    : mName(name), mUsername(username) {}

// Draw a ticket from the bin
void Student::draw(Bin& bin)
{
    mExam = bin.drawAndRemove();
}

// Map stored ticket to an exam name
std::string Student::getExam(const std::vector<std::string>& exams) const
{
    return (mExam >= 0 && static_cast<std::size_t>(mExam) < exams.size())
           ? exams[mExam]
           : "Unknown";
}

// ---------- Getters / setters ----------
std::string Student::getName() const                 { return mName; }
void        Student::setName(const std::string& n)   { mName = n; }

std::string Student::getUsername() const             { return mUsername; }
void        Student::setUsername(const std::string& u){ mUsername = u; }

// Stream insertion (prints: Name (username))
std::ostream& operator<<(std::ostream& os, const Student& s)
{
    return os << s.mName << " (" << s.mUsername << ")";
}
