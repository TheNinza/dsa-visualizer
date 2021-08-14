// C program for Bubble Sort
#include <stdio.h>

// Function to sort an array using bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            //Swap if the element found is greater
            //than the next element
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
    int i;
    printf("The array after running bubble sort is : [");
    for (i = 0; i < n - 1; i++)
        printf("%d, ", arr[i]);
    printf("%d]\n", arr[n - 1]);
}

// Driver code
int main()
{
    int arr[] = {100, 1, 10, -1, 0};
    int n = 5;

    bubbleSort(arr, n);
    printArray(arr, n);

    return 0;
}

// Output :
// The array after running bubble sort is : [-1, 0, 1, 10, 100]
