#include "child.h"

int main() {
    int* sequence = NULL;
    int buff_int, size, flag = 0;
    char buff_char = '\0';
    if (scanf("%d%c", &size, &buff_char) != 2 || buff_char != '\n') {
        printf("Error: expected size of sequence in following format: {integer num}{\\n}\n");
    } else {
        for (int i = 0; i < size && !flag; i++) {
            if (scanf("%d%c", &buff_int, &buff_char) != 2) {
                printf("Error: expected data in following format: {integer num}{space}\n");
                flag = 1;
            } else if (buff_char != ' ' && buff_char != '\n') {
                printf("Error: expected %d or %d, got %d\n", ' ', '\n', buff_char);
                flag = 1;
            } else {
                sequence = (int*) realloc(sequence, (i + 1) * sizeof(int));
                sequence[i] = buff_int;
            }
        }
        if (sequence == NULL) {
            printf("Error: empty sequence or some problems here");
        } else {
            if (flag == 0) {
                Qsort(sequence, size);
                PrintSequence(sequence, size);
            }
            free(sequence);
        }
    }
    exit(flag);
    // return flag;
}