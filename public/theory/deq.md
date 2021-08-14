# What is Double Ended Queue?

It is a homogeneous list of elements in which insertion and deletion operations are performed from both the ends i.e, we can insert elements from the rear end or from the front ends. Hence, it is called double-ended queue. It is commonly referred to as deque.

There are two types of deques. These two types are due to the restrictions put to preform either the insertions or deletions only at the end. They are :

1. Input Restricted Deque

2. Output Restricted Deque

Four Operations :

=> Insertion of an element at the REAR end of the queue

=> Deletion of an element from the FRONT end of the queue

=> Insertion of an element at the FRONT end of the queue

=> Deletion of an element from the REAR end of the queue

## Description of the algorithm

Algorithm for Insertion at rear end

```python
Step-1: [Check for overflow]
		if(rear==MAX)
			Print("Queue is Overflow”);
			return;
Step-2:  [Insert Element]
		else
			rear=rear+1;
			q[rear]=no;
		[Set rear and front pointer]
		if rear=0
			rear=1;
		if front=0
			front=1;
Step-3: return
```

Algorithm for Insertion at front end

```python
Step-1 :  [Check for the front position]
		if(front<=1)
			Print("Cannot add item at the front”);
			return;
Step-2 :  [Insert at front]
		else
			front=front-1;
			q[front]=no;
Step-3  : Return
```

Algorithm for Deletion from front end

```python
Step-1 [ Check for front pointer]
		if front=0
			print(" Queue is Underflow”);
			return;
Step-2 [Perform deletion]
		else
			no=q[front];
			print(“Deleted element is”,no);
		[Set front and rear pointer]
		if front=rear
			front=0;
			rear=0;
		else
			front=front+1;
Step-3 : Return
```

Algorithm for Deletion from rear end

```python
Step-1 : [Check for the rear pointer]
		if rear=0
			print(“Cannot delete value at rear end”);
			return;
Step-2:  [ perform deletion]
		else
			no=q[rear];
			[Check for the front and rear pointer]
		if front= rear
			front=0;
			rear=0;
		else
			rear=rear-1;
			print(“Deleted element is”,no);
Step-3 : Return
```

## Time complexity

Insertion or deletion in the middle is O(n)

The time complexity of random access by index is O(1)

time complexity of all enque(insert)/deque(delete) operations is O(1)
