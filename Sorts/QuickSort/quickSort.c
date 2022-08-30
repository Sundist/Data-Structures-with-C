//
// Created by Sundist on 17.08.2022.
//
#include <stdio.h>

int SIZE = 15;

void sort(int arr[]);

int partition(int partition[], int low, int high);

void quickSort(int partition[], int low, int high);

int main() {
    printf("Quick Sort implementation with C\n");
    printf("Unsorted Array: \n");
    int arr[SIZE];
    for (int i = 0; i < SIZE; ++i)
        printf("%d, ", arr[i]);
    sort(arr);

}


void sort(int arr[]) {
    printf("\nSorted Array:\n");
    quickSort(arr, 0, (sizeof(arr) / sizeof(int)) - 1);
}

int partition(int partition[], int low, int high) {
    return 1;
}

void quickSort(int partition[], int low, int high) {

}