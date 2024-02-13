#include <stdio.h>
#include <stdlib.h>

#define MAX_KEYS 3
#define MAX_CHILDREN MAX_KEYS+1

struct BTreeNode {
    int keys[MAX_KEYS];
    struct BTreeNode* children[MAX_CHILDREN];
    int num_keys;
    int is_leaf;
};

struct BTreeNode* createNode() {
    struct BTreeNode* newNode = (struct BTreeNode*)malloc(sizeof(struct BTreeNode));
    newNode->num_keys = 0;
    newNode->is_leaf = 1;
    return newNode;
}

void insertNonFull(struct BTreeNode* node, int key) {
    int i = node->num_keys - 1;
    if (node->is_leaf) {
        while (i >= 0 && node->keys[i] > key) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->num_keys++;
    } else {
        while (i >= 0 && node->keys[i] > key)
            i--;

        if (node->children[i + 1]->num_keys == MAX_KEYS) {
            splitChild(node, i + 1, node->children[i + 1]);
            if (node->keys[i + 1] < key)
                i++;
        }
        insertNonFull(node->children[i + 1], key);
    }
}

void splitChild(struct BTreeNode* parent, int index, struct BTreeNode* child) {
    struct BTreeNode* newNode = createNode();
    newNode->is_leaf = child->is_leaf;
    newNode->num_keys = MAX_KEYS / 2;

    for (int i = 0; i < MAX_KEYS / 2; i++)
        newNode->keys[i] = child->keys[i + MAX_KEYS / 2];

    if (!child->is_leaf) {
        for (int i = 0; i < MAX_CHILDREN / 2; i++)
            newNode->children[i] = child->children[i + MAX_CHILDREN / 2];
    }

    child->num_keys = MAX_KEYS / 2;

    for (int i = parent->num_keys; i > index; i--)
        parent->children[i + 1] = parent->children[i];

    parent->children[index + 1] = newNode;

    for (int i = parent->num_keys - 1; i >= index; i--)
        parent->keys[i + 1] = parent->keys[i];

    parent->keys[index] = child->keys[MAX_KEYS / 2];

    parent->num_keys++;
}

void insert(struct BTreeNode** root, int key) {
    struct BTreeNode* node = *root;

    if (node->num_keys == MAX_KEYS) {
        struct BTreeNode* newNode = createNode();
        newNode->is_leaf = 0;
        newNode->children[0] = node;
        *root = newNode;
        splitChild(newNode, 0, node);
        insertNonFull(newNode, key);
    } else {
        insertNonFull(node, key);
    }
}

void inorder(struct BTreeNode* root) {
    if (root) {
        for (int i = 0; i < root->num_keys; i++) {
            inorder(root->children[i]);
            printf("%d ", root->keys[i]);
        }
        inorder(root->children[root->num_keys]);
    }
}

int main() {
    struct BTreeNode* root = createNode();
    insert(&root, 10);
    insert(&root, 20);
    insert(&root, 5);
    insert(&root, 6);
    insert(&root, 12);
    insert(&root, 30);

    printf("Inorder traversal of the B-Tree is:\n");
    inorder(root);

    return 0;
}


// Explanation:

// A B-Tree is a self-balancing tree data structure that maintains sorted data and allows searches, sequential access, insertions, and deletions in logarithmic time.
// The insert function inserts a key into the B-Tree while maintaining the B-Tree properties.
// The splitChild function splits a full child node into two nodes during insertion.
// The inorder function performs an inorder traversal of the B-Tree to print its keys in sorted order.