#include <stdio.h>

class StackADT {
private:
    int top;       // Index of the top element
    int max_size;  // Maximum size of stack
    int arr[5];    // Array to store stack elements

public:
    // Constructor
    StackADT() {
        top = -1;      // Stack is initially empty
        max_size = 5;  // Stack size fixed to 5
    }

    void push(int num);   // Push operation
    int pop();            // Pop operation
    int peek();           // Peek operation
    void display();       // Display stack elements
};

// Main function with menu-driven approach
int main() {
    StackADT stack;
    int choice, result, num;

    do {
        printf("\nMENU:\n1) Push\n2) Pop\n3) Peek\n4) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number to push: ");
                scanf("%d", &num);
                stack.push(num);
                break;

            case 2:
                result = stack.pop();
                if (result != -1) {
                    printf("Popped element: %d\n", result);
                } else {
                    printf("Stack is empty. Cannot pop.\n");
                }
                break;

            case 3:
                result = stack.peek();
                if (result != -1) {
                    printf("Top element: %d\n", result);
                } else {
                    printf("Stack is empty.\n");
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

// Push function
void StackADT::push(int num) {
    if (top >= max_size - 1) {
        printf("Stack Overflow! Cannot push.\n");
        return;
    }
    arr[++top] = num;  // Increment top and insert element
    printf("Pushed: %d\n", num);
}

// Pop function
int StackADT::pop() {
    if (top < 0) {
        return -1;  // Stack is empty
    }
    return arr[top--];  // Return top element and decrement top
}

// Peek function
int StackADT::peek() {
    if (top < 0) {
        return -1;  // Stack is empty
    }
    return arr[top];  // Return top element without removing
}
