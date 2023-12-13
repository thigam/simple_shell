#ifndef MAIN
#define MAIN

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

typedef int (*funcptr)(char *);

typedef struct functions {
    char *func_name;
    funcptr func;
} functions_t;

void path_handler(char *input);
int switcher(char *command);
int exit_shell (char *);

#endif
