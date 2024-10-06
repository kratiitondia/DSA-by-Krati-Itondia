#include <iostream>
#include <vector>
#include <algorithm>

// Counting Sort function
void countingSort(std::vector<int>& arr) {
    if (arr.empty()) return;

    // Step 1: Find the maximum value in the array
    int max_val = *std::max_element(arr.begin(), arr.end());

    // Step 2: Create a count array to store the frequency of each element
    std::vector<int> count(max_val + 1, 0);

    // Count the occurrences of each value in the original array
    for (int num : arr) {
        count[num]++;
    }

    // Step 3: Reconstruct the sorted array using the count array
    int index = 0;
    for (int i = 0; i <= max_val; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }

    // Print the sorted array for better understanding
    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// Example usage
int main() {
    std::vector<int> arr = {4, 2, 2, 8, 3, 3, 1};

    std::cout << "Original array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    countingSort(arr);

    return 0;
}

/*
    Detailed Step-by-Step Example:
    Original array: [4, 2, 2, 8, 3, 3, 1]

    Step 1: Find the maximum value
    - Maximum value in array = 8

    Step 2: Initialize count array
    - Count array of size 9 initialized: [0, 0, 0, 0, 0, 0, 0, 0, 0]

    Step 3: Count occurrences of each element
    - After counting: [0, 1, 2, 0, 1, 0, 0, 0, 1]
      Explanation:
      - Value 1 occurs once.
      - Value 2 occurs twice.
      - Value 3 occurs twice.
      - Value 4 occurs once.
      - Value 8 occurs once.

    Step 4: Reconstruct sorted array
    - Traverse the count array and reconstruct:
    - Sorted array: [1, 2, 2, 3, 3, 4, 8]

    Time Complexity: O(n + k)
    Space Complexity: O(k)
*/
