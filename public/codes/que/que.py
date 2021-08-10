# Python3 program for array implementation of queue

INT_MIN = -32768


# Class Queue to represent a queue
class Queue:

    # __init__ function
    def __init__(self, capacity):
        self.front = self.size = 0
        self.rear = capacity - 1
        self.array = [None]*capacity
        self.capacity = capacity

    # Queue is full when size becomes
    # equal to the capacity
    def isFull(self):
        return self.size == self.capacity

    # Queue is empty when size is 0
    def isEmpty(self):
        return self.size == 0

    # Function to add an item to the queue.
    # It changes rear and size
    def enqueue(self, item):
        if self.isFull():
            return
        self.rear = (self.rear + 1) % (self.capacity)
        self.array[self.rear] = item
        self.size += 1
        print(item, "enqueued to queue")

    # Function to remove an item from queue.
    # It changes front and size
    def dequeue(self):
        if self.isEmpty():
            return INT_MIN

        print(self.array[self.front], "dequeued from queue")
        self.front = (self.front + 1) % (self.capacity)
        self.size -= 1

    # Function to get front of queue
    def qfront(self):
        if self.isEmpty():
            return INT_MIN

        return self.array[self.front]

    # Function to get rear of queue
    def qrear(self):
        if self.isEmpty():
            return INT_MIN
        return self.array[self.rear]


# Driver Code
queue = Queue(1000)

queue.enqueue(10)
queue.enqueue(100)
queue.enqueue(-1)

queue.dequeue()

print("Front item is", queue.qfront())
print("Rear item is", queue.qrear())

# Output:
# 10 enqueued to queue
# 100 enqueued to queue
# -1 enqueued to queue
# 10 dequeued from queue
# Front item is 100
# Rear item is -1
