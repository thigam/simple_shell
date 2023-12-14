#include "main.h"

void _strcat(char *dest, char *source)
{
    int i = 0, j = 0;

    while (dest[i])
    {
        i++;
    }

    for (j = 0; source[j]; j++)
    {
        dest[i++] = source[j];
    }
    dest[i] = '\0';
}
