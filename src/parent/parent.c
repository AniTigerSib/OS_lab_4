#include "parent.h"
#include "../sequence/sequence_functions.h"

int main() {
    int fd[2];
    pipe(fd); // Creating a pipe
    pid_t pid = fork();

    if (pid < CHILD_PROCESS_PID) {
        printf("Error: fork failed\n");
    } else if (pid == CHILD_PROCESS_PID) { // Child process
        dup2(fd[0], STDIN_FILENO);
        close(fd[1]);
        ChildFunc();
    } else {
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);

        int sequence[SIZE_OF_SEQUENCE] = {0};
        FillArrayWithRandomNumbers(sequence, SIZE_OF_SEQUENCE);
        PrintSequence(sequence, SIZE_OF_SEQUENCE);

        close(fd[1]);
        wait(NULL); // Waiting for process to stop
    }
    return 0;
}

static void ChildFunc() {
    int* sequence = NULL;
    int buff_int, size = 0;
    int flag = FLAG_IS_NORMAL;
    char buff_char = '\0';

    if (scanf("%d%c", &size, &buff_char) != 2 || buff_char != '\n') {
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
            if (flag == FLAG_IS_NORMAL) {
                Qsort(sequence, size);
                PrintSequence(sequence, size);
            }
            free(sequence);
        }
    }
    exit(flag);
}


// Not actual:

// static int MakeKid(Child *kid) {
//     int pipe_parent_to_kid[2];
//     if (pipe(pipe_parent_to_kid) != 0) {
//         return -1;
//     }
//     if ((kid->pid = fork()) < 0) {
//         close(pipe_parent_to_kid[P_READ]);
//         close(pipe_parent_to_kid[P_WRITE]);
//         return -1;
//     } else if (kid->pid == 0) {
//         dup2(pipe_parent_to_kid[P_READ], STDIN_FILENO);
//         close(pipe_parent_to_kid[P_WRITE]);
//         close(pipe_parent_to_kid[P_READ]);
//         ChildFunc();
//         exit(0);
//     } else {
//         kid->fp_to = fdopen(pipe_parent_to_kid[P_WRITE], "w");
//         close(pipe_parent_to_kid[P_READ]);
//         close(pipe_parent_to_kid[P_WRITE]);
//         return 0;
//     }
// }

// static void ChildFunc() {
//     int* sequence = NULL;
//     int buff_int, size, flag = 0;
//     char buff_char = '\0';
//     while (!feof(stdin) && !flag) {
//         if (fscanf(stdin, "%d%c", &buff_int, &buff_char) != 2) {
//             printf("Error: expected data in following format: {integer num}{space}\n");
//             flag = 1;
//         } else if (buff_char != ' ' || buff_char != '\n') {
//             printf("Error: expected space, got %c\n", buff_char);
//             flag = 1;
//         } else {
//             sequence = (int*) realloc(sequence, (size + 1) * sizeof(int));
//             sequence[size] = buff_int;
//             size++;
//             if (buff_char == '\n') {
//                 flag = 2;
//             }
//         }
//     }
//     if (flag == 2) {
//         flag = 0;
//         Qsort(sequence, size);
//         PrintSequence(sequence, size);
//     }
//     exit(flag);
// }