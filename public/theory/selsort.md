# What is Selection Sort?

Selection sort is conceptually the most simplest sorting algorithm. This algorithm will first find the smallest element in the array and swap it with the element in the first position, then it will find the second smallest element and swap it with the element in the second position, and it will keep on doing this until the entire array is sorted.
It is called selection sort because it repeatedly selects the next-smallest element and swaps it into the right place.

## Description of the algorithm

1. Starting from the first element, we search the smallest element in the array, and replace it with the element in the first position.
2. We then move on to the second position, and look for smallest element present in the subarray, starting from index 1, till the last index.
3. We replace the element at the second position in the original array, or we can say at the first position in the subarray, with the second smallest element.
4. This is repeated, until the array is completely sorted.

```python
> arr[] = 64 25 12 22 11
Find the minimum element in arr[0...4] and place it at beginning
11 25 12 22 64

> Find the minimum element in arr[1...4] and place it at beginning of arr[1...4]
11 12 25 22 64

> Find the minimum element in arr[2...4] and place it at beginning of arr[2...4]
11 12 22 25 64

> Find the minimum element in arr[3...4] and place it at beginning of arr[3...4]
11 12 22 25 64
```

## Time complexity

1. Worst Case : O(n2)
2. Best Case : Ω(n2)
3. Average Case : Θ(n2)
