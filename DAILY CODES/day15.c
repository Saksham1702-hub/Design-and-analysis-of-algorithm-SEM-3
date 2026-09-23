#include <stdio.h>
#include <stdlib.h>

// Structure of a tree node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* createNode(int data) {

    // Allocate memory for a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Store data
    newNode->data = data;

    // Initially, no children
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Inorder Traversal: Left -> Root -> Right
void inorder(struct Node* root) {

    // Stop when there is no node
    if (root == NULL)
        return;

    // 1. Visit left subtree
    inorder(root->left);

    // 2. Visit root
    printf("%d ", root->data);

    // 3. Visit right subtree
    inorder(root->right);
}

int main() {

    // Create root
    struct Node* root = createNode(4);

    // Create left and right children
    root->left = createNode(2);
    root->right = createNode(6);

    // Create children of 2
    root->left->left = createNode(1);
    root->left->right = createNode(3);

    // Create children of 6
    root->right->left = createNode(5);
    root->right->right = createNode(7);

    printf("Inorder Traversal: ");

    // Perform inorder traversal
    inorder(root);

    return 0;
}