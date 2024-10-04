#include <iostream>
#include <vector>

// Function to merge two halves of the array
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    std::vector<int> L(n1), R(n2);

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    // Merge the temp arrays back into arr[left..right]
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements of L[]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy any remaining elements of R[]
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge Sort function
void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Recursively sort the two halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);

        // Print the array after merging each time for better understanding
        std::cout << "Merged array: ";
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
    mergeSort(arr, 0, arr.size() - 1);

    std::cout << "\nSorted array: ";
    printArray(arr);

    return 0;
}

/*
    Merge Sort Example:
    Original array: [12, 11, 13, 5, 6, 7]

    Sorting Process:
    - After merging: [11, 12, 13, 5, 6, 7]
    - After merging: [5, 6, 7, 11, 12, 13]

    Time Complexity: O(n log n)
    Space Complexity: O(n) (Due to temporary arrays for merging)
*/
