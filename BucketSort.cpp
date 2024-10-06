#include <iostream>
#include <vector>
#include <algorithm>

// Bucket Sort function
void bucketSort(std::vector<float>& arr) {
    int n = arr.size();
    if (n <= 0) return;

    // Step 1: Create n empty buckets
    std::vector<std::vector<float>> buckets(n);

    // Step 2: Put array elements into different buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = n * arr[i]; // Index in bucket
        buckets[bucketIndex].push_back(arr[i]);
    }

    // Step 3: Sort individual buckets
    for (int i = 0; i < n; i++) {
        std::sort(buckets[i].begin(), buckets[i].end());
    }

    // Step 4: Concatenate all sorted buckets into the original array
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (float value : buckets[i]) {
            arr[index++] = value;
        }
    }

    // Print the sorted array for better understanding
    std::cout << "Sorted array: ";
    for (float num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// Example usage
int main() {
    std::vector<float> arr = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};

    std::cout << "Original array: ";
    for (float num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    bucketSort(arr);

    return 0;
}

/*
    Detailed Step-by-Step Example:
    Original array: [0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434]

    Step 1: Create empty buckets
    - Number of buckets = 6 (same as number of elements)

    Step 2: Distribute elements into buckets
    - Bucket 0: [0.1234]
    - Bucket 2: [0.3434]
    - Bucket 3: [0.565, 0.656, 0.665]
    - Bucket 5: [0.897]

    Step 3: Sort each bucket
    - Sorted buckets:
      - Bucket 0: [0.1234]
      - Bucket 2: [0.3434]
      - Bucket 3: [0.565, 0.656, 0.665]
      - Bucket 5: [0.897]

    Step 4: Concatenate sorted buckets
    - Sorted array: [0.1234, 0.3434, 0.565, 0.656, 0.665, 0.897]

   
