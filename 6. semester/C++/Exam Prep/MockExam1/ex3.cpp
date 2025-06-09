#include <iostream>
#include <algorithm> 

// Function to find and return the sum of the largest elements in two arrays
int sumOfTwoLargest(int arr1[], int arr2[], int size) {
    // Defensive check in case of invalid input
    if (size <= 0) return 0;

    // Initialize max values with the first element of each array
    int max1 = arr1[0];
    int max2 = arr2[0];

    // Traverse both arrays to find the maximum in each
    for (int i = 1; i < size; ++i) {
        if (arr1[i] > max1) max1 = arr1[i];
        if (arr2[i] > max2) max2 = arr2[i];
    }

    // Return the sum of the two maximum values
    return max1 + max2;
}

int main() {
    // Example input arrays (both must have the same size)
    int arr1[] = {3, 8, 2, 5};  // max = 8
    int arr2[] = {7, 1, 4, 6};  // max = 7

    // Calculate the number of elements
    int size = sizeof(arr1) / sizeof(arr1[0]);

    // Call the function and print the result
    int result = sumOfTwoLargest(arr1, arr2, size);
    std::cout << "Sum of largest elements: " << result << std::endl;

    return 0;
}
