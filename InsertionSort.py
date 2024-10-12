def insertion_sort(arr):
    # Traverse through 1 to len(arr)
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1

        # Move elements greater than key to one position ahead of their current position
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1

        arr[j + 1] = key

        # Print the array after each pass
        print(f"After pass {i}: {arr}")

# Example usage
arr = [10, 3, 8, 15, 6, 12, 2]
print("Original array:", arr)
print("\nSorting process:")
insertion_sort(arr)
print("\nSorted array:", arr)

"""
    Insertion Sort Example:
    Original array: [10, 3, 8, 15, 6, 12, 2]

    Sorting Process:
    - Pass 1: [3, 10, 8, 15, 6, 12, 2]
    - Pass 2: [3, 8, 10, 15, 6, 12, 2]
    - Pass 3: [3, 8, 10, 15, 6, 12, 2]
    - Pass 4: [3, 6, 8, 10, 15, 12, 2]
    - Pass 5: [3, 6, 8, 10, 12, 15, 2]
    - Pass 6: [2, 3, 6, 8, 10, 12, 15]

    Time Complexity:
    Best: O(n)
    Average/Worst: O(n^2)
"""
