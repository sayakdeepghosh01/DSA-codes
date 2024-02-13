#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_KEYS 3

struct BPlusTreeNode {
    int keys[MAX_KEYS];
    struct BPlusTreeNode* children[MAX_KEYS + 1];
    struct BPlusTreeNode* next;
    int num_keys;
};

struct BPlusTreeNode* createNode() {
    struct BPlusTreeNode* newNode = (struct BPlusTreeNode*)malloc(sizeof(struct BPlusTreeNode));
    newNode->num_keys = 0;
    newNode->next = NULL;
    return newNode;
}

bool isLeaf(struct BPlusTreeNode* node) {
    return (node->children[0] == NULL);
}

struct BPlusTreeNode* splitNode(struct BPlusTreeNode* parent, int index, struct BPlusTreeNode* child) {
    struct BPlusTreeNode* newNode = createNode();
    newNode->next = child->next;
    child->next = newNode;

    for (int i = 0; i < MAX_KEYS / 2; i++) {
        newNode->keys[i] = child->keys[i + MAX_KEYS / 2];
        newNode->children[i] = child->children[i + MAX_KEYS / 2];
    }
    newNode->children[MAX_KEYS / 2] = child->children[MAX_KEYS];

    child->num_keys = MAX_KEYS / 2;
    newNode->num_keys = MAX_KEYS / 2;

    for (int i = parent->num_keys; i > index; i--) {
        parent->keys[i] = parent->keys[i - 1];
        parent->children[i + 1] = parent->children[i];
    }

    parent->keys[index] = newNode->keys[0];
    parent->children[index + 1] = newNode;

    parent->num_keys++;

    return parent;
}

struct BPlusTreeNode* insertInternal(struct BPlusTreeNode* node, int key) {
    if (isLeaf(node)) {
        int i = node->num_keys - 1;
        while (i >= 0 && node->keys[i] > key) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->num_keys++;
        return node;
    }

    int i = 0;
    while (i < node->num_keys && node->keys[i] < key)
        i++;

    if (node->children[i]->num_keys == MAX_KEYS) {
        node = splitNode(node, i, node->children[i]);
        if (node->keys[i] < key)
            i++;
    }

    node->children[i] = insertInternal(node->children[i], key);
    return node;
}

struct BPlusTreeNode* insert(struct BPlusTreeNode* root, int key) {
    if (root == NULL) {
        root = createNode();
        root->keys[0] = key;
        root->num_keys = 1;
        return root;
    }

    if (root->num_keys == MAX_KEYS) {
        struct BPlusTreeNode* newNode = createNode();
        newNode->next = root;
        splitNode(newNode, 0, root);
        root = newNode;
    }

    root = insertInternal(root, key);
    return root;
}

void inorder(struct BPlusTreeNode* root) {
    if (root) {
        for (int i = 0; i < root->num_keys; i++) {
            inorder(root->children[i]);
            printf("%d ", root->keys[i]);
        }
        inorder(root->children[root->num_keys]);
    }
}

int main() {
    struct BPlusTreeNode* root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 12);
    root = insert(root, 30);

    printf("Inorder traversal of the B+ Tree is:\n");
    inorder(root);

    return 0;
}


// Explanation:

// A B+ Tree is a self-balancing tree data structure that maintains sorted data and allows searches, sequential access, insertions, and deletions in logarithmic time.
// B+ Trees are similar to B-Trees but have some differences in their internal structure, such as having all keys in the leaf nodes and having leaf nodes connected in a linked list for range queries.
// The insert function inserts a key into the B+ Tree while maintaining the B+ Tree properties.
// The splitNode function splits a full child node into two nodes during insertion.
// The inorder function performs an inorder traversal of the B+ Tree to print its keys in sorted order.



