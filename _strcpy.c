#include "main.h"

void _strcpy(char *dest, char *source)
{
    int i = 0;

    for (i = 0; source[i]; i++)
    {
        dest[i] = source[i];
    }
    dest[i] = '\0';
}
