#include <iostream>
#include <unordered_set>

//Returns the number of common elements between two arrays of equal size
int commonElements(int arr1[], int arr2[], int size) {
    std::unordered_set<int> set1;
    std::unordered_set<int> seen;
    int count = 0;

    //Insert all elements from arr1 into a set
    for (int i = 0; i < size; ++i) {
        set1.insert(arr1[i]);
    }

    //Check which elements from arr2 are in set1 (no duplicates)
    for (int i = 0; i < size; ++i) {
        if (set1.count(arr2[i]) && !seen.count(arr2[i])) {
            seen.insert(arr2[i]);
            count++;
        }
    }

    return count;
}

int main() {
    int arr1[] = {5, 1, 3, 7, 9};
    int arr2[] = {2, 3, 1, 4, 9};
    int size = 5;

    std::cout << "Common elements: " << commonElements(arr1, arr2, size) << std::endl;

    return 0;
}
