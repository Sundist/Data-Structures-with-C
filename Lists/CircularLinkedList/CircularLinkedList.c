//
// Created by Sundist on 2.09.2022.
//

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int getSize(struct Node *node) {
    if (node == NULL)
        return 0;
    struct Node *iter = node;
    iter = iter->next;
    int counter = 1;
    while (iter != node) {
        counter++;
        iter = iter->next;
    }
    return counter;
}

void printList(struct Node *node) {
    if (node == NULL)
        printf("Linked List is EMPTY!\n");
    struct Node *iter = node;
    printf("%d-> ", node->data);
    while (iter->next != node) {
        iter = iter->next;
        printf("%d-> ", iter->data);
    }
    printf("%d\n", node->data);
}

struct Node *add(struct Node *node, int value) {
    if (node == NULL) {
        node = (struct Node *) malloc(sizeof(struct Node));
        node->data = value;
        node->next = node;
        return node;
    }

    struct Node *iter = node;
    while (iter->next != node)
        iter = iter->next;
    struct Node *temp = (struct Node *) malloc(sizeof(struct Node));
    temp->next = node;
    temp->data = value;
    iter->next = temp;
    return node;
}

struct Node *delete(struct Node *node, int value) {
    if (node == NULL)
        return node;
    struct Node *iter = node;
    while (iter->next->data != value)
        iter = iter->next;
    struct Node *temp = iter;
    temp->next = iter->next->next;
    iter->next = temp->next;
    free(temp);
    return node;
}


struct Node *deleteAt(struct Node *node, int index) {
    if (node == NULL)
        return node;
    struct Node *iter = node;
    int counter = 1;
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
    struct Node *head = NULL;

    head = add(head, rand() % 10000);
    for (int i = 0; i < 5; ++i)
        add(head, rand() % 10000);

    add(head, 111);
    for (int i = 0; i < 5; ++i)
        add(head, rand() % 10000);

    printf("%d\n", getSize(head));
    printList(head);

    head = delete(head, 111);
    printf("%d\n", getSize(head));
    printList(head);

}

