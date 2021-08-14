// C Program for insertion, deletion, traversal and searching in one dimentional array
#include <stdio.h>
#include <stdlib.h>

// structure to store array,capacity and size in one place
struct Array
{
    int *arr;
    int capacity;
    int size;
};

// initialises the structure by dynamic memory allocation
struct Array *createArray(int capacity)
{
    struct Array *array = (struct Array *)malloc(sizeof(struct Array));
    array->arr = (int *)malloc(sizeof(int) * capacity);
    array->size = 0;
    array->capacity = capacity;
    return array;
}

// to insert value at position
void insert(struct Array *array, int value, int position)
{
    if (array->size >= array->capacity) // return if array is full
        return;
    if (position == -1) // use position = -1 to insert at the end
    {
        insert(array, value, array->size); // insert at size index which is the end of the array
    }
    else
    {
        // shifts all elements to the right from size to position
        for (int i = array->size; i > position; i--)
        {
            array->arr[i] = array->arr[i - 1];
        }
        array->arr[position] = value; // insert value at position
        array->size++;
    }
}

void arrdelete(struct Array *array, int position)
{
    if (array->size == 0 || position >= array->size) // return if array is full or position exceeds size
        return;
    if (position == -1) // use position = -1 to delete from the end
    {
        arrdelete(array, array->size - 1);
    }
    else
    {
        // shifts all elements to the left from position to size
        for (int i = position; i < array->size - 1; i++)
        {
            array->arr[i] = array->arr[i + 1];
        }
        array->size--;
    }
}

int arrsearch(struct Array *array, int value)
{
    // check each element of the array for the value
    for (int i = 0; i < array->size; i++)
        if (array->arr[i] == value) // return true(or 1) if the element is found
        {
            printf("%d found\n", value);
            return 1;
        }
    // return false(or 0) if the element is not found after traversing the entire array
    printf("%d not found\n", value);
    return 0;
}

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
    int i;
    printf("The array is : [");
    for (i = 0; i < n - 1; i++)
        printf("%d, ", arr[i]);
    printf("%d]\n", arr[n - 1]);
}

int main()
{
    int n = 10;
    struct Array *array = createArray(n);
    // Insertion
    insert(array, 10, 0);
    printArray(array->arr, array->size);
    insert(array, 11, 0);
    printArray(array->arr, array->size);
    insert(array, 12, -1);
    printArray(array->arr, array->size);
    insert(array, 13, 1);
    printArray(array->arr, array->size);
    insert(array, 14, 0);
    printArray(array->arr, array->size);
    insert(array, 15, -1);
    printArray(array->arr, array->size);
    insert(array, 16, 0);
    printArray(array->arr, array->size);

    // Deletion
    arrdelete(array, 0);
    printArray(array->arr, array->size);
    arrdelete(array, -1);
    printArray(array->arr, array->size);
    arrdelete(array, 2);
    printArray(array->arr, array->size);

    //Search
    arrsearch(array, 10);
    arrsearch(array, 13);

    return 0;
}

// Output:
// The array is : [10]
// The array is : [11, 10]
// The array is : [11, 10, 12]
// The array is : [11, 13, 10, 12]
// The array is : [14, 11, 13, 10, 12]
// The array is : [14, 11, 13, 10, 12, 15]
// The array is : [16, 14, 11, 13, 10, 12, 15]
// The array is : [14, 11, 13, 10, 12, 15]
// The array is : [14, 11, 13, 10, 12]
// The array is : [14, 11, 10, 12]
// 10 found
// 13 not found
