#ifndef PARENT_H
#define PARENT_H

// #include <signal.h>
// #include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define CHILD_PROCESS_PID 0
#define FLAG_IS_ERROR 1
#define FLAG_IS_NORMAL 0
#define SIZE_OF_SEQUENCE 500

enum { P_READ, P_WRITE }; // Pipe read/write

static void ChildFunc();


// Not actual:

// typedef struct Child {
    // FILE *fp_to;
    // FILE *fp_from;
    // pid_t pid;
// } Child; // Child structure


#endif