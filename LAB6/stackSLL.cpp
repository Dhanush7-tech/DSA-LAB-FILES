#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    char data;
    Node* next;
};

// Stack ADT class using a linked list
class StackADT {
private:
    Node* top; // Pointer to the top of the stack

public:
    // Constructor
    StackADT() {
        top = NULL; // Stack is initially empty
    }

    void push(char ch);  // Push operation
    char pop();          // Pop operation
    char peek();         // Peek operation
};

// Main function with menu-driven approach
int main() {
    StackADT stack;
    int choice;
    char result, ch;

    do {
        printf("\nMENU:\n1) Push\n2) Pop\n3) Peek\n4) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Consume newline left by scanf

        switch (choice) {
            case 1:
                printf("Enter the character to push: ");
                scanf("%c", &ch);
                stack.push(ch);
                break;

            case 2:
                result = stack.pop();
                if (result != '\0') {
                    printf("Popped element: %c\n", result);
                } else {
                    printf("Stack is empty. Cannot pop.\n");
                }
                break;

            case 3:
                result = stack.peek();
                if (result != '\0') {
                    printf("Top element: %c\n", result);
                } else {
                    printf("Stack is empty.\n");
                }
                break;

            case 4:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice! Enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}

// Push function
void StackADT::push(char ch) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed! Cannot push.\n");
        return;
    }
    newNode->data = ch;
    newNode->next = top; // Link new node to the current top
    top = newNode;       // Update top
    printf("Pushed: %c\n", ch);
}

// Pop function
char StackADT::pop() {
    if (top == NULL) {
        return '\0'; // Stack is empty, return null character
    }
    Node* temp = top;  // Store the current top
    char poppedData = temp->data;
    top = top->next;   // Move top to the next node
    free(temp);        // Free the old top node
    return poppedData;
}

// Peek function
char StackADT::peek() {
    if (top == NULL) {
        return '\0'; // Stack is empty, return null character
    }
    return top->data; // Return top element without removing
}


