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
int (*get_builtin(char *cmd))(data_shell *);
void bring_line(char **lineptr, size_t *n, char *buffer, size_t j);
int cd_shell(data_shell *datash);


#endif
