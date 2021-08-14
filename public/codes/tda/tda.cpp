//C++ Program for row major and column major traversal of 2 dimentional array
#include <iostream>
using namespace std;

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
    cout << "The array in row major traversal is : [";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << array[i][j] << ", ";
    }
    cout << "]" << endl;

    // column major traversal
    cout << "The array in column major traversal is : [";
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
            cout << array[i][j] << ", ";
    }
    cout << "]" << endl;

    return 0;
}

// Output:
// The array in row major traversal is : [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, ]
// The array in column major traversal is : [1, 6, 11, 16, 2, 7, 12, 17, 3, 8, 13, 18, 4, 9, 14, 19, 5, 10, 15, 20, ]
