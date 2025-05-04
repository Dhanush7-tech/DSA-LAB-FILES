#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

// Queue ADT using an Array
class QueueADT {
private:
    int arr[SIZE];
    int front, rear;

public:
    // Constructor
    QueueADT() {
        front = -1;
        rear = -1;
    }

    void enqueue(int value); // Enqueue operation
    int dequeue();           // Dequeue operation
    int peek();              // Peek operation
};

// Main function with menu-driven approach
int main() {
    QueueADT queue;
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
void QueueADT::enqueue(int value) {
    if (rear == SIZE - 1) {
        printf("Queue is full!\n");
        return;
    }
    if (front == -1) front = 0;
    arr[++rear] = value;
    printf("Enqueued: %d\n", value);
}

// Dequeue function
int QueueADT::dequeue() {
    if (front == -1 || front > rear) {
        return -1; // Queue is empty
    }
    return arr[front++];
}

// Peek function
int QueueADT::peek() {
    if (front == -1 || front > rear) {
        return -1; // Queue is empty
    }
    return arr[front];
}
