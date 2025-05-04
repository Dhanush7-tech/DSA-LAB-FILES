#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stack>

using namespace std;

// Node structure for the expression tree
class Node {
public:
    char data;
    Node* left;
    Node* right;
};

// Expression Tree class
class ExpressionTree {
private:
    Node* root;  // Root of the tree

    // Private helper functions (defined after main)
    Node* createNode(char value);
    bool isOperator(char ch);
    void inorderRec(Node* node);
    void preorderRec(Node* node);
    void postorderRec(Node* node);

public:
    ExpressionTree(); // Constructor
    void constructTree(char postfix[]);
    void inorder();
    void preorder();
    void postorder();
};

// Main function
int main() {
    ExpressionTree expTree;
    int choice;
    char postfix[50];

    while (1) {
        printf("\n1. Enter Postfix Expression\n2. Construct Expression Tree\n3. Preorder Traversal\n4. Inorder Traversal\n5. Postorder Traversal\n6. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a valid postfix expression: ");
                scanf("%s", postfix);
                break;
            case 2:
                expTree.constructTree(postfix);
                printf("Expression tree constructed successfully.\n");
                break;
            case 3:
                printf("Preorder Traversal: ");
                expTree.preorder();
                break;
            case 4:
                printf("Inorder Traversal: ");
                expTree.inorder();
                break;
            case 5:
                printf("Postorder Traversal: ");
                expTree.postorder();
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
ExpressionTree::ExpressionTree() {
    root = NULL;
}

// Creates a new node with the given character
Node* ExpressionTree::createNode(char value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Checks if a character is an operator (+, -, *, /)
bool ExpressionTree::isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Constructs an expression tree from the given postfix expression
void ExpressionTree::constructTree(char postfix[]) {
    stack<Node*> st;
    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        // If the character is an operand, push it into the stack
        if (isalnum(ch)) {
            st.push(createNode(ch));
        }
        // If the character is an operator, pop two elements and create a new node
        else if (isOperator(ch)) {
            Node* newNode = createNode(ch);
            newNode->right = st.top(); st.pop();
            newNode->left = st.top(); st.pop();
            st.push(newNode);
        }
    }

    // The final element in the stack is the root of the expression tree
    root = st.top();
}

// Inorder Traversal (Left, Root, Right)
void ExpressionTree::inorder() {
    inorderRec(root);
    printf("\n");
}

// Recursive function for inorder traversal
void ExpressionTree::inorderRec(Node* node) {
    if (node == NULL) return;
    
    // Print '(' for readability
    if (isOperator(node->data)) printf("(");
    
    inorderRec(node->left);
    printf("%c ", node->data);
    inorderRec(node->right);

    // Print ')' for readability
    if (isOperator(node->data)) printf(")");
}

// Preorder Traversal (Root, Left, Right)
void ExpressionTree::preorder() {
    preorderRec(root);
    printf("\n");
}

// Recursive function for preorder traversal
void ExpressionTree::preorderRec(Node* node) {
    if (node == NULL) return;
    printf("%c ", node->data);
    preorderRec(node->left);
    preorderRec(node->right);
}

// Postorder Traversal (Left, Right, Root)
void ExpressionTree::postorder() {
    postorderRec(root);
    printf("\n");
}

// Recursive function for postorder traversal
void ExpressionTree::postorderRec(Node* node) {
    if (node == NULL) return;
    postorderRec(node->left);
    postorderRec(node->right);
    printf("%c ", node->data);
}
