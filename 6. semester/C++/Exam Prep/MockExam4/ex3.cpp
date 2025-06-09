#include <iostream>
#include <limits>

//Returns the second largest element in the array
int secondLargest(int arr[], int size) {
    if (size < 2) return -1; // Not enough elements

    int max = std::numeric_limits<int>::min();
    int second = std::numeric_limits<int>::min();

    for (int i = 0; i < size; ++i) {
        if (arr[i] > max) {
            second = max;
            max = arr[i];
        } else if (arr[i] > second && arr[i] < max) {
            second = arr[i];
        }
    }

    return (second == std::numeric_limits<int>::min()) ? -1 : second;
}

int main() {
    int arr[] = {42, 11, 23, 87, 59};
    int size = sizeof(arr) / sizeof(arr[0]);

    int result = secondLargest(arr, size);
    if (result != -1) {
        std::cout << "Second largest value is: " << result << std::endl;
    } else {
        std::cout << "No second largest value found.\n";
    }

    return 0;
}
