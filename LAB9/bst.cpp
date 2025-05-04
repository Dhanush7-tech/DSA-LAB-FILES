#include <stdio.h>
#include <stdlib.h>

// Node structure for the Binary Search Tree
class Node {
public:
    int data;
    Node* left;
    Node* right;
};

// Binary Search Tree class
class BST {
private:
    Node* root; // Root of the BST

    // Private helper functions (definitions after main)
    Node* createNode(int value);
    Node* insertRec(Node* node, int value);
    void inorderRec(Node* node);
    void preorderRec(Node* node);
    void postorderRec(Node* node);
    bool searchRec(Node* node, int value);

public:
    BST(); // Constructor
    void insert(int value);
    void inorder();
    void preorder();
    void postorder();
    bool search(int value);
};

// Main function
int main() {
    BST tree;
    int choice, value;

    while (1) {
        printf("\n1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Search\n6. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                printf("Enter value to insert: ");
                scanf("%d", &value);
                tree.insert(value);
                break;
            case 2: 
                printf("Preorder Traversal: ");
                tree.preorder(); 
                break;
            case 3: 
                printf("Inorder Traversal: ");
                tree.inorder(); 
                break;
            case 4: 
                printf("Postorder Traversal: ");
                tree.postorder(); 
                break;
            case 5:
                printf("Enter value to search: ");
                scanf("%d", &value);
                printf("%s\n", tree.search(value) ? "Found" : "Not Found");
                break;
            case 6: 
                printf("Exiting program...\n");
                return 0;
            default: 
                printf("Invalid choice! Please enter a number between 1 and 6.\n");
        }
    }
}

// Function Definitions

// Constructor: Initializes the root node as NULL
BST::BST() {
    root = NULL;
}

// Creates a new node with the given value
Node* BST::createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Inserts a new value into the BST
void BST::insert(int value) {
    root = insertRec(root, value);
}

// Recursive function to insert a value in the correct position
Node* BST::insertRec(Node* node, int value) {
    if (node == NULL) 
        return createNode(value);

    if (value < node->data) 
        node->left = insertRec(node->left, value);
    else 
        node->right = insertRec(node->right, value);

    return node;
}

// Prints the BST in Inorder (Left, Root, Right)
void BST::inorder() {
    inorderRec(root);
    printf("\n");
}

// Recursive function for inorder traversal
void BST::inorderRec(Node* node) {
    if (node == NULL) 
        return;

    inorderRec(node->left);
    printf("%d ", node->data);
    inorderRec(node->right);
}

// Prints the BST in Preorder (Root, Left, Right)
void BST::preorder() {
    preorderRec(root);
    printf("\n");
}

// Recursive function for preorder traversal
void BST::preorderRec(Node* node) {
    if (node == NULL) 
        return;

    printf("%d ", node->data);
    preorderRec(node->left);
    preorderRec(node->right);
}

// Prints the BST in Postorder (Left, Right, Root)
void BST::postorder() {
    postorderRec(root);
    printf("\n");
}

// Recursive function for postorder traversal
void BST::postorderRec(Node* node) {
    if (node == NULL) 
        return;

    postorderRec(node->left);
    postorderRec(node->right);
    printf("%d ", node->data);
}

// Searches for a value in the BST
bool BST::search(int value) {
    return searchRec(root, value);
}

// Recursive function to search for a value
bool BST::searchRec(Node* node, int value) {
    if (node == NULL) 
        return false;

    if (node->data == value) 
        return true;

    return (value < node->data) ? searchRec(node->left, value) : searchRec(node->right, value);
}
