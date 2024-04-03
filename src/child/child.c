#include <stdio.h>
#include <stdlib.h>

#include "sorting_alg.h"

void PrintSequence(int* sequence, int size);

int main() {
    int* sequence = NULL;
    int buff_int, size, flag = 0;
    char buff_char = '\0';
    while (!feof(stdin) && !flag) {
        if (scanf("%d%c", &buff_int, &buff_char) != 2) {
            printf("Error: expected data in following format: {integer num}{space}\n");
            flag = 1;
        } else if (buff_char != ' ' || buff_char != '\n') {
            printf("Error: expected space, got %c\n", buff_char);
            flag = 1;
        } else {
            sequence = (int*) realloc(sequence, (size + 1) * sizeof(int));
            sequence[size] = buff_int;
            size++;
            if (buff_char == '\n') {
                flag = 2;
            }
        }
    }
    if (flag == 2) {
        flag = 0;
        Qsort(sequence, size);
    }
    return flag;
}

void PrintSequence(int* sequence, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", sequence[i]);
    }
    printf("\n");
}