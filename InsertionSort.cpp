#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Move elements that are greater than key one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;

        // Print the array after each pass for better understanding
        std::cout << "After pass " << i << ": ";
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
    std::vector<int> arr = {10, 3, 8, 15, 6, 12, 2};

    std::cout << "Original array: ";
    printArray(arr);


    std::cout << "\nSorting process:\n";
    insertionSort(arr);

    std::cout << "\nSorted array: ";
    printArray(arr);

    return 0;
}

/*
    Insertion Sort Algorithm:
    - Time Complexity:
      Best Case: O(n) -> The array is already sorted.
      Average Case: O(n^2) -> Random order of elements.
      Worst Case: O(n^2) -> The array is sorted in reverse order.
    - Space Complexity: O(1) -> In-place sorting.

    Example:
    Original array: 10, 3, 8, 15, 6, 12, 2

    Sorting Process:
    - Pass 1: [3, 10, 8, 15, 6, 12, 2]
      -> Inserted 3 in the correct position before 10.
    - Pass 2: [3, 8, 10, 15, 6, 12, 2]
      -> Inserted 8 in the correct position between 3 and 10.
    - Pass 3: [3, 8, 10, 15, 6, 12, 2]
      -> 15 is already in the correct position.
    - Pass 4: [3, 6, 8, 10, 15, 12, 2]
      -> Inserted 6 in the correct position before 10 and 15.
    - Pass 5: [3, 6, 8, 10, 12, 15, 2]
      -> Inserted 12 in the correct position before 15.
    - Pass 6: [2, 3, 6, 8, 10, 12, 15]
      -> Inserted 2 in the first position.

    Use Cases:
    - Suitable for small datasets or partially sorted arrays.
    - Efficient when the array size is small.
*/
