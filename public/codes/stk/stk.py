# Python program for implementation of stack

maxsize = 32767


# Function to create a stack. It initializes size of stack as 0
def createStack():
    stack = []
    return stack


# Stack is empty when stack size is 0
def isEmpty(stack):
    return len(stack) == 0


# Function to add an item to stack. It increases size by 1
def push(stack, item):
    stack.append(item)
    print(item, "pushed to stack ")


# Function to remove an item from stack. It decreases size by 1
def pop(stack):
    if (isEmpty(stack)):
        return (-maxsize - 1)  # return minus infinite
    return stack.pop()


# Function to return the top from stack without removing it
def peek(stack):
    if (isEmpty(stack)):
        return (-maxsize - 1)  # return minus infinite
    return stack[len(stack) - 1]


# Driver program to test above functions
stack = createStack()
push(stack, 10)
push(stack, 100)
push(stack, -1)
print(pop(stack), "popped from stack")
print(peek(stack), "is the top now")

# Output:
# 10 pushed to stack
# 100 pushed to stack
# -1 pushed to stack
# -1 popped from stack
# 100 is the top now
