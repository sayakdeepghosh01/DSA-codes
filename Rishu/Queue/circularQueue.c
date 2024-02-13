#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

struct Queue {
    int items[SIZE];
    int front, rear;
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
    if ((queue->front == 0 && queue->rear == SIZE - 1) ||
        (queue->rear == (queue->front - 1) % (SIZE - 1)))
        return 1;
    return 0;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    if (queue->front == -1)
        return 1;
    return 0;
}

// Function to add an element to the queue
void enqueue(struct Queue* queue, int value) {
    if (isFull(queue))
        printf("Queue is full\n");
    else {
        if (queue->front == -1)
            queue->front = 0;
        queue->rear = (queue->rear + 1) % SIZE;
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
        if (queue->front == queue->rear) {
            queue->front = queue->rear = -1;
        } else {
            queue->front = (queue->front + 1) % SIZE;
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

//Explanation:

// Circular queue is similar to a simple queue but it handles wrap around condition more efficiently.
// isFull() and isEmpty() functions are defined similar to the simple queue implementation but with wrap around consideration.
// enqueue() and dequeue() functions also consider the wrap around condition.