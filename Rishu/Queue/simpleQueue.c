#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

struct Queue {
    int items[SIZE];
    int front;
    int rear;
};

// Function to create a queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    if (queue->rear == SIZE - 1)
        return 1;
    return 0;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    if (queue->rear == -1)
        return 1;
    return 0;
}

// Function to add an element to the queue
void enqueue(struct Queue* queue, int value) {
    if (isFull(queue))
        printf("Queue is full\n");
    else {
        if (isEmpty(queue))
            queue->front = 0;
        queue->rear++;
        queue->items[queue->rear] = value;
        printf("Inserted %d\n", value);
    }
}

// Function to remove an element from the queue
int dequeue(struct Queue* queue) {
    int item;
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    } else {
        item = queue->items[queue->front];
        queue->front++;
        if (queue->front > queue->rear) {
            queue->front = queue->rear = -1;
        }
        return item;
    }
}

int main() {
    struct Queue* queue = createQueue();

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    printf("Dequeuing element %d\n", dequeue(queue));
    printf("Dequeuing element %d\n", dequeue(queue));

    enqueue(queue, 6);

    return 0;
}

// Explaination: 
// This code defines a simple queue using an array.
// createQueue() function creates a new queue and initializes its front and rear indices.
// isFull() and isEmpty() functions check if the queue is full or empty respectively.
// enqueue() adds elements to the rear of the queue.
// dequeue() removes elements from the front of the queue.