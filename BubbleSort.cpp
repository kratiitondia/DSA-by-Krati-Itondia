#include <iostream>
#include <vector>

// Function to perform Bubble Sort
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    bool swapped;

    for (int i = 0; i < n - 1; ++i) {
        swapped = false;

        // Traverse through all elements in the unsorted portion of the array
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Swap if the element is greater than the next element
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // Print the array after each pass for better understanding
        std::cout << "After pass " << i + 1 << ": ";
        for (int k : arr) {
            std::cout << k << " ";
        }
        std::cout << std::endl;

        // If no two elements were swapped in the inner loop, break (the array is sorted)
        if (!swapped) {
            break;
        }
    }
}

void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {64, 25, 12, 22, 11};

    std::cout << "Original array: ";
    printArray(arr);

    std::cout << "\nSorting process:\n";
    bubbleSort(arr);

    std::cout << "\nSorted array: ";
    printArray(arr);

    return 0;
}
/*By Harsh*/
/*
    Bubble Sort Algorithm:
    - Time Complexity:
      Best Case: O(n) -> The array is already sorted.
      Average Case: O(n^2) -> Random order of elements.
      Worst Case: O(n^2) -> The array is sorted in reverse order.
    - Space Complexity: O(1) -> In-place sorting.

    Example:
    Original array: 64, 25, 12, 22, 11

    Sorting Process:
    - Pass 1: [25, 12, 22, 11, 64]
      -> The largest element (64) is "bubbled" to the last position.
    - Pass 2: [12, 22, 11, 25, 64]
      -> The second largest element (25) is bubbled to its correct position.
    - Pass 3: [12, 11, 22, 25, 64]
      -> The next largest element (22) is bubbled to its correct position.
    - Pass 4: [11, 12, 22, 25, 64]
      -> The elements are now in sorted order.

    Use Cases:
    - Bubble Sort is simple to implement and understand.
    - Not suitable for large datasets due to its O(n^2) complexity.
    - Useful for educational purposes and understanding sorting concepts.
*/
