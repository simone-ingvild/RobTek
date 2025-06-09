#include "bin.h"
#include <algorithm>

// Constructor: initializes random number generator with seed
Bin::Bin(unsigned int seed) : rng(seed) {}

// Fills the bin fairly with repeated elements and shuffles
void Bin::fillEvenly(const std::vector<std::string>& elements, int totalSlots) {
    items.clear();
    int n = elements.size();
    for (int i = 0; i < totalSlots; ++i) {
        items.push_back(elements[i % n]);
    }
    std::shuffle(items.begin(), items.end(), rng);
}

// Draws an item from the back of the bin
std::string Bin::draw() {
    if (items.empty()) return "";
    std::string value = items.back();
    items.pop_back();
    return value;
}

// Checks if bin is empty
bool Bin::empty() const {
    return items.empty();
}
