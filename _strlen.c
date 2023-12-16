#include "main.h"

int _strlen(char *a)
{
    int i = 0;

    while (a[i])
    {
        i++;
    }

    return (i);
}
