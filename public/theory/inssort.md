# What is Insertion Sort?

Insertion sort is the sorting mechanism where the sorted array is built having one item at a time. The array elements are compared with each other sequentially and then arranged simultaneously in some particular order. The analogy can be understood from the style we arrange a deck of cards. This sort works on the principle of inserting an element at a particular position, hence the name Insertion Sort.

## Description of the algorithm

1. The first step involves the comparison of the element in question with its adjacent element.
2. And if at every comparison reveals that the element in question can be inserted at a particular position, then space is created for it by shifting the other elements one position to the right and inserting the element at the suitable position.
3. The above procedure is repeated until all the element in the array is at their apt position.

```python
INSERTION-SORT(A)
    for i = 1 to n
        key ← A [i]
        j ← i – 1
        while j > = 0 and A[j] > key
            A[j+1] ← A[j]
            j ← j – 1
        End while
        A[j+1] ← key
    End for
```

## Time complexity

1. Worst Case : O(n2)
2. Best Case : Ω(n)
