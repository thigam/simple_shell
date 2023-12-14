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

        if (ac == 0 && av == NULL) 
                write(1, "Chill", 5); 

    while (1)
    {
        write(1, "#cisfun$ ", 9);

        input = malloc(100);

        if (input == NULL)
            write(1, "malloc fails for input", 22); 

        if (getline(&input, &length, stdin) == -1)
            perror("Error:");

        if (input[_strlen(input) - 1] == '\n') 
            input[_strlen(input) - 1] = '\0'; 

        path_handler(input);

        word = strtok(input, " ");

        i = 0;

        argv = malloc(sizeof(char *) * 20); 
        if (argv == NULL)
        {
            write(1, "malloc fails for argv", 21); 
            exit(1);
        }

        i = 0;

        while (word != NULL)
        {
            argv[i] = malloc(strlen(word) + 1);
            if (argv[i] == NULL)
                write(1, "Didn't allocate space in array", 30);

            _strcpy(argv[i], word);
            i++;
            word = strtok(NULL, " ");
        }

        argv[i] = NULL;

        if (stat(argv[0], &st) == 0)
        {
            if (child_pid == -1)
            {
                perror("Error");
                return (1);
            }

            if (child_pid != 0)
                child_pid = fork();

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
            {
                if (input != NULL)
                    free(input); 
                if (argv != NULL)
                {
                    for (i = 0; argv[i] != NULL; i++)
                    {
                        free(argv[i]);
                    }
                    free(argv);
                } 
                return (0);
            }
        else
        {
            write(1, "./shell: No such file or directory\n", 35);

        }

        if (input != NULL)
            free(input);
        if (argv != NULL)
        {
            for (i = 0; argv[i] != NULL; i++)
            {
                free(argv[i]);
            }
            free(argv);
        } 

    }

    return 0;
}
