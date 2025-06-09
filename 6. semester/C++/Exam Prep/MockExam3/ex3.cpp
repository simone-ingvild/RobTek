#include <iostream>
#include <climits>

//Returns the smallest common element in two arrays of the same size.
//Returns -1 if no common element is found.
int smallestCommonElement(int arr1[], int arr2[], int size) {
    int minCommon = INT_MAX;

    //Compare every element in arr1 with every element in arr2
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (arr1[i] == arr2[j] && arr1[i] < minCommon) {
                minCommon = arr1[i]; //Update minimum if common and smaller
            }
        }
    }

    //Return -1 if no common element was found
    return (minCommon == INT_MAX) ? -1 : minCommon;
}

int main() {
    //Test arrays
    int arr1[] = {5, 1, 7, 3, 9};
    int arr2[] = {4, 3, 8, 2, 1};
    int size = 5;

    //Call the function
    int result = smallestCommonElement(arr1, arr2, size);

    //Print the result
    if (result != -1) {
        std::cout << "The smallest common element is: " << result << "\n";
    } else {
        std::cout << "There is no common element.\n";
    }

    //Optional additional test case
    int a[] = {10, 20, 30};
    int b[] = {40, 50, 60};
    std::cout << "Test with no common elements: ";
    std::cout << smallestCommonElement(a, b, 3) << "\n"; // Should print -1

    return 0;
}
