#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

// Helper to check if a, b, c is a Pythagorean triplet
bool isPythagoreanTriplet(int a, int b, int c) {
    return (a * a + b * b == c * c);
}

std::vector<int> removePythagoreanTriplets(const std::vector<int>& input) {
    std::vector<int> result = input;
    std::sort(result.begin(), result.end());

    std::vector<bool> toRemove(result.size(), false);

    for (size_t i = 0; i < result.size(); ++i) {
        for (size_t j = i + 1; j < result.size(); ++j) {
            for (size_t k = j + 1; k < result.size(); ++k) {
                if (isPythagoreanTriplet(result[i], result[j], result[k])) {
                    toRemove[i] = toRemove[j] = toRemove[k] = true;
                }
            }
        }
    }

    std::vector<int> filtered;
    for (size_t i = 0; i < result.size(); ++i) {
        if (!toRemove[i]) {
            filtered.push_back(result[i]);
        }
    }
    return filtered;
}

int main() {
    // Opgave 2 demo
    std::vector<int> nums = {6, 25, 5, 3, 7, 24, 4, 23};
    std::vector<int> noTriplets = removePythagoreanTriplets(nums);
    std::cout << "Without Pythagorean Triplets: ";
    for (int n : noTriplets) std::cout << n << " ";
    std::cout << "\n";

    return 0;
}