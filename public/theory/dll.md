# What is Doubly Linked List?

Doubly linked list is a complex type of linked list in which a node contains a pointer to the previous as well as the next node in the sequence.

Therefore, in a doubly linked list, a node consists of three parts: node data, pointer to the next node in sequence (next pointer) , pointer to the previous node (previous pointer).

Doubly linked list is a complex type of linked list in which a node contains a pointer to the previous as well as the next node in the sequence.

Therefore, in a doubly linked list, a node consists of three parts: node data, pointer to the next node in sequence (next pointer) , pointer to the previous node (previous pointer).

## Description of the algorithm

Assume that START is the first element in the linked list and TAIL is the last element of linked list.

i. Insert At Beginning

```python
Start
Input the DATA to be inserted
Create a new node.
NewNode → Data = DATA NewNode →Lpoint =NULL
IF START IS NULL NewNode→ Rpoint = NULL

Else NewNode → Rpoint = START START→Lpoint = NewNode
START =NewNode
Stop
```

ii. Insertion at location:

```python
Start
Input the DATA and POS
Initialize TEMP = START; i = 0
Repeat the step 4 if (i less than POS) and (TEMP is not equal to NULL)
TEMP = TEMP → RPoint; i = i +1
If (TEMP not equal to NULL) and (i equal to POS)
(a) Create a New Node

(b) NewNode → DATA = DATA

(c) NewNode → RPoint = TEMP → RPoint

(d) NewNode → LPoint = TEMP

(e) (TEMP → RPoint) → LPoint = NewNode

(f ) TEMP → RPoint = New Node

Else

(a) Display “Position NOT found”

Stop
```

iii. Insert at End

```python
Start
Input DATA to be inserted
Create a NewNode
NewNode → DATA = DATA
NewNode → RPoint = NULL
If (START equal to NULL)
a. START = NewNode

b. NewNode → LPoint=NULL

Else
a. TEMP = START

b. While (TEMP → Next not equal to NULL)

i. TEMP = TEMP → Next

c. TEMP → RPoint = NewNode

d. NewNode → LPoint = TEMP

Stop
```

iv. Forward Traversal

```python
Start
If (START is equal to NULL)
a) Display “The list is Empty”

b) Stop

Initialize TEMP = START
Repeat the step 5 and 6 until (TEMP == NULL )
Display “TEMP → DATA”
TEMP = TEMP → Next
Stop
```

v. Backward Traversal

```python
Start
If (START is equal to NULL)
Display “The list is Empty”
Stop
Initialize TEMP = TAIL
Repeat the step 5 and 6 until (TEMP == NULL )
Display “TEMP → DATA”
TEMP = TEMP → Prev
Stop
```

## Time complexity

In a doubly-linked list, the time complexity for inserting and deleting an element is O(1).
