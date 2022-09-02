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
        root = (struct Node *) malloc(sizeof(struct Node *));
        root->left = NULL;
        root->right = NULL;
        root->data = data;
    }
    if (data < root->data)
        root = add(root->left, data);
    else if (data > root->data)
        root= add(root->right, data);
    return root;
}

int search(struct Node *root, int data) {
    if (root == NULL)
        return -1;
    if (data > root->data)
        search(root->right, data);
    else if (data < root->data)
        search(root->left, data);
    else return 1;
    return 0;

}


int main() {
    struct Node *root = (struct Node *) malloc(sizeof(struct Node *));
    root->data = 42;
    root->right = NULL;
    root->left = NULL;
    root = add(root, 86);
    root = add(root, 6);
    root = add(root, 48);
    root = add(root, 18);
    printf("%d \n", search(root, 6));
}