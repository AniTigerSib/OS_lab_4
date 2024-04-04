#include "sequence_functions.h"

void Swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void Qsort(int* arr, int n) {
    if (n <= 1) return;
    int pivot = arr[n / 2];
    int i = -1;
    int j = n;
    while (1) {
        do i++; while (arr[i] < pivot);
        do j--; while (arr[j] > pivot);
        if (i >= j) break;
        Swap(&arr[i], &arr[j]);
    }
    Qsort(arr, i);
    Qsort(arr + i, n - i);
}

void PrintSequence(int* sequence, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", sequence[i]);
    }
    printf("\n");
}

void PrintSeqIntoStreamByDescryptor(int *sequence, int size, int fd) {
    for (int i = 0; i < size; i++) {
        dprintf(fd, "%d ", sequence[i]);
    }
}

void FillArrayWithRandomNumbers(int *arr, int size) {
    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Заполнение случайными числами в диапазоне от 0 до 99
    }
}