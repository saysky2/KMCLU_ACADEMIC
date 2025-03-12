// Implementation of circular queue using linked list 

#include <stdio.h>
#include <stdlib.h>

// Node structure to represent elements in the linked list
struct Node 
{
    int data;
    struct Node *next;
};

// Circular Queue implemented using a linked list
struct CircularQueue 
{
    struct Node *front, *rear;
};

// Function to initialize a circular queue
void initializeQueue(struct CircularQueue *queue) 
{
    queue->front = queue->rear = NULL;
}

// Function to check if the queue is empty
int isEmpty(struct CircularQueue *queue) 
{
    return (queue->front == NULL);
}

// Function to enqueue (add) an element into the circular queue
void enqueue(struct CircularQueue *queue, int value) 
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (isEmpty(queue)) {
        queue->front = newNode;
    } else {
        queue->rear->next = newNode;
    }

    queue->rear = newNode;
    queue->rear->next = queue->front; // Establish circular behavior

    printf("%d enqueued to the queue.\n", value);
}

// Function to dequeue (remove) an element from the circular queue
void dequeue(struct CircularQueue *queue) 
{
    if (isEmpty(queue)) 
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    int value = queue->front->data;
    struct Node *temp = queue->front;

    if (queue->front == queue->rear) 
    {
        queue->front = queue->rear = NULL;
    }
    else 
    {
        queue->front = queue->front->next;
        queue->rear->next = queue->front; // Maintain circular behavior
    }

    free(temp);
    printf("%d dequeued from the queue.\n", value);
}

// Function to display the circular queue
void displayQueue(struct CircularQueue *queue) 
{
    if (isEmpty(queue)) 
    {
        printf("Queue is empty.\n");
        return;
    }

    struct Node *temp = queue->front;
    printf("Elements in the circular queue are: ");
    do 
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != queue->front);

    printf("\n");
}

int main() 
{
    struct CircularQueue queue;
    initializeQueue(&queue);
    int choice, value;

    while (1) 
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&queue, value);
                break;
            case 2:
                dequeue(&queue);
                break;
            case 3:
                displayQueue(&queue);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}