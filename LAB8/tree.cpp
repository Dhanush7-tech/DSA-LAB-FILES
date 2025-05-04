#include <stdio.h>
#include <stdlib.h>

// Node structure for the binary tree
struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

// Tree ADT class
class TreeADT {
private:
    Node* root;

public:
    // Constructor
    TreeADT() {
        root = NULL;
    }

    // Function prototypes
    void insert(char data);
    void preorder();
    void inorder();
    void postorder();
    bool search(char key);

private:
    Node* insert(Node* node, char data);
    void preorder(Node* node);
    void inorder(Node* node);
    void postorder(Node* node);
    bool search(Node* node, char key);
};

// Main function with menu-driven approach
int main() {
    TreeADT tree;
    int choice;
    char data;

    do {
        printf("\nMENU:\n");
        printf("1) Insert\n2) Preorder\n3) Inorder\n4) Postorder\n5) Search\n6) Exit\n");
        printf("Enter your choice: ");
        scanf(" %d", &choice);

        switch (choice) {
            case 1:
                printf("Enter character to insert: ");
                scanf(" %c", &data);
                tree.insert(data);
                break;

            case 2:
                printf("Preorder Traversal: ");
                tree.preorder();
                printf("\n");
                break;

            case 3:
                printf("Inorder Traversal: ");
                tree.inorder();
                printf("\n");
                break;

            case 4:
                printf("Postorder Traversal: ");
                tree.postorder();
                printf("\n");
                break;

            case 5:
                printf("Enter character to search: ");
                scanf(" %c", &data);
                if (tree.search(data)) {
                    printf("Character found in the tree.\n");
                } else {
                    printf("Character not found.\n");
                }
                break;

            case 6:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice! Enter a number between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}

// Function to insert a node into the tree
void TreeADT::insert(char data) {
    root = insert(root, data);
}

// Recursive function to insert a node
Node* TreeADT::insert(Node* node, char data) {
    if (node == NULL) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        if (newNode == NULL) {
            printf("Memory allocation failed!\n");
            return node;
        }
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    char choice;
    printf("Insert %c to (L)eft or (R)ight of %c? ", data, node->data);
    scanf(" %c", &choice);

    if (choice == 'L' || choice == 'l') {
        node->left = insert(node->left, data);
    } else {
        node->right = insert(node->right, data);
    }
    return node;
}

// Function to print preorder traversal
void TreeADT::preorder() {
    preorder(root);
}

// Recursive function for preorder traversal
void TreeADT::preorder(Node* node) {
    if (node == NULL) return;
    printf("%c ", node->data);
    preorder(node->left);
    preorder(node->right);
}

// Function to print inorder traversal
void TreeADT::inorder() {
    inorder(root);
}

// Recursive function for inorder traversal
void TreeADT::inorder(Node* node) {
    if (node == NULL) return;
    inorder(node->left);
    printf("%c ", node->data);
    inorder(node->right);
}

// Function to print postorder traversal
void TreeADT::postorder() {
    postorder(root);
}

// Recursive function for postorder traversal
void TreeADT::postorder(Node* node) {
    if (node == NULL) return;
    postorder(node->left);
    postorder(node->right);
    printf("%c ", node->data);
}

// Function to search for a character in the tree
bool TreeADT::search(char key) {
    return search(root, key);
}

// Recursive function to search for a character
bool TreeADT::search(Node* node, char key) {
    if (node == NULL) return false;
    if (node->data == key) return true;
    return search(node->left, key) || search(node->right, key);
}
