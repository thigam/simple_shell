#include "main.h"

int exit_shell (char *command)
{
        if (command != NULL)
        {
                exit (0);
        }
        return (1);
}
