#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
    int isThreaded;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    node->isThreaded = 0;
    return node;
}

void inorder(struct Node* root) {
    struct Node* curr = root;
    while (curr != NULL) {
        if (curr->left == NULL) {
            printf("%d ", curr->data);
            curr = curr->right;
        } else {
            struct Node* pre = curr->left;
            while (pre->right != NULL && pre->right != curr)
                pre = pre->right;

            if (pre->right == NULL) {
                pre->right = curr;
                curr = curr->left;
            } else {
                pre->right = NULL;
                printf("%d ", curr->data);
                curr = curr->right;
            }
        }
    }
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    root->left->left->right = root->left;
    root->left->right->right = root;

    printf("Inorder traversal of threaded binary tree: ");
    inorder(root);

    return 0;
}

// Explanation:

// Threaded Binary Tree is a binary tree in which every node's right child points to the inorder successor (or to the inorder predecessor) of the node.
// The newNode function creates a new node with the given data and initializes its left and right children to NULL.
// The inorder function performs an inorder traversal of the threaded binary tree using threading to find the next node to visit.