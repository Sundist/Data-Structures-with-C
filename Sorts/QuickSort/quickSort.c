//
// Created by Sundist on 17.08.2022.
//
#include <stdio.h>
#include <stdlib.h>

int SIZE = 15;


int partitionFunction(int partition[], int low, int high);

void quickSort(int partition[], int low, int high);

int main() {
    printf("Quick Sort implementation with C\n");
    printf("Unsorted Array: \n");
    int arr[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = rand() % 1000 + 1;
        printf("%d, ", arr[i]);

    }
    printf("\nSorted Array:\n");
    quickSort(arr, 0, SIZE - 1);

    for (int i = 0; i < SIZE; ++i)
        printf("%d, ", arr[i]);

}


int partitionFunction(int partition[], int low, int high) {
    int x = partition[high];
    int i = low - 1;
    for (int j = low; j < high - 1; ++j) {
        if (partition[j] <= x) {
            i++;
            int temp = partition[i];
            partition[i] = partition[j];
            partition[j] = temp;
        }
    }
    int temp = partition[i + 1];
    partition[i + 1] = partition[high];
    partition[high] = temp;
    return i + 1;
}

void quickSort(int partition[], int low, int high) {
    if (low < high) {
        int q = partitionFunction(partition, low, high);
        quickSort(q, low, high - 1);
        quickSort(q, low + 1, high);
    }

}