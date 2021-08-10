// C++ program for QuickSort
#include <iostream>
using namespace std;

// A utility function to swap two elements
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition (int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot
	int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot
		if (arr[j] < pivot)
		{
			i++; // increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* p is partitioning index, arr[p] is now
		at right place */
		int p = partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, p - 1);
		quickSort(arr, p + 1, high);
	}
}

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
    int i;
    cout << "The array after running QuickSort is : [";
    for (i = 0; i < n-1; i++)
        cout << arr[i] << ", ";
    cout << arr[n-1] << "]" << endl;
}

// Driver Code
int main()
{
	int arr[] = { 100, 1, 10, -1, 0 };
	int n = 5;
	
    quickSort(arr, 0, n - 1);
	printArray(arr, n);

	return 0;
}

// Output :
// The array after running QuickSort is : [-1, 0, 1, 10, 100]
