# Function to heapify a subtree rooted at index i
def heapify(arr, n, i):
    largest = i  # Initialize largest as root
    left = 2 * i + 1  # Left child index
    right = 2 * i + 2  # Right child index

    # See if left child exists and is greater than root
    if left < n and arr[left] > arr[largest]:
        largest = left

    # See if right child exists and is greater than the largest so far
    if right < n and arr[right] > arr[largest]:
        largest = right

    # Change root if needed
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]  # Swap

        # Heapify the root again
        heapify(arr, n, largest)

# Heap Sort function
def heap_sort(arr):
    n = len(arr)

    # Build a max heap
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

    # Extract elements one by one from the heap
    for i in range(n - 1, 0, -1):
        # Move current root to the end
        arr[i], arr[0] = arr[0], arr[i]

        # Call max heapify on the reduced heap
        heapify(arr, i, 0)

        # Print the array after each extraction for better understanding
        print(f"Heap after removing max element: {arr}")

# Example usage
arr = [12, 11, 13, 5, 6, 7]

print("Original array:", arr)
print("\nSorting process:")
heap_sort(arr)

print("\nSorted array:", arr)

"""
    Heap Sort Example:
    Original array: [12, 11, 13, 5, 6, 7]

    Sorting Process:
    - Heap after removing max element: [11, 7, 13, 5, 6, 12]
    - Heap after removing max element: [7, 6, 13, 5, 11, 12]
    - ...

    Time Complexity: O(n log n)
    Space Complexity: O(1) (In-place sorting)
"""
