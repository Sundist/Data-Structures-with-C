//
// Created by Sundist on 25.08.2022.
//
#include <stdio.h>

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
    if (SIZE + 1 < DEFAULT_CAPACITY)
        arr[SIZE + 1] = value;
    else {
        int arr2[DEFAULT_CAPACITY * 2];
        for (int i = 0; i < SIZE; ++i)
            arr2[i] = arr[i];
        arr2[SIZE + 1] = value;
        arr[DEFAULT_CAPACITY * 2];
        for (int i = 0; i < SIZE; ++i)
            arr[i] = arr2[i];
    }
    SIZE++;
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