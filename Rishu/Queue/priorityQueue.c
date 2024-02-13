#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int priority;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int d, int p) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = d;
    temp->priority = p;
    temp->next = NULL;
    return temp;
}

// Function to push an element into the queue
void push(struct Node** head, int d, int p) {
    struct Node* start = (*head);
    struct Node* temp = newNode(d, p);

    if ((*head)->priority > p) {
        temp->next = *head;
        (*head) = temp;
    } else {
        while (start->next != NULL && start->next->priority < p) {
            start = start->next;
        }
        temp->next = start->next;
        start->next = temp;
    }
}

// Function to pop the element with the highest priority
int pop(struct Node** head) {
    struct Node* temp = *head;
    int data = (*head)->data;
    (*head) = (*head)->next;
    free(temp);
    return data;
}

int isEmpty(struct Node** head) {
    return (*head) == NULL;
}

int main() {
    struct Node* pq = newNode(0, 0);

    push(&pq, 2, 1);
    push(&pq, 3, 0);
    push(&pq, 4, 2);
    push(&pq, 5, 0);

    while (!isEmpty(&pq)) {
        printf("%d ", pop(&pq));
    }
    return 0;
}



// Explanation:

// Priority queue is implemented using linked list.
// Each node of the linked list contains data and priority.
// push() function adds an element to the priority queue based on its priority.
// pop() function removes and returns the element with the highest priority.