#include <iostream>
#include <vector>

void selectionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;

        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            std::swap(arr[i], arr[minIndex]);
        }

        std::cout << "After pass " << i + 1 << ": ";
        for (int k : arr) {
            std::cout << k << " ";
        }
        std::cout << std::endl;
    }
}

void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {29, 10, 14, 37, 14, 5, 7};

    std::cout << "Original array: ";
    printArray(arr);

    std::cout << "\nSorting process:\n";
    selectionSort(arr);

    std::cout << "\nSorted array: ";
    printArray(arr);

    return 0;
}

/*
    Selection Sort Algorithm:
    - Time Complexity:
      Best Case: O(n^2) -> Even if the array is sorted, Selection Sort compares each element.
      Average Case: O(n^2) -> Random order of elements.
      Worst Case: O(n^2) -> The array is sorted in reverse order.
    - Space Complexity: O(1) -> In-place sorting.

    Example:
    Original array: 29, 10, 14, 37, 14, 5, 7

    Sorting Process:
    - Pass 1: [5, 10, 14, 37, 14, 29, 7]
      -> The minimum element (5) is swapped with the first element (29).
    - Pass 2: [5, 7, 14, 37, 14, 29, 10]
      -> The minimum element (7) from the remaining unsorted portion is swapped with 10.
    - Pass 3: [5, 7, 10, 37, 14, 29, 14]
      -> The minimum element (10) is already at the correct position.
    - Pass 4: [5, 7, 10, 14, 37, 29, 14]
      -> The minimum element (14) is swapped with 37.
    - Pass 5: [5, 7, 10, 14, 14, 29, 37]
      -> The minimum element (14) is already at the correct position.
    - Pass 6: [5, 7, 10, 14, 14, 29, 37]
      -> The minimum element (29) is already at the correct position.

    Use Cases:
    - Selection Sort is simple and has performance close to Bubble Sort.
    - It can be useful for small datasets or when memory write operations need to be minimized.
*/
/*by harsh*/
