#include <iostream>
#include <vector>

// Function to partition the array and return the pivot index
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choose the last element as pivot
    int i = low - 1; // Index of smaller element

    for (int j = low; j < high; j++) {
        // If the current element is less than or equal to the pivot
        if (arr[j] <= pivot) {
            i++; // Increment the index of smaller element
            std::swap(arr[i], arr[j]); // Swap elements
        }
    }
    
    // Swap the pivot element with the element at index (i + 1)
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Quick Sort function
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pi = partition(arr, low, high);

        // Print the array after each partition for better understanding
        std::cout << "Partition at index " << pi << ": ";
        for (int x : arr) {
            std::cout << x << " ";
        }
        std::cout << std::endl;

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Helper function to print the array
void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {10, 7, 8, 9, 1, 5};
    
    std::cout << "Original array: ";
    printArray(arr);

    std::cout << "\nSorting process:\n";
    quickSort(arr, 0, arr.size() - 1);

    std::cout << "\nSorted array: ";
    printArray(arr);

    return 0;
}

/*
    Quick Sort Example:
    Original array: [10, 7, 8, 9, 1, 5]

    Sorting Process:
    - Partition at index 3: [5, 7, 8, 9, 1, 10]
    - Partition at index 1: [1, 5, 7, 8, 9, 10]
    - Partition at index 5: [1, 5, 7, 8, 9, 10]

    Time Complexity:
    Best/Average: O(n log n)
    Worst: O(n^2) (Occurs when the array is already sorted or in reverse order, without proper pivoting)
    Space Complexity: O(log n) (Due to recursion stack)

    Description:
    - Quick Sort works by selecting a 'pivot' element from the array and partitioning
      the other elements into two sub-arrays according to whether they are less than or greater than the pivot.
    - This process is recursively applied to both sub-arrays.
    - The partition function ensures that the pivot is placed in its correct position, such that all elements to the left are smaller and all elements to the right are greater.
*/
