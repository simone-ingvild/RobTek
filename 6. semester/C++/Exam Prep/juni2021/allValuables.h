#ifndef ALLVALUABLES_H
#define ALLVALUABLES_H

#include <vector>
#include <iostream>
#include "valuable.h"

// Class that manages a collection of Valuable items
class AllValuables {
private:
    std::vector<Valuable*> items; // Collection of pointers to Valuable objects

public:
    // Add a Valuable to the collection
    void add(Valuable& valuable) {
        items.push_back(&valuable);
    }

    // Calculate the total value of all items
    double getValue() const {
        double sum = 0.0;
        for (auto* item : items) {
            sum += item->getValue();
        }
        return sum;
    }

    // Print the name and value of each item, and the total value
    void printAll() const {
        for (auto* item : items) {
            std::cout << item->getName() << ", " 
                      << static_cast<int>(item->getValue()) << std::endl;
        }
        std::cout << "Total: " << static_cast<int>(getValue()) << std::endl;
    }
};

#endif // ALLVALUABLES_H
