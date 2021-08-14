// C++ program for implementation of stack
#include <iostream>
using namespace std;

#define INT_MIN -32768;

// A structure to represent a stack
struct Stack
{
    int top;
    unsigned int capacity;
    int *array;
};

// function to create a stack of given capacity. It initializes size of
// stack as 0
struct Stack *createStack(unsigned int capacity)
{
    struct Stack *stack = new struct Stack;
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = new int[stack->capacity];
    return stack;
}

// Stack is full when top is equal to the last index
int isFull(struct Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

// Stack is empty when top is equal to -1
int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

// Function to add an item to stack. It increases top by 1
void push(struct Stack *stack, int item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
    cout << item <<" pushed to stack" << endl;
}

// Function to remove an item from stack. It decreases top by 1
int pop(struct Stack *stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    cout << stack->array[stack->top] << " popped from stack" << endl;
    return stack->array[stack->top--];
}

// Function to return the top from stack without removing it
int peek(struct Stack *stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}

// Driver program to test above functions
int main()
{
    struct Stack *stack = createStack(100);

    push(stack, 10);
    push(stack, 100);
    push(stack, -1);

    pop(stack);

    cout << peek(stack) << " is the top now" << endl;

    delete[] (stack->array);
    delete stack;

    return 0;
}

// Output:
// 10 pushed to stack
// 100 pushed to stack
// -1 pushed to stack
// -1 popped from stack
// 100 is the top now
