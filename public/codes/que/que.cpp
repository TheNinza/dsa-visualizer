// C++ program for implementation of queue
#include <iostream>
using namespace std;

#define INT_MIN -32768;

// A structure to represent a queue
struct Queue
{
    int front, rear, size;
    unsigned int capacity;
    int *array;
};

// function to create a queue
// of given capacity.
// It initializes size of queue as 0
struct Queue *createQueue(unsigned int capacity)
{
    struct Queue *queue = new struct Queue;
    queue->capacity = capacity;
    queue->front = queue->size = 0;

    // This is important, see the enqueue
    queue->rear = capacity - 1;
    queue->array = new int[queue->capacity];
    return queue;
}

// Queue is full when size becomes
// equal to the capacity
int isFull(struct Queue *queue)
{
    return (queue->size == queue->capacity);
}

// Queue is empty when size is 0
int isEmpty(struct Queue *queue)
{
    return (queue->size == 0);
}

// Function to add an item to the queue.
// It changes rear and size
void enqueue(struct Queue *queue, int item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
    cout << item << " enqueued to queue" << endl;
}

// Function to remove an item from queue.
// It changes front and size
int dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    cout << item << " dequeued from queue" << endl;
    return item;
}

// Function to get front of queue
int front(struct Queue *queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}

// Function to get rear of queue
int rear(struct Queue *queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->rear];
}

// Driver program to test above functions
int main()
{
    struct Queue *queue = createQueue(1000);

    enqueue(queue, 10);
    enqueue(queue, 100);
    enqueue(queue, -1);

    dequeue(queue);

    cout << "Front item is " << front(queue) << endl;
    cout << "Rear item is " << rear(queue) << endl;

    delete[] (queue->array);
    delete queue;

    return 0;
}

// Output: 
// 10 enqueued to queue
// 100 enqueued to queue
// -1 enqueued to queue
// 10 dequeued to queue
// Front item is 100
// Rear item is -1
