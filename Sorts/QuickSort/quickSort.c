//
// Created by Sundist on 17.08.2022.
//
#include <stdio.h>

void sort(int arr[]);

int partition(int partition[], int low, int high);

void quickSort(int partition[], int low, int high);

int main() {
    printf("Quick Sort implementation with C");
}


void sort(int arr[]) {
    quickSort(arr, 0, (sizeof(arr) / sizeof(int)) - 1);
}

int partition(int partition[], int low, int high) {
    return 1;
}

void quickSort(int partition[], int low, int high) {

}