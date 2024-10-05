#include <iostream>
#include <vector>

// Function to heapify a subtree rooted at node i, which is an index in arr[]
void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // Left child
    int right = 2 * i + 2; // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than the largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root
    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Heap Sort function
void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        std::swap(arr[0], arr[i]);

        // Call heapify on the reduced heap
        heapify(arr, i, 0);

        // Print the array after each extraction for better understanding
        std::cout << "Heap after removing max element: ";
        for (int x : arr) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
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
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};

    std::cout << "Original array: ";
    printArray(arr);

    std::cout << "\nSorting process:\n";
    heapSort(arr);

    std::cout << "\nSorted array: ";
    printArray(arr);

    return 0;
}

/*
    Heap Sort Example:
    Original array: [12, 11, 13, 5, 6, 7]

    Sorting Process:
    - Heap after removing max element: [11, 7, 6, 5, 12, 13]
    - Heap after removing max element: [7, 5, 6, 11, 12, 13]
    - ...

    Time Complexity: O(n log n)
    Space Complexity: O(1) (In-place sorting)
*/
