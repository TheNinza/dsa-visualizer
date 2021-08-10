# Python implementation of De-queue


# Maximum size of array or Dequeue
MAX = 10000


# A structure to represent a Deque
class Deque:
    def __init__(self, size):
        self.arr = [None]*MAX
        self.front = -1
        self.rear = 0
        self.size = size


# Checks whether Deque is full or not.
def isFull(deque):
    return ((deque.front == 0 & deque.rear == deque.size - 1) |
            deque.front == deque.rear + 1)


# Checks whether Deque is empty or not.
def isEmpty(deque):
    return (deque.front == -1)


# Inserts an element at front
def insertfront(deque, key):
    # check whether Deque if full or not
    if (isFull(deque)):
        print("Overflow\n\n")
        return

    # If queue is initially empty
    if (deque.front == -1):
        deque.front = 0
        deque.rear = 0

    # front is at first position of queue
    elif (deque.front == 0):
        deque.front = deque.size - 1

    else:  # decrement front end by '1'
        deque.front = deque.front - 1

    # insert current element into Deque
    deque.arr[deque.front] = key


# function to inset element at rear end
# of Deque.
def insertrear(deque, key):
    if (isFull(deque)):
        print("Overflow\n\n")
        return

    # If queue is initially empty
    if (deque.front == -1):
        deque.front = 0
        deque.rear = 0

    # rear is at last position of queue
    elif (deque.rear == deque.size - 1):
        deque.rear = 0

    # increment rear end by '1'
    else:
        deque.rear = deque.rear + 1

    # insert current element into Deque
    deque.arr[deque.rear] = key


# Deletes element at front end of Deque
def deletefront(deque):
    # check whether Deque is empty or not
    if (isEmpty(deque)):
        print("Queue Underflow\n\n")
        return

    # Deque has only one element
    if (deque.front == deque.rear):
        deque.front = -1
        deque.rear = -1

    else:
        # back to initial position
        if (deque.front == deque.size - 1):
            deque.front = 0

        else:  # increment front by '1' to remove current
            # front value from Deque
            deque.front = deque.front + 1


# Delete element at rear end of Deque
def deleterear(deque):
    if (isEmpty(deque)):
        print("Underflow\n\n")
        return

    # Deque has only one element
    if (deque.front == deque.rear):
        deque.front = -1
        deque.rear = -1

    elif (deque.rear == 0):
        deque.rear = deque.size - 1
    else:
        deque.rear = deque.rear - 1


# Returns front element of Deque
def getFront(deque):
    # check whether Deque is empty or not
    if (isEmpty(deque)):
        print("Underflow\n\n")
        return -1
    return deque.arr[deque.front]


# function return rear element of Deque
def getRear(deque):
    # check whether Deque is empty or not
    if (isEmpty(deque) | deque.rear < 0):
        print("Underflow\n\n")
        return -1
    return deque.arr[deque.rear]


# Driver program to test above function

dq = Deque(5)
print("Insert element at rear end : 10")
insertrear(dq, 10)

print("insert element at rear end : 100")
insertrear(dq, 100)

print("get rear element", getRear(dq))

deleterear(dq)
print("After delete rear element new rear become", getRear(dq))

print("inserting element at front end : -1")
insertfront(dq, -1)

print("get front element", getFront(dq))

deletefront(dq)

print("After delete front element new front become", getFront(dq))


# Output:
# Insert element at rear end : 10
# insert element at rear end : 100
# get rear element  100
# After delete rear element new rear become 10
# inserting element at front end : -1
# get front element  -1
# After delete front element new front become 10
