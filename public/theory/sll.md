# What is Singly Linked List?

Singly linked list can be defined as the collection of ordered set of elements. The number of elements may vary according to need of the program.

A node in the singly linked list consist of two parts: data part and link part. Data part of the node stores actual information that is to be represented by the node while the link part of the node stores the address of its immediate successor.

One way chain or singly linked list can be traversed only in one direction. In other words, we can say that each node contains only next pointer, therefore we can not traverse the list in the reverse direction.

It requires only one list pointer variable, i.e., the head pointer pointing to the first node.

### Memory space

It utilizes less memory space as compare to doubly linked list.

## Description of the algorithm

To create a singly linked list, we will need to start by creating two classes: Node and SinglyLinkedList

Since our nodes consist of some sort of value as well as a pointer to the next one, it needs to contain a val attribute as well as a next attribute. next will start by being equal to null.

Remember that our singly linked list needs to include a head and a tail to specify where it begins and ends. We will also add a length property to make some of our functions easier to implement. The head and tail will start as null.

```python
 class Node {
  constructor(val) {
    this.val = val;
    this.next = null;
  }
}


class SinglyLinkedList {
  constructor() {
    this.length = 0;
    this.head = null;
    this.tail = null;
  }
}
```

## Time complexity

In a singly linked list, the time complexity for inserting and deleting an element from the list is O(n).
