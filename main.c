#include "main.h"


int main(int ac, char **av, char **env)
{
    char *input = NULL;
    struct stat st;
    pid_t child_pid;
    int status;
    size_t length = 0;
    int i = 0;
    char *word;
    char **argv = NULL;



    while (1)
    {
        printf("#cisfun$ ");

        if (input != NULL)
            free(input);
        input = malloc(100);

        if (input == NULL)
            printf("#cisfun$ ");

        if (getline(&input, &length, stdin) == -1)
            perror("Error:");

        if (input[strlen(input) - 1] == '\n')
            input[strlen(input) - 1] = '\0';

        path_handler(input);

        word = strtok(input, " ");

        i = 0;

        if (argv != NULL)
        {
            for (i = 0; argv[i] != NULL; i++)
            {
                free(argv[i]);
            }
            free(argv);
        }

        argv = malloc(sizeof(char *) * strlen(input) + 1);
        if (argv == NULL)
        {
            printf("malloc fails");
            exit(1);
        }

        i = 0;

        while (word != NULL)
        {
            argv[i] = malloc(strlen(word) + 1);
            if (argv[i] == NULL)
                printf("Didn't allocate space in array");

            strcpy(argv[i], word);
            i++;
            word = strtok(NULL, " ");
        }

        argv[i] = NULL;

        if (stat(argv[0], &st) == 0)
        {
            child_pid = fork();

            if (child_pid == -1)
            {
                perror("Error");
                return (1);
            }

            if (child_pid == 0)
            {
                if (execve(argv[0], argv, env) == -1)
                    perror("Error:");
            }
            else
            {
                if (wait(&status) == -1)
                    perror("Wait failed:");
            }
        }
        else if (switcher(argv[0]) == 1)
            return (0);
        else
        {
            printf("./shell: No such file or directory\n");

        }

    }

    return 0;
}
