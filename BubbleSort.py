
def bubble_sort(arr):
    n = len(arr)

    # Traverse through all array elements
    for i in range(n - 1):
        swapped = False

        # Traverse the array from 0 to n-i-1
        # Swap if the element found is greater than the next element
        for j in range(n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True

        # Print the array after each pass
        print(f"After pass {i + 1}: {arr}")

        # If no elements were swapped, then the array is already sorted
        if not swapped:
            break

# Example usage
arr = [64, 25, 12, 22, 11]
print("Original array:", arr)
print("\nSorting process:")
bubble_sort(arr)
print("\nSorted array:", arr)

""" By Harsh:
    Bubble Sort Example:
    Original array: [64, 25, 12, 22, 11]

    Sorting Process:
    - Pass 1: [25, 12, 22, 11, 64]
    - Pass 2: [12, 22, 11, 25, 64]
    - Pass 3: [12, 11, 22, 25, 64]
    - Pass 4: [11, 12, 22, 25, 64]

    Time Complexity:
    Best: O(n) (Already sorted array)
    Average/Worst: O(n^2)
"""
