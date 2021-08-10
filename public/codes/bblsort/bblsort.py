# Python program for Bubble Sort

def bubbleSort(arr):
    n = len(arr)

    # Traverse through all array elements
    for i in range(n):

        # Last i elements are already in place
        for j in range(0, n-i-1):

            # traverse the array from 0 to n-i-1
            # Swap if the element found is greater
            # than the next element
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]


# Driver code to test above
arr = [100, 1, 10, -1, 0]

bubbleSort(arr)

print("The array after running bubble sort is : ", end="")
print(arr)

# Output :
# The array after running bubble sort is : [-1, 0, 1, 10, 100]
