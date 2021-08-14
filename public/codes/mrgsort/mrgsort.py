# Python program for implementation of MergeSort

# Merges two subarrays of array[].
# First subarray is array[begin..mid]
# Second subarray is array[mid+1..right]
def merge(array, left, mid, right):
    subArrayOne = mid - left + 1
    subArrayTwo = right - mid

    # create temp arrays
    leftArray = [0] * subArrayOne
    rightArray = [0] * subArrayTwo

    # Copy data to temp arrays leftArray[] and rightArray[]
    for i in range(0, subArrayOne):
        leftArray[i] = array[left + i]

    for j in range(0, subArrayTwo):
        rightArray[j] = array[mid + 1 + j]

    indexofSubArrayOne = 0	 # Initial index of first subarray
    indexofSubArrayTwo = 0	 # Initial index of second subarray
    indexOfMergedArray = left	 # Initial index of merged subarray
# Merge the temp arrays back into array[left..right]
    while indexofSubArrayOne < subArrayOne and indexofSubArrayTwo < subArrayTwo:
        if leftArray[indexofSubArrayOne] <= rightArray[indexofSubArrayTwo]:
            array[indexOfMergedArray] = leftArray[indexofSubArrayOne]
            indexofSubArrayOne += 1
        else:
            array[indexOfMergedArray] = rightArray[indexofSubArrayTwo]
            indexofSubArrayTwo += 1
        indexOfMergedArray += 1

    # Copy the remaining elements of L[], if there
    # are any
    while indexofSubArrayOne < subArrayOne:
        array[indexOfMergedArray] = leftArray[indexofSubArrayOne]
        indexofSubArrayOne += 1
        indexOfMergedArray += 1

    # Copy the remaining elements of R[], if there
    # are any
    while indexofSubArrayTwo < subArrayTwo:
        array[indexOfMergedArray] = rightArray[indexofSubArrayTwo]
        indexofSubArrayTwo += 1
        indexOfMergedArray += 1

# begin is for left index and end is right index of the
# sub-array of arr to be sorted


def mergeSort(array, begin, end):
    if (begin < end):
        mid = (begin+end)//2

        # Sort first and second halves
        mergeSort(array, begin, mid)
        mergeSort(array, mid+1, end)
        merge(array, begin, mid, end)


# Driver code to test above
arr = [100, 1, 10, -1, 0]
n = 5

mergeSort(arr, 0, n-1)
print("The array after running merge sort is : ", end="")
print(arr)

# Output :
# The array after running merge sort is : [-1, 0, 1, 10, 100]
