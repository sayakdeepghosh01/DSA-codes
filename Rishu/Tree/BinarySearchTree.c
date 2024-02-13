#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* node, int key) {
    if (node == NULL) return newNode(key);

    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);

    return node;
}

struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (root->data < key)
        return search(root->right, key);

    return search(root->left, key);
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal of binary search tree: ");
    inorder(root);

    int key = 40;
    if (search(root, key) != NULL)
        printf("\n%d found in BST", key);
    else
        printf("\n%d not found in BST", key);

    return 0;
}


// Explanation:

// Binary Search Tree (BST) is a binary tree in which the value of each node's left child is less than the value of the node and the value of each node's right child is greater than the value of the node.
// The insert function inserts a new node with the given key into the BST.
// The search function searches for a key in the BST and returns the node if found, otherwise returns NULL.
// The inorder function performs an inorder traversal of the BST, which results in a sorted sequence of node values.
