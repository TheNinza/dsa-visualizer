# What is One Dimensional Array?

A simple array may be created when the variables grouped together conceptually appear as a single row. This is known as a one-dimensional array.
A single or one dimensional array declaration has the following form,
"array_element_data_type array_name[array_size];"
Here, array_element_data_type define the base type of the array, which is the type of each element in the array.
"array_name" is any valid C identifier name that obeys the same rule for the
identifier naming.
"array_size" defines how many elements the array will hold.

Syntax: datatype array_name[size];
datatype: It denotes the type of the elements in the array.
array_name: Name of the array. It must be a valid identifier.
size: Number of elements an array can hold. here are some example of array declarations:

> int num[100];
> float temp[20];
> char ch[50];

num is an array of type int, which can only store 100 elements of type int.
temp is an array of type float, which can only store 20 elements of type float.
ch is an array of type char, which can only store 50 elements of type char.

## Description of the algorithm

Rules For Declaring One Dimensional Array:

```python

- An array variable must be declared before being used in a program.

- The declaration must have a data type(int, float, char, double, etc.), variable name, and subscript.

- The subscript represents the size of the array. If the size is declared as 10, programmers can store 10 elements.

- An array index always starts from 0. For example, if an array variable is declared as s[10], then it ranges from 0 to 9.

- Each array element stored in a separate memory location
```

## Time complexity

The time complexity of two dimensional array is O(n)
