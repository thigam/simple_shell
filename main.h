#ifndef MAIN
#define MAIN

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>

#define BUFSIZE 1024


/**
 * struct data - struct that contains all relevant data on runtime
 * @av: argument vector
 * @input: command line written by the user
 * @args: tokens of the command line
 * @status: last status of the shell
 * @counter: lines counter
 * @_environ: environment variable
 * @pid: process ID of the shell
 */
typedef struct data
{
	char **av;
	char *input;
	char **args;
	int status;
	int counter;
	char **_environ;
	char *pid;
} data_shell;

typedef struct builtin_s
{
	char *name;
	int (*f)(data_shell *datash);
} builtin_t;

typedef int (*funcptr)(char *);

typedef struct functions {
    char *func_name;
    funcptr func;
} functions_t;

void path_handler(char *input);
int switcher(char *command);
int exit_shell (char *);
<<<<<<< HEAD
int (*get_builtin(char *cmd))(data_shell *);
void bring_line(char **lineptr, size_t *n, char *buffer, size_t j);
int cd_shell(data_shell *datash);
/*env.c*/
int cmp_env_name(const char *nenv, const char *name);
char *_getenv(const char *name, char **_environ);
int _env(data_shell *datash);
/*shell_env.c*/
char *copy_info(char *name, char *value);
void set_env(char *name, char *value, data_shell *datash);
int _setenv(data_shell *datash);
int _unsetenv(data_shell *datash);
int exit_shell(data_shell *datash);


#endif
