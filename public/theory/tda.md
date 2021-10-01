# What is Two Dimensional Array?

The two-dimensional array can be defined as an array of arrays. The 2D array is organized as matrices which can be represented as the collection of rows and columns. However, 2D arrays are created to implement a relational database lookalike data structure. It provides ease of holding the bulk of data at once which can be passed to any number of functions wherever required.

### Declaration of two dimensional Array in C:

The syntax to declare the 2D array is given below.

> arr_type arr_name [ rows ] [ cols ] ;

Where arr_name is the name of the array being declared, each element of which is of type arr_type. The expressions rows and cols enclosed in square brackets are constant integral expressions (or integral constants) that specify the number of rows and columns in the array. When a compiler comes across the declaration of an array, it reserves memory for the specified number of array elements. For a two-dimensional array, the memory required is given as rows* cols* sizeof(arr_type).

Note that we can declare matrices of built-in as well as user-defined types; we can also declare multiple matrices in a single declaration statement, separated by commas. Scalar variables, vectors and multidimensional arrays can also be declared along with matrices.

## Description of the algorithm

In the 1D array, we don't need to specify the size of the array if the declaration and initialization are being done simultaneously. However, this will not work with 2D arrays.
Just as with one-dimensional arrays, you cannot change
the size of a two-dimensional array once it has been
defined.
But you can initialize a 2-D array like this:

```python
int counts[COUNTRIES][MEDALS] =
 {
 { 0, 3, 0 },
 { 0, 0, 1 },
 { 0, 0, 1 },
 { 1, 0, 0 },
 { 0, 0, 1 },
 { 3, 1, 1 },
 { 0, 1, 0 }
 { 1, 0, 1 }
 };
```

## Time complexity

The time complexity of two dimensional array is O(n^2)
