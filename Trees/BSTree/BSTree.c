//
// Created by Sundist on 2.09.2022.
//
#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *add(struct Node *root, int data) {
    if (root == NULL) {
        root = (struct Node *) malloc(sizeof(struct Node));
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        return root;
    }

    if (data < root->data)
        root->left = add(root->left, data);
    else if (data > root->data)
        root->right = add(root->right, data);
    return root;
}

void inOrderTraverse(struct Node *root) {
    if (root != NULL) {
        inOrderTraverse(root->left);
        printf("%d ", root->data);
        inOrderTraverse(root->right);
    }
}

void preOrderTraverse(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderTraverse(root->left);
        preOrderTraverse(root->right);
    }
}

void postOrderTraverse(struct Node *root) {
    if (root != NULL) {
        postOrderTraverse(root->left);
        postOrderTraverse(root->right);
        printf("%d ", root->data);
    }
}

int search(struct Node *root, int data) {
    if (root == NULL)
        return 0;
    else if (root->data == data)
        return 1;
    else {
        if (data < root->data)
            search(root->left, data);
        else if (data > root->data) {
            search(root->right, data);
        }
    }
    return -1;
}

int main() {
    struct Node *root = NULL;
    root = add(root, 65);
    add(root, 86);
    add(root, 6);
    add(root, 48);
    add(root, 18);
    add(root, 94);
    add(root, 4);
    add(root, 15);
    preOrderTraverse(root);
    printf("\n");
    inOrderTraverse(root);
    printf("\n");
    postOrderTraverse(root);
    printf("\n");
    printf("%d", search(root, 66));
}