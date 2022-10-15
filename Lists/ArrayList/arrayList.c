//
// Created by Sundist on 25.08.2022.
//
#include <stdio.h>
#include <stdlib.h>

int DEFAULT_CAPACITY = 16;
int SIZE = 0;

int getSize() {
    return SIZE;
}

void printArrayList(int arr[]) {
    printf("[");
    for (int j = 0; j < SIZE; ++j)
        printf("%d, ", arr[j]);

    printf("]\n");
}

int add(int arr[], int value) {
    if (SIZE >= DEFAULT_CAPACITY) {
        int arr2[] = malloc(sizeof(int) * DEFAULT_CAPACITY * 2);
        for (int i = 0; i < SIZE; ++i)
            arr2[i] = arr[i];
        arr = arr2;
        DEFAULT_CAPACITY *= 2;
    }

    arr[SIZE++] = value;
    return *arr;
}

int delete(int arr[], int value) {
    int index = 0;
    while (arr[index] != value)
        index++;
    for (int i = index; i < SIZE; ++i)
        arr[i] = arr[i + 1];
    SIZE--;
    return *arr;
}

int main() {
    int array[DEFAULT_CAPACITY];
    for (int i = 0; i < DEFAULT_CAPACITY; i++)
        add(array, i * 6 + 7);

    printf("%d\n", getSize());
    printArrayList(array);

    delete(array, 31);
    printf("%d\n", getSize());
    printArrayList(array);
}