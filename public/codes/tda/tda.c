//C Program for row major and column major traversal of 2 dimentional array
#include <stdio.h>
#include <stdlib.h>

// A utility function to print an array of size n x m in row major order
void printArrayRowMajor(int **arr, int n, int m)
{
    int i, j;
    printf("The array in row major traversal is : [");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            printf("%d, ", arr[i][j]);
    }
    printf("]\n");
}

int main()
{
    int n = 4, m = 5;

    int array[n][m];

    /* To fill the array like this
    {{ 1, 2, 3, 4, 5},
     { 6, 7, 8, 9,10},
     {11,12,13,14,15},
     {16,17,18,19,20}}
    */
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            array[i][j] = count;
            count++;
        }
    }

    // row major traversal
    printf("The array in row major traversal is : [");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d, ", array[i][j]);
    }
    printf("]\n");

    // column major traversal
    printf("The array in column major traversal is : [");
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
            printf("%d, ", array[i][j]);
    }
    printf("]\n");

    return 0;
}

// Output:
// The array in row major traversal is : [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, ]
// The array in column major traversal is : [1, 6, 11, 16, 2, 7, 12, 17, 3, 8, 13, 18, 4, 9, 14, 19, 5, 10, 15, 20, ]
