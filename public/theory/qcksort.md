# What is Quick Sort?

Quick sort algorithm is one of the most widely used sorting algorithms. It follows a divide and conquer paradigm. We usually use Recursion in quicksort implementation. In each recursive call, a pivot is chosen, then the array is partitioned in such a way that all the elements less than pivot lie to the left and all the elements greater than pivot lie to the right.

After every call, the chosen pivot occupies its correct position in the array which it is supposed to as in a sorted array. So with each step, our problem gets reduced by 2 which leads to quick sorting. Pivot can be an element. Example: last element of the current array or the first element of current array or random pivot etc.

## Description of the algorithm

The algorithm processes the elements in 3 steps.

1. An array is divided into subarrays by selecting a pivot element (element selected from the array).

2. While dividing the array, the pivot element should be positioned in such a way that elements less than pivot are kept on the left side and elements greater than pivot are on the right side of the pivot.

3. The left and right subarrays are also divided using the same approach. This process continues until each subarray contains a single element.

At this point, elements are already sorted. Finally, elements are combined to form a sorted array.

The main idea behind merge sort is that, the short list takes less time to be sorted.

```python
quickSort(arr, beg, end)
    if (beg < end)
        pivotIndex = partition(arr,beg, end)
        quickSort(arr, beg, pivotIndex)
        quickSort(arr, pivotIndex + 1, end)

partition(arr, beg, end)
    set end as pivotIndex
    pIndex = beg - 1
    for i = beg to end-1
        if arr[i] < pivot
        swap arr[i] and arr[pIndex]
        pIndex++
    swap pivot and arr[pIndex+1]
    return pIndex + 1
```

## Time complexity

1. Worst Case : O(n^2)
2. Best Case : O(n log n)
