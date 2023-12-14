#include "main.h"

int switcher(char *command)
{
    int i = 0;

    functions_t funcs[] = {
        {"/bin/exit", exit_shell}
    };

    for (i = 0; funcs[i].func_name; i++)
    {
        if (_strcmp(funcs[i].func_name, command) == 0)
        {
            return (funcs[i].func(command));
            break;
        }
    }

    return (0);
}
