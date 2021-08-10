# What is STACK?

Stack is one of the basic linear Data structure, that we use for storing our data. Data in a stack is stored in a serialized manner. One important thing about using a Stack is that the data first entered in the stack will be at the last of the stack. This is one of the reason why we also called Stack a LIFO Data Structure, i.e; Last in First Out. We’ll be discussing more about this feature later in this article.

The basic terminology that we will be using in Stack is :

Top – This refers to the topmost element of the stack, or in other words the element last entered in the stack.

Push () – This is one of the operation that we can perform on stack, for inserting data in this data structure.

Pop () – This operation deals with deleting the data from the stack. It deletes the top-most data from the stack.

Peek () – This operation helps us in looking at the topmost element of the data without removing it from the stack.

## Description of the algorithm

In stack related algorithms TOP initially point 0, index of elements in stack is start from 1, and index of last element is MAX.

```python
    INIT_STACK (STACK, TOP)

    Algorithm to initialize a stack using array.
    TOP points to the top-most element of stack.

    1) TOP: = 0;
    2) Exit
```

Push operation is used to insert an element into stack.

```python
    PUSH_STACK(STACK,TOP,MAX,ITEM)

    Algorithm to push an item into stack.

    1) IF TOP = MAX   then
    Print “Stack is full”;
    Exit;
    2) Otherwise
    TOP: = TOP + 1;        /*increment TOP*/
    STACK (TOP):= ITEM;
    3) End of IF
    4) Exit
```

Pop operation is used to remove an item from stack, first get the element and then decrease TOP pointer.

```python
    POP_STACK(STACK,TOP,ITEM)

    Algorithm to pop an element from stack.

    1) IF TOP = 0 then
        Print “Stack is empty”;
        Exit;
    2) Otherwise
        ITEM: =STACK (TOP);
        TOP:=TOP – 1;
    3) End of IF
    4) Exit
    IS_FULL(STACK,TOP,MAX,STATUS)

    Algorithm to check stack is full or not.
    STATUS contains the result status.

    1) IF TOP = MAX then
        STATUS:=true;
    2) Otherwise
        STATUS:=false;
    3)  End of IF
    4)  Exit
    IS_EMPTY(STACK,TOP,MAX,STATUS)

    Algorithm to check stack is empty or not.
    STATUS contains the result status.


    1) IF TOP = 0 then
        STATUS:=true;
    2) Otherwise
        STATUS:=false;
    3)  End of IF
    4)  Exit
```

## Time complexity

The time complexity of push(), pop(), isEmpty() and peek() is O(1) .
