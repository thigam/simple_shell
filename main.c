#include "main.h"

/**
 * free_data - frees data structure
 *
 * @datash: data structure
 * Return: no return
 */
void free_data(data_shell *datash)
{
	unsigned int i;

	for (i = 0; datash->_environ[i]; i++)
	{
		free(datash->_environ[i]);
	}

	free(datash->_environ);
	free(datash->pid);
}

/**
 * set_data - Initialize data structure
 *
 * @datash: data structure
 * @av: argument vector
 * Return: no return
 */
void set_data(data_shell *datash, char **av)
{
	unsigned int i;

	datash->av = av;
	datash->input = NULL;
	datash->args = NULL;
	datash->status = 0;
	datash->counter = 1;

	for (i = 0; environ[i]; i++)
		;

	datash->_environ = malloc(sizeof(char *) * (i + 1));

	for (i = 0; environ[i]; i++)
	{
		datash->_environ[i] = _strdup(environ[i]);
	}

	datash->_environ[i] = NULL;
	datash->pid = aux_itoa(getpid());
}

/**
 * main - Entry point
 *
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success.
 */
int main(int ac, char **av)
{
	data_shell datash;
	(void) ac;

	signal(SIGINT, get_sigint);
	set_data(&datash, av);
	shell_loop(&datash);
	free_data(&datash);
	if (datash.status < 0)
		return (255);
	return (datash.status);
}

/*
int main(int ac, char **av, char **env)
{
    char *input = NULL;
    struct stat st;
    pid_t child_pid = 5;
    int status = 0;
    size_t length = 0;
    int i = 0;
    char *word;
    char **argv = NULL;

        if (ac == 0 && av == NULL)
                write(1, "Chill", 5);

    while (1)
    {
        write(1, "#cisfun$ ", 9);

        if (getline(&input, &length, stdin) == -1)
           {
                   break;
           }

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
            {
                write(1, "Didn't allocate space in array", 30);
                free_array(argv);
                return (1);
            }

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
                free_array(argv);
                return (0);
            }
        else
        {
            write(1, "./shell: No such file or directory\n", 35);
        }

        free_array(argv);

    }

    return 0;
}*/
