# Python program for Insertion Sort

# Function to do insertion sort
def insertionSort(arr):

    # Traverse through 1 to len(arr)
    for i in range(1, len(arr)):

        key = arr[i]

        # Move elements of arr[0..i-1], that are
        # greater than key, to one position ahead
        # of their current position
        j = i-1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key


# Driver code to test above
arr = [100, 1, 10, -1, 0]

insertionSort(arr)

print("The array after running insertion sort is : ", end="")
print(arr)

# Output :
# The array after running insertion sort is : [-1, 0, 1, 10, 100]
