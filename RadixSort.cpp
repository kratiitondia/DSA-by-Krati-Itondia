#include <iostream>
#include <vector>
#include <algorithm>

// Function to get the maximum value in the array
int getMax(const std::vector<int>& arr) {
    return *std::max_element(arr.begin(), arr.end());
}

// Counting Sort used in Radix Sort to sort based on digit position
void countingSortForRadix(std::vector<int>& arr, int exp) {
    int n = arr.size();
    std::vector<int> output(n);
    int count[10] = {0};

    // Count occurrences of each digit at the current place value
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Update count array for actual positions
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy the sorted values back into the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Radix Sort function
void radixSort(std::vector<int>& arr) {
    // Find the maximum value to determine the number of digits
    int max_val = getMax(arr);

    // Apply counting sort to sort elements based on each digit
    for (int exp = 1; max_val / exp > 0; exp *= 10) {
        countingSortForRadix(arr, exp);

        // Print the array after sorting each digit for better understanding
        std::cout << "Array after sorting by digit at place " << exp << ": ";
        for (int num : arr) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

// Example usage
int main() {
    std::vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    std::cout << "Original array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    radixSort(arr);

    return 0;
}

/*
    Detailed Step-by-Step Example:
    Original array: [170, 45, 75, 90, 802, 24, 2, 66]

    Step 1: Sort by the least significant digit (exp = 1)
    - Counting sort by unit place
    - Array after sorting: [170, 90, 802, 2, 24, 45, 75, 66]

    Step 2: Sort by the tens place (exp = 10)
    - Counting sort by tens place
    - Array after sorting: [802, 2, 24, 45, 66, 170, 75, 90]

    Step 3: Sort by the hundreds place (exp = 100)
    - Counting sort by hundreds place
    - Array after sorting: [2, 24, 45, 66, 75, 90, 170, 802]

    Time Complexity: O(nk)
    Space Complexity: O(n + k)
*/
