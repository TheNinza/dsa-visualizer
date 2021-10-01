# What is Bubble Sorting?

Bubble sort is a sorting algorithm that works by repeatedly stepping through lists that need to be sorted, comparing each pair of adjacent items and swapping them if they are in the wrong order. This passing procedure is repeated until no swaps are required, indicating that the list is sorted. Bubble sort gets its name because smaller elements bubble toward the top of the list.

It basically does swapping of elements if they are not in the right order depending on their value and the intended order. A nested loop will be used to implement this algorithm.

## Description of the algorithm

1.Bubble sort is mainly used in educational purposes for helping students understand the foundations of sorting.

2.This is used to identify whether the list is already sorted. When the list is already sorted (which is the best-case scenario), the complexity of bubble sort is only O(n).

3.In real life, bubble sort can be visualised when people in a queue wanting to be standing in a height wise sorted manner swap their positions among themselves until everyone is standing based on increasing order of heights.

,

```python
bubbleSort( Arr[], total_elements)
   for i = 0 to total_elements - 1 do:
      swapped = false
      for j = 0 to total_elements - i - 2 do:
         if Arr[j] > Arr[j+1] then
            swap(Arr[j], Arr[j+1])
            swapped = true
         end if
      end for
      if(not swapped) then
         break
      end if
   end for
end
```

## Time complexity

The time complexity is of the order n2 or O(n2).
