//
// Created by Sundist on 30.09.2022.
//

#include <stdio.h>


int SIZE = 0;
int CAPACITY = 15;

void add(int array, int element);

int remove(int array);

int main() {
    int list[CAPACITY];

}

void add(int[] array, int element) {
    array = add(arry, element);
    int index = SIZE - 1;
    while (1) {

    }

}

int remove(int[] array) {
    // son eleman ılk elemana atanacak
    array[0] = array[SIZE - 1];
    // son eleman arryden cıkartılacak
    array[SIZE - 1] = NULL;
    // dongu ıcınde ıkı cocuk bulunup  bırınden daha kucukse buyuk olanla yer degıstırılecek

    for (int i = 0; i < SIZE; ++i) {
        int leftChild = array[2 * i + 1];
        int rightChild = array[2 * i + 2];
        if (rightChild < leftChild) {
            int temp = leftChild;
            leftChild = rightChild;
            rightChild = temp;
        }
    }
    // left yok right yok
    // break
    // left var right yok
    // //left küçük -> break
    // //left büyük -> swap
    //ikisi de var
    // //buyuk olanı bul
    // // //buyuk olan benden kucuk -> break
    // // // buyuk olan benden buyuk -> swap
}