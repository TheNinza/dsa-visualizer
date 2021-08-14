# Python3 program for QuickSort

# This function takes last element as pivot, places
# the pivot element at its correct position in sorted
# array, and places all smaller (smaller than pivot)
# to left of pivot and all greater elements to right
# of pivot
def partition(arr, low, high):
    pivot = arr[high]  # pivot
    # Index of smaller element and indicates the right position of pivot found so far
    i = (low - 1)

    for j in range(low, high):
        # If current element is smaller than the pivot
        if arr[j] < pivot:
            i += 1  # increment index of smaller element
            arr[i], arr[j] = arr[j], arr[i]
    arr[i+1], arr[high] = arr[high], arr[i+1]
    return (i + 1)


# The main function that implements QuickSort
# arr[] --> Array to be sorted,
# low --> Starting index,
# high --> Ending index
def quick_sort(arr, low, high):

    if (low < high):

        # p is partitioning index, array[p]
        # is at right place
        p = partition(arr, low, high)

        # Separately sort elements before partition
        # and after partition
        quick_sort(arr, low, p - 1)
        quick_sort(arr, p + 1, high)


# Driver code to test above
arr = [100, 1, 10, -1, 0]
quick_sort(arr, 0, len(arr) - 1)

print("The array after running QuickSort is : ", end="")
print(arr)

# Output :
# The array after running QuickSort is : [-1, 0, 1, 10, 100]
