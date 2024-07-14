#include <stdio.h>
#include <stdlib.h>

struct avl {
    int data;
    struct avl *left, *right;
    int height;
};

struct avl *createnode(int x) {
    struct avl *new = (struct avl *)malloc(sizeof(struct avl));
    new->data = x;
    new->left = NULL;
    new->right = NULL;
    new->height = 1;
    return new;
}

int max(int a, int b) {
    return (a > b ? a : b);
}

int getHeight(struct avl *node) {
    if (node == NULL)
        return 0;
    return node->height;
}

int balancefactor(struct avl *node) {
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

struct avl *leftrotate(struct avl *y) {
    struct avl *x = y->right;
    struct avl *T2 = x->left;

    x->left = y;
    y->right = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

struct avl *rightrotate(struct avl *x) {
    struct avl *y = x->left;
    struct avl *T2 = y->right;

    y->right = x;
    x->left = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

struct avl *insert(struct avl *node, int x) {
    if (node == NULL)
        return createnode(x);

    if (x < node->data)
        node->left = insert(node->left, x);
    else if (x > node->data)
        node->right = insert(node->right, x);
    else // Duplicate keys are not allowed in AVL trees
        return node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int bf = balancefactor(node);

    // Left Left
    if (bf > 1 && x < node->left->data)
        return rightrotate(node);

    // Right Right
    if (bf < -1 && x > node->right->data)
        return leftrotate(node);

    // Left Right
    if (bf > 1 && x > node->left->data) {
        node->left = leftrotate(node->left);
        return rightrotate(node);
    }

    // Right Left
    if (bf < -1 && x < node->right->data) {
        node->right = rightrotate(node->right);
        return leftrotate(node);
    }

    return node;
}

void preorder(struct avl *node) {
    if (node == NULL)
        return;
    printf("%d\t", node->data);
    preorder(node->left);
    preorder(node->right);
}

int main() {
    struct avl *root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);

    preorder(root);

    return 0;
}
