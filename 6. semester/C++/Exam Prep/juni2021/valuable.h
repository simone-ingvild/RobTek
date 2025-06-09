#ifndef VALUABLE_H
#define VALUABLE_H

#include <string>

// Abstract base class representing a valuable item
class Valuable {
private:
    std::string name;  // Name of the item
    double value;      // Monetary value of the item

public:
    // Constructor to initialize name and value
    Valuable(const std::string& name, double value)
        : name(name), value(value) {}

    // Virtual destructor to allow proper cleanup in derived classes
    virtual ~Valuable() {}

    // Getter for the value
    virtual double getValue() const {
        return value;
    }

    // Getter for the name
    virtual std::string getName() const {
        return name;
    }
};

#endif // VALUABLE_H
