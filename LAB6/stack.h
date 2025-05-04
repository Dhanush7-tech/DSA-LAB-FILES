#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

// Node structure for the stack
struct Node {
    char data;
    struct Node* next;
};

// Stack class using singly linked list
class Stack {
private:
    Node* top;

public:
    Stack() { top = NULL; }

    void push(char value) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        if (!newNode) {
            printf("Stack overflow\n");
            return;
        }
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    char pop() {
        if (isEmpty()) {
            printf("Stack underflow\n");
            return '\0';
        }
        Node* temp = top;
        char popped = top->data;
        top = top->next;
        free(temp);
        return popped;
    }

    char peek() {
        if (isEmpty()) return '\0';
        return top->data;
    }

    bool isEmpty() {
        return top == NULL;
    }
};

#endif
