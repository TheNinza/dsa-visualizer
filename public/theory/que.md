# What is QUEUE?

A queue is a linear type of data structure used to store the data in a sequentially. The concept of queue is based on the FIFO, which means "First in First Out". It is also known as "first come first severed". The queue has the two ends front and rear. The next element is inserted from the rear end and removed from the front end.

We can perform the following operations in the Queue.

Enqueue - The enqueue is an operation where we add items to the queue. If the queue is full, it is a condition of the Queue

Dequeue - The dequeue is an operation where we remove an element from the queue. An element is removed in the same order as it is inserted. If
the queue is empty, it is a condition of the Queue Underflow.

Front - An element is inserted in the front end.

Rear - An element is removed from the rear end..

## Description of the algorithm

Algorithm for enqueue operation

```python
procedure enqueue(data)

   if queue is full
      return overflow
   endif

   rear ← rear + 1
   queue[rear] ← data
   return true

end procedure
```

Algorithm for dequeue operation

```python
procedure dequeue

   if queue is empty
      return underflow
   end if

   data = queue[front]
   front ← front + 1
   return true

end procedure
```

peek()
This function helps to see the data at the front of the queue. The algorithm of peek() function is as follows −

Algorithm

```python
begin procedure peek
   return queue[front]
end procedure
```

isfull()
As we are using single dimension array to implement queue, we just check for the rear pointer to reach at MAXSIZE to determine that the queue is full. In case we maintain the queue in a circular linked-list, the algorithm will differ. Algorithm of isfull() function −

Algorithm

```python
begin procedure isfull

   if rear equals to MAXSIZE
      return true
   else
      return false
   endif

end procedure
```

isempty()
Algorithm of isempty() function −

Algorithm

```python
begin procedure isempty

   if front is less than MIN  OR front is greater than rear
      return true
   else
      return false
   endif

end procedure
```

## Time complexity

Enqueue: O(N) time (worst case), O(1) time (best case), O(1) time (average case)

Dequeue: O(1) time

Peek: O(1).

Full: O(1) time

Empty: O(1) time
