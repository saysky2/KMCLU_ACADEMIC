#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct CircularQueue {
    struct Node* front;
    struct Node* rear;
};

// Function to initialize an empty circular queue
void initializeQueue(struct CircularQueue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// Function to check if the circular queue is empty
int isEmpty(struct CircularQueue* queue) {
    return (queue->front == NULL);
}

// Function to enqueue an element in the circular queue
void enqueue(struct CircularQueue* queue, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = newNode;
    } else {
        queue->rear->next = newNode;
    }

    queue->rear = newNode;
    queue->rear->next = queue->front; // Connect rear to front to make it circular
}

// Function to dequeue an element from the circular queue
int dequeue(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1; // Return an invalid value indicating failure
    }

    int removedData = queue->front->data;
    struct Node* temp = queue->front;

    if (queue->front == queue->rear) {
        queue->front = queue->rear = NULL;
    } else {
        queue->front = queue->front->next;
        queue->rear->next = queue->front;
    }

    free(temp);
    return removedData;
}


void display(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }

    struct Node* current = queue->front;
    printf("Elements in the circular queue: ");
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != queue->front);
    printf("\n");
}

// Example usage
int main() {
    struct CircularQueue cq;
    initializeQueue(&cq);

    enqueue(&cq, 1);
    enqueue(&cq, 2);
    enqueue(&cq, 3);

    display(&cq);  

    dequeue(&cq);
    display(&cq);  

    return 0;
}
