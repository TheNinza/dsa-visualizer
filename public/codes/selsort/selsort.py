# Python program for selection sort

def selectionSort(arr):

    # One by one move boundary of unsorted subarray
    for i in range(len(arr)-1):
        # Find the minimum element in unsorted array
        min_idx = i
        for j in range(i+1, len(arr)):
            if arr[j] < arr[min_idx]:
                min_idx = j

        # Swap the found minimum element with
        # the first element
        arr[i], arr[min_idx] = arr[min_idx], arr[i]


# Driver code to test above
arr = [100, 1, 10, -1, 0]

selectionSort(arr)

print("The array after running selection sort is : ", end="")
print(arr)

# Output :
# The array after running selection sort is : [-1, 0, 1, 10, 100]
