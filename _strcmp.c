#include "main.h"

int _strcmp(char *a, char *b)
{
    int i = 0;

    if (a == NULL || b == NULL)
	    return (1);

    for (i = 0; a[i]; i++)
    {
        if (a[i] != b[i])
        {
            return (1);
        }
    }
    return (0);
}
