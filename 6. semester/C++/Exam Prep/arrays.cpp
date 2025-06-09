#include <iostream>
#include <vector>
#include <algorithm>

// Exercise 1: Find the largest element in an array
int findStoersteTal(const std::vector<int>& arr) {
    if (arr.empty()) {
        return 0; // Or throw an exception for an empty array
    }
    return *std::max_element(arr.begin(), arr.end());
}

// Exercise 2: Reverse an array
std::vector<int> vendArray(std::vector<int> arr) {
    std::reverse(arr.begin(), arr.end());
    return arr;
}

// Exercise 3: Sum of even numbers in an array
int sumAfLigeTal(const std::vector<int>& arr) {
    int sum = 0;
    for (int num : arr) {
        if (num % 2 == 0) {
            sum += num;
        }
    }
    return sum;
}

// Exercise 4: Count occurrences of a number
int taelForekomster(const std::vector<int>& arr, int target) {
    int count = 0;
    for (int num : arr) {
        if (num == target) {
            count++;
        }
    }
    return count;
}

// Exercise 5: Check if an array is sorted (ascending)
bool erSorteret(const std::vector<int>& arr) {
    if (arr.size() <= 1) {
        return true; // Empty or single-element arrays are sorted
    }
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

// Exercise 6: Check if two numbers in a sorted array sum to a third
bool sumAfToTal(const std::vector<int>& arr, int x) {
    if (arr.size() < 2) {
        return false;
    }
    size_t left = 0;
    size_t right = arr.size() - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == x) {
            return true;
        } else if (sum < x) {
            left++;
        } else {
            right--;
        }
    }
    return false;
}

int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    std::vector<int> arr(n);
    std::cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    // Example usage for each exercise
    std::cout << "Largest element: " << findStoersteTal(arr) << std::endl;

    std::vector<int> reversed = vendArray(arr);
    std::cout << "Reversed array: ";
    for (int num : reversed) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Sum of even numbers: " << sumAfLigeTal(arr) << std::endl;

    int target;
    std::cout << "Enter the number to count: ";
    std::cin >> target;
    std::cout << "Count of " << target << ": " << taelForekomster(arr, target) << std::endl;

    std::cout << "Array is sorted: " << std::boolalpha << erSorteret(arr) << std::endl;

    int x;
    std::cout << "Enter the target sum: ";
    std::cin >> x;
    std::cout << "Two numbers sum to " << x << ": " << std::boolalpha << sumAfToTal(arr, x) << std::endl;

    return 0;
}