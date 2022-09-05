//
// Created by Sundist on 2.09.2022.
//

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

int getSize(struct Node *node) {
    if (node == NULL)
        return 0;
    int counter = 0;
    struct Node *iter = node;
    while (iter != NULL) {
        counter++;
        iter = iter->next;
    }
    return counter;
}

void printList(struct Node *node) {
    if (node == NULL)
        printf("List is EMPTY");

    struct Node *iter = node;
    printf("NULL <-> ");
    while (iter != NULL) {
        printf("%d <-> ", iter->data);
        iter = iter->next;
    }
    printf("NULL\n");
}

struct Node *add(struct Node *node, int value) {
    if (node == NULL) {
        node = (struct Node *) malloc(sizeof(struct Node));
        node->data = value;
        node->prev = NULL;
        node->next = NULL;
        return node;
    }
    struct Node *iter = node;
    while (iter->next != NULL)
        iter = iter->next;

    struct Node *temp = (struct Node *) malloc(sizeof(struct Node));
    temp->next = NULL;
    temp->prev = iter;
    iter->next = temp;
    temp->data = value;

    return node;
}

struct Node *delete(struct Node *node, int value) {
    if (node == NULL)
        return node;

    struct Node *iter = node;
    while (iter->next->data != value && iter->next != NULL)
        iter = iter->next;
    struct Node *temp = iter;
    temp->next = iter->next->next;
    iter->next = temp->next;
    free(temp);

    return node;
}

struct Node *deleteAt(struct Node *node, int index);

int main() {
    struct Node *head = (struct Node *) malloc(sizeof(struct Node));
    head->next = NULL;
    head->prev = NULL;
    head->data = 42;
    for (int i = 0; i < 5; ++i)
        add(head, rand() % 10000 + 1);
    add(head, 111);
    for (int i = 0; i < 5; ++i)
        add(head, rand() % 10000 + 1);
    printList(head);
    printf("Size of the Doubly Llinked List is: %d\n", getSize(head));

    head = delete(head, 111);
    printList(head);
    printf("Size of the Doubly Llinked List is: %d\n", getSize(head));


}
