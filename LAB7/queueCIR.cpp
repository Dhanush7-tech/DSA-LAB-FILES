#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

// Circular Queue ADT using an Array
class CircularQueueADT {
private:
    int arr[SIZE];
    int front, rear;

public:
    // Constructor
    CircularQueueADT() {
        front = -1;
        rear = -1;
    }

    void enqueue(int value); // Enqueue operation
    int dequeue();           // Dequeue operation
    int peek();              // Peek operation
};

// Enqueue function
void CircularQueueADT::enqueue(int value) {
    if ((rear + 1) % SIZE == front) {
        printf("Queue is full!\n");
        return;
    }
    if (front == -1) front = 0;
    rear = (rear + 1) % SIZE;
    arr[rear] = value;
    printf("Enqueued: %d\n", value);
}

// Dequeue function
int CircularQueueADT::dequeue() {
    if (front == -1) {
        return -1; // Queue is empty
    }
    int data = arr[front];
    if (front == rear) {
        front = rear = -1; // Reset queue
    } else {
        front = (front + 1) % SIZE;
    }
    return data;
}

// Peek function
int CircularQueueADT::peek() {
    if (front == -1) {
        return -1; // Queue is empty
    }
    return arr[front];
}

// Main function with menu-driven approach
int main() {
    CircularQueueADT queue;
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
