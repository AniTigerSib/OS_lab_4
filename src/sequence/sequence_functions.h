#ifndef SORTING_ALG_H
#define SORTING_ALG_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Swap(int* a, int* b);
void Qsort(int* arr, int n);
void PrintSequence(int* sequence, int size);
void FillArrayWithRandomNumbers(int *arr, int size);

#endif