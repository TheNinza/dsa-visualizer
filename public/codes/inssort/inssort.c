// C program for Insertion Sort
#include <stdio.h>

// Function to sort an array using insertion sort
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (j = 1; j < n; j++)
    {
        key = arr[j];
        i = j - 1;

        /* Move elements of arr[0..j-1], that are
		greater than key, to one position ahead
		of their current position */
        while (i >= 0 && arr[i] > key)
        {
            arr[i + 1] = arr[i];
            i = i - 1;
        }
        arr[i + 1] = key;
    }
}

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
    int i;
    printf("The array after running insertion sort is : [");
    for (i = 0; i < n - 1; i++)
        printf("%d, ", arr[i]);
    printf("%d]\n", arr[n - 1]);
}

// Driver code
int main()
{
    int arr[] = {100, 1, 10, -1, 0};
    int n = 5;

    insertionSort(arr, n);
    printArray(arr, n);

    return 0;
}

// Output :
// The array after running insertion sort is : [-1, 0, 1, 10, 100]
