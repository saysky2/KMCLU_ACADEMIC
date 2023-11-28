// Program to implement stack using linked list
#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};

struct Node* top = NULL; // Initially the list is empty

void push(int);
void pop();
void display();

int main() {
    int choice, value;
    printf("\nIMPLEMENTING STACKS USING LINKED LISTS\n");
    while (1) {
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the value to insert: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("\nInvalid Choice\n");
        }
    }
}

void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1); // Exit the program with an error code
    }

    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("Node is Inserted\n\n");
}

void pop() {
    if (top == NULL) {
        printf("\nEMPTY STACK\n");
    } else {
        struct Node* temp = top;
        printf("\nPopped Element : %d", temp->data);
        printf("\n");
        top = temp->next;
        free(temp);
    }
}

void display() {
    if (top == NULL) {
        printf("\nEMPTY STACK\n");
    } else {
        printf("The stack is \n");
        struct Node* temp = top;
        while (temp != NULL) {
            printf("%d--->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n\n");
    }
}