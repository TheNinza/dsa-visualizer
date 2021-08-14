// C program for selection sort
#include <stdio.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
    int i;
    printf("The array after running selection sort is : [");
    for (i = 0; i < n - 1; i++)
        printf("%d, ", arr[i]);
    printf("%d]\n", arr[n - 1]);
}

// Driver code
int main()
{
    int arr[] = {100, 1, 10, -1, 0};
    int n = 5;

    selectionSort(arr, n);
    printArray(arr, n);

    return 0;
}

// Output :
// The array after running selection sort is : [-1, 0, 1, 10, 100]
