#include <stdio.h>
#include <stdlib.h>

// Queue ADT using a Linked List
class LinkedListQueueADT {
private:
    struct Node {
        int data;
        Node* next;
    };
    Node* front;
    Node* rear;

public:
    // Constructor
    LinkedListQueueADT() {
        front = rear = NULL;
    }

    void enqueue(int value); // Enqueue operation
    int dequeue();           // Dequeue operation
    int peek();              // Peek operation
};


// Main function with menu-driven approach
int main() {
    LinkedListQueueADT queue;
    int choice, value, result;

    do {
        printf("\nMENU:\n1) Enqueue\n2) Dequeue\n3) Peek\n4) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                queue.enqueue(value);
                break;

            case 2:
                result = queue.dequeue();
                if (result != -1) {
                    printf("Dequeued element: %d\n", result);
                } else {
                    printf("Queue is empty. Cannot dequeue.\n");
                }
                break;

            case 3:
                result = queue.peek();
                if (result != -1) {
                    printf("Front element: %d\n", result);
                } else {
                    printf("Queue is empty.\n");
                }
                break;

            case 4:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice! Enter a number between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}
// Enqueue function
void LinkedListQueueADT::enqueue(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Enqueued: %d\n", value);
}
// Dequeue function
int LinkedListQueueADT::dequeue() {
    if (front == NULL) {
        return -1; // Queue is empty
    }
    Node* temp = front;
    int data = temp->data;
    front = front->next;
    if (front == NULL) {
        rear = NULL; // Reset queue
    }
    free(temp);
    return data;
}

// Peek function
int LinkedListQueueADT::peek() {
    if (front == NULL) {
        return -1; // Queue is empty
    }
    return front->data;
}