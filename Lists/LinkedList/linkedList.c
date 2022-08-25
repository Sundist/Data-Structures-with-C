//
// Created by Sundist on 25.08.2022.
//

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};


void getSize(struct Node *list) {
    if (list == NULL)
        printf("List is empty\n");
    struct Node *iter = list;
    int counter = 0;
    while (iter != NULL) {
        iter = iter->next;
        counter++;
    }
    printf("List's size is: %d\n", counter);
}

void printList(struct Node *node) {
    struct Node *iter = node;
    while (iter != NULL) {
        printf("%d -> ", iter->data);
        iter = iter->next;
    }
    printf("NULL\n");
}

struct Node *add(struct Node *node, int value) {
    if (node == NULL) {
        node = (struct Node *) malloc(sizeof(struct Node));
        node->data = value;
        node->next = NULL;
    }
    struct Node *iter = node;
    while (iter->next != NULL)
        iter = iter->next;

    iter->next = (struct Node *) malloc(sizeof(struct Node));
    iter->next->data = value;
    iter->next->next = NULL;
    return node;
}

struct Node *delete(struct Node *node, int value) {
    struct Node *iter = node;
    while (iter->next->data != value && iter->next != NULL)
        iter = iter->next;

    struct Node *temp = iter;
    temp->next = iter->next->next;
    iter->next = temp->next;
    free(temp);
    return node;
}

struct Node *deleteAt(struct Node *node, int index) {
    struct Node *iter = node;
    int counter = 0;
    while (counter != index - 1) {
        iter = iter->next;
        counter++;
    }
    struct Node *temp = iter;
    temp->next = iter->next->next;
    iter->next = temp->next;
    free(temp);
    return node;
}

int main() {
    struct Node *head = (struct Node *) malloc(sizeof(struct Node));
    head->data = 42;
    head->next = (struct Node *) malloc(sizeof(struct Node));
    head->next->data = 53;
    head->next->next = (struct Node *) malloc(sizeof(struct Node));
    head->next->next->data = 81;
    head->next->next->next = NULL;
    add(head, 6664);
    add(head, 6616);
    add(head, 6626);
    getSize(head);
    printList(head);
    delete(head, 6616);
    getSize(head);
    printList(head);
    deleteAt(head, 3);
    getSize(head);
    printList(head);
}
