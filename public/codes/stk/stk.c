// C program for implementation of stack
#include <stdio.h>
#include <stdlib.h>

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
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
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
    printf("%d pushed to stack\n", item);
}

// Function to remove an item from stack. It decreases top by 1
int pop(struct Stack *stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    printf("%d popped from stack\n", stack->array[stack->top]);
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

    printf("%d is the top now", peek(stack));

    free(stack->array);
    free(stack);
    return 0;
}

// Output:
// 10 pushed to stack
// 100 pushed to stack
// -1 pushed to stack
// -1 popped from stack
// 100 is the top now
