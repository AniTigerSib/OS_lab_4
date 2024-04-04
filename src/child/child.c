#include "child.h"

int main() {
    int* sequence = NULL;
    int buff_int, size = 0;
    int flag = FLAG_IS_NORMAL;
    char buff_char = '\0';

    if (scanf("%d", &size) != 1) {
        printf("Error: expected size of sequence in following format: {integer num}{\\n}\n");
    } else {
        for (int i = 0; i < size && !flag; i++) {
            if (scanf("%d%c", &buff_int, &buff_char) != 2) {
                printf("Error: expected data in following format: {integer num}{space}\n");
                flag = FLAG_IS_ERROR;
            } else if (buff_char != ' ' && buff_char != '\n') {
                printf("Error: expected %d or %d, got %d\n", ' ', '\n', buff_char);
                flag = FLAG_IS_ERROR;
            } else {
                sequence = (int*) realloc(sequence, (i + 1) * sizeof(int));
                sequence[i] = buff_int;
            }
        }
        if (sequence == NULL) {
            printf("Error: empty sequence or some problems here");
        } else {
            printf("Sequence: ");
            PrintSequence(sequence, size);
            printf("\n\nSorted sequence: ");
            if (flag == FLAG_IS_NORMAL) {
                Qsort(sequence, size);
                PrintSequence(sequence, size);
            }
            free(sequence);
        }
    }
    exit(flag);
}